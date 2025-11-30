#include <stdio.h>
#include <stdlib.h>

// ==== NODE STRUCTURE ====
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node, *NodePTR;

// Treat the Tree as a pointer to NodePTR
typedef NodePTR Tree;

// ==== FUNCTION PROTOTYPES ====
void initializeTree(Tree* T);
NodePTR createNode(int data);
void insertTree(Tree* T, int data);
NodePTR deleteNode(NodePTR root, int data);
void deleteTree(Tree* T, int data);
NodePTR search(Tree T, int data);
void Preorder(Tree T);
void Inorder(Tree T);
void Postorder(Tree T);
void BFS(Tree T);

int main (){
    Tree T;
    initializeTree(&T);

}

void initializeTree(Tree* T){
    (*T) = NULL;
}

NodePTR createNode(int data){
    NodePTR newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertTree(Tree* T, int data){
    if(*T == NULL){
        *T = createNode(data);
        return;
    }
    if(data < (*T)->data)
        insertTree(&(*T)->left, data);
    else if (data > (*T)->data)
        insertTree(&(*T)->right, data);
}

NodePTR deleteNode(NodePTR root, int data);
void deleteTree(Tree* T, int data);

NodePTR search(Tree T, int data){
    if(T == NULL || T->data == data){
        return T;
    }
    if(data < T->data)
        return search(T->left, data);
    else
        return search(T->right, data);
}

void Preorder(Tree T){
    if(T == NULL) return;
    printf("%d ", T->data);
    Preorder(T->left);
    Preorder(T->right);
}

void Inorder(Tree T){
    if(T == NULL) return;
    Preorder(T->left);
    printf("%d ", T->data);
    Preorder(T->right);
}

void Postorder(Tree T){
    if(T == NULL) return;
    Preorder(T->left);
    Preorder(T->right);
    printf("%d ", T->data);
}

void BFS(Tree T){
    if(T == NULL) return;

    Queue q;
    initQueue(&q);
    enqueue(&q, T);

    while(!isEmpty(&q)){
        NodePTR current = dequeue(&q);
        printf("%d ", current->data);

        if(current->left) enqueue()
    }
}