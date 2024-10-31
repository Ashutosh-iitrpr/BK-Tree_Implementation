//Ashutosh Rajput
//2023CSB1289
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <time.h>

#define M_PI 3.14159265358979323846

struct Node
{
    float longitude;
    float latitude;
    char *name;
    struct Node **children;
    int numChildren;
};

//function to create a new node
struct Node* createNode(float longitude, float latitude, char *name)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->longitude = longitude;
    newNode->latitude = latitude;
    newNode->name = strdup(name);
    newNode->numChildren = 23;
    newNode->children = (struct Node**)malloc(sizeof(struct Node*) * newNode->numChildren);
    for(int i = 0; i < newNode->numChildren; i++)
    {
        newNode->children[i] = NULL;
    }
    return newNode;
}

//function to create a BK tree
struct Node* createBKTree(float longitude, float latitude, char *name)
{
    struct Node *root = createNode(longitude, latitude, name);
    return root;
}

 

//function to calculate haversine distance
int heversine_distance(float lon1, float lat1, float lon2, float lat2)
{
    float dLat = (lat2 - lat1) * M_PI / 180.0;
    float dLon = (lon2 - lon1) * M_PI / 180.0;
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;
    float a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    float rad = 6371;
    float c = 2 * asin(sqrt(a));
    return rad * c;
}

//function to insert a new node in BK tree
void insertNode(struct Node *root, float longitude, float latitude, char *name)
{
    struct Node *currentNode = root;
    int distance = 0;
    while(currentNode != NULL)
    {
        distance = heversine_distance(currentNode->longitude, currentNode->latitude, longitude, latitude);
        if(currentNode->children[distance/15] == NULL)
        {
            currentNode->children[distance/15] = createNode(longitude, latitude, name);
            break;
        }
        else
        {
            currentNode = currentNode->children[distance/15];
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
    printf("%s\n", root->name);
}

int main()
{
    

}

