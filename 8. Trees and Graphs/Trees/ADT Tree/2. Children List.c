#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node {
    int data;
    struct node* next;
} Node, *NodePTR;

typedef NodePTR Tree[MAX];

void initTree(Tree T);
NodePTR createNode(int data);
void insertTree(Tree T, int data);
void deleteTree(Tree T, int data);
void searchTree(Tree T, int data);
void Preorder(Tree T);
void Inorder(Tree T);
void Postorder(Tree T);
void BFS(Tree T);

