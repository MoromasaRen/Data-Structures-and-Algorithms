#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* leftChild;
    struct Node* rightChild;
} Node, *BST;

void insert(BST* T, int value);
void deleteLeaf(BST* T, int value);     
void deleteNode(BST* T, int value);  
bool isMember(BST T, int value);
int findMin(BST T);
int findMax(BST T);
void display(BST T);

int main() {
    BST T = NULL;

    insert(&T, 50);
    insert(&T, 20);
    insert(&T, 80);
    insert(&T, 10);
    insert(&T, 30);
    insert(&T, 70);
    insert(&T, 90);

    printf("Before delete:\n");
    display(T);

    printf("\nDeleteLeaf(30):\n");
    deleteLeaf(&T, 30);
    display(T);

    printf("\nFull deleteNode(20):\n");
    deleteNode(&T, 20);
    display(T);

    printf("\nisMember(70) = %s\n", isMember(T, 70) ? "true" : "false");
    printf("Min = %d\n", findMin(T));
    printf("Max = %d\n", findMax(T));

    return 0;
}

void insert(BST* T, int value){
    BST* trav = T;

    while(*trav != NULL && (*trav)->data != value){
        if((*trav)->data > value){
            trav = &(*trav)->leftChild;
        } else {
            trav = &(*trav)->rightChild;
        }
    }

    if(*trav == NULL){
        *trav = (BST)calloc(1, sizeof(Node));
        if (*trav != NULL) {
            (*trav)->data = value;
            (*trav)->leftChild = NULL;
            (*trav)->rightChild = NULL;
        }
    }
}

void deleteLeaf(BST* T, int value){
    BST* trav = T;

    while(*trav != NULL && (*trav)->data != value){
        if((*trav)->data > value){
            trav = &(*trav)->leftChild;
        } else {
            trav = &(*trav)->rightChild;
        }
    }

    if(*trav == NULL) return;

    if((*trav)->leftChild == NULL && (*trav)->rightChild == NULL){
        free(*trav);
        *trav = NULL;
    }
}

void deleteNode(BST* T, int value){
    BST* trav = T;

    while(*trav != NULL && (*trav)->data != value){
        if((*trav)->data > value){
            trav = &(*trav)->leftChild;
        } else {
            trav = &(*trav)->rightChild;
        }
    }

    if(*trav == NULL) return;

    Node *target = *trav;

    if(target->leftChild == NULL && target->rightChild == NULL){
        free(target);
        *trav = NULL;
        return;
    }

    if(target->leftChild == NULL && target->rightChild != NULL){
        *trav = target->rightChild;
        free(target);
        return;
    }

    if(target->leftChild != NULL && target->rightChild == NULL){
        *trav = target->leftChild;
        free(target);
        return;
    }

    BST* succ = &target->rightChild;
    while((*succ)->leftChild != NULL){
        succ = &(*succ)->leftChild;
    }

    target->data = (*succ)->data;

    Node *toDelete = *succ;
    *succ = toDelete->rightChild;
    free(toDelete);
}

bool isMember(BST T, int value){
    while(T != NULL){
        if(T->data == value) return true;
        T = (value < T->data) ? T->leftChild : T->rightChild;
    }
    return false;
}

int findMin(BST T){
    if(T == NULL) return -1;
    while(T->leftChild != NULL){
        T = T->leftChild;
    }
    return T->data;
}

int findMax(BST T){
    if(T == NULL) return -1;
    while(T->rightChild != NULL){
        T = T->rightChild;
    }
    return T->data;
}

void display(BST T){
    if(T != NULL){
        printf("Node: %d ", T->data);

        if (T->leftChild)
            printf("Left = %d, ", T->leftChild->data);
        else
            printf("Left = 0, ");

        if (T->rightChild)
            printf("Right = %d\n", T->rightChild->data);
        else
            printf("Right = 0\n");

        display(T->leftChild);
        display(T->rightChild);
    }
}
