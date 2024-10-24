#include "header.h"
//Ashutosh Rajput
//2023CSB1289
#include <stdio.h>
#include <stdlib.h>
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



int main()
{
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

    depth_traverse(root);
    
    return 0;
}
