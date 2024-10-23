#include "header.h"
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

//function to calculate the levenshtein distance between two strings
int levenshteinDistance(const char *word1, const char *word2)
{
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int dp[len1 + 1][len2 + 1];
    for(int i = 0; i <= len1; i++)
    {
        for(int j = 0; j <= len2; j++)
        {
            if(i == 0)
            {
                dp[i][j] = j;
            }
            else if(j == 0)
            {
                dp[i][j] = i;
            }
            else if(word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }
    return dp[len1][len2];
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

int main()
{
}