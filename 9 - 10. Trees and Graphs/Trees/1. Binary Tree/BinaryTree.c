#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// Define the structure of a tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node, *NodePTR;

typedef NodePTR Tree[MAX];


