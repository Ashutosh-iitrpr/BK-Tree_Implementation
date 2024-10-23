//Ashutosh Rajput
//2023CSB1289
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
struct Node* createNode(const char *word)
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
struct Node* createBKTree(const char *word)
{
    struct Node *root = createNode(word);
    return root;
}

//function to insert a new node in BK tree
void insertNode(struct Node *root, const char *word)
{
    struct Node *currentNode = root;
    int distance = 0;
    while(currentNode != NULL)
    {
        distance = levenshteinDistance(currentNode->word, word);
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

