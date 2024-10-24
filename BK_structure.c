#include "header.h"
//Ashutosh Rajput
//2023CSB1289
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <time.h>

//As of now we are restricting the child nodes to 15

//creating structure of node in BK Tree
struct Node
{
    int length;
    char *word;
    struct Node **children;
    int numChildren;
};

//function to create a new node
struct Node* createNode(char *word)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->length = strlen(word);
    newNode->word = strdup(word);
    newNode->numChildren = 15;
    newNode->children = (struct Node**)malloc(sizeof(struct Node*) * newNode->numChildren);
    for(int i = 0; i < newNode->numChildren; i++)
    {
        newNode->children[i] = NULL;
    }
    return newNode;
}

//function to create a BK tree
struct Node* createBKTree(char *word)
{
    struct Node *root = createNode(word);
    return root;
}



//function to insert a new node in BK tree
void insertNode(struct Node *root,  char *word)
{
    struct Node *currentNode = root;
    int distance = 0;
    while(currentNode != NULL)
    {
        distance = lev_dist(currentNode->word, word);
        if(currentNode->children[distance] == NULL)
        {
            currentNode->children[distance] = createNode(word);
            break;
        }
        else
        {
            currentNode = currentNode->children[distance];
        }
    }
}

void depth_traverse(struct Node *root)
{
    if(root == NULL)
    {
        return;
    }
    for(int i = 0; i < root->numChildren; i++)
    {
        depth_traverse(root->children[i]);
    }
    printf("%s\n", root->word);
}

//function for searching a word in BK tree
void searchBKTree(struct Node *root, char *word, int tolerance, char ***results, int *result_count) {
    if (root == NULL) return;

    int distance = lev_dist(root->word, word);
    if (distance <= tolerance) {
        int index = distance;  // Index based on Levenshtein distance
        if (result_count[index] < 15) {  // Assuming max 15 results per distance
            results[index][result_count[index]] = root->word;
            result_count[index]++;
        }
    }

    // Search in the range of distance - tolerance to distance + tolerance subtrees
    for (int i = fmax(0, distance - tolerance); i <= distance + tolerance && i < root->numChildren; i++) {
        searchBKTree(root->children[i], word, tolerance, results, result_count);
    }
}

void search_preprocessor(struct Node *root) {
    char word[100];
    int tolerance;
    char **results[15];  // Array of 15 arrays for different distances
    int result_count[15] = {0};

    printf("Enter the word to search: ");
    scanf("%s", word);

    printf("Enter the tolerance: ");
    scanf("%d", &tolerance);

    for (int i = 0; i < 15; i++) {
        results[i] = (char **)malloc(15 * sizeof(char *));
    }

    searchBKTree(root, word, tolerance, results, result_count);

    // Return the first non-empty array of results
    for (int i = 0; i < 15; i++) {
        if (result_count[i] > 0) {
            printf("Words within distance %d of '%s':\n", i, word);
            for (int j = 0; j < result_count[i]; j++) {
                printf("  %s\n", results[i][j]);
            }
            // Free memory after use
            for (int k = 0; k < 15; k++) {
                free(results[k]);
            }
            return;
        }
    }

    printf("No words found within the given tolerance.\n");
    // Free memory even if no results are found
    for (int k = 0; k < 15; k++) {
        free(results[k]);
    }
}







int main() {
    struct Node *root = createBKTree("hello");
    insertNode(root, "world");
    insertNode(root, "hell");
    insertNode(root, "help");
    insertNode(root, "jello");
    insertNode(root, "jelly");
    insertNode(root, "jellybean");
    insertNode(root, "jellybeans");
    insertNode(root, "jellyfish");
    insertNode(root, "jellyfishes");
    insertNode(root, "jellyfisher");
    insertNode(root, "holla");
    insertNode(root, "hella");

    depth_traverse(root);

    search_preprocessor(root);
    
}
