#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define ROOT -1
#define DNE -2

typedef struct node {
    int child;
    struct node* next;
} Node, *NodePTR;

typedef struct {
    int root;
    NodePTR childNode[MAX];
} Tree;

// Operations
int Parent(Tree* T, int index);
int Left_Child(Tree* T, int index);
int Right_Sibling(Tree* T, int index);
int Label(int index);
void createNode(Tree* T, int parentIndex, int childIndex);
int root(Tree* T);
void initialize(Tree* T);
void makeNull(Tree* T);
void display(Tree* T);

int main (){

    Tree T;
    initialize(&T);

    T.root = 0;

    createNode(&T, 0, 1);
    createNode(&T, 0, 2);
    createNode(&T, 1, 3);
    createNode(&T, 1, 4);
    createNode(&T, 2, 5);
    display(&T);
    
    printf("Root: %d\n", T.root);
    printf("Parent of 4 = %d\n", Parent(&T, 5));
    printf("Left child of 2 = %d\n", Left_Child(&T, 2));
    printf("Right sibling of 3 = %d\n", Right_Sibling(&T, 4));

    return 0;
}

int Parent(Tree* T, int index){;
    for(int i = 0; i < MAX; i++){
        NodePTR current = T->childNode[i];
        while(current != NULL){
            if(current->child == index){
                return i;
            }
            current = current->next;
        }
    }
    return ROOT;
}

int Left_Child(Tree* T, int index){
    if(T->childNode[index] == NULL){
        return DNE;
    }
    return T->childNode[index]->child;
}

int Right_Sibling(Tree* T, int index){
    int parent = Parent(T, index);
    if(parent == ROOT){
        return DNE;
    }
    NodePTR current = T->childNode[parent];
    while(current != NULL){
        if(current->child == index){
            if(current->next != NULL){
                return current->next->child;
            } else {
                return DNE;
            }
        }
        current = current->next;
    }
    return DNE;
}

int Label(int index){
    return index;
}

void createNode(Tree* T, int parentIndex, int childIndex){
    NodePTR newNode = malloc(sizeof(Node));
    newNode->child = childIndex;
    newNode->next = NULL;

    newNode->next = T->childNode[parentIndex];
    T->childNode[parentIndex] = newNode;
}

int root(Tree* T){
    return T->root;
}

void initialize(Tree* T){
    T->root = DNE;
    for(int i = 0; i < MAX; i++){
        T->childNode[i] = NULL;
    }
}

void makeNull(Tree* T){
    initialize(T);
}

void display(Tree* T){
    printf("Parent: Children List\n");
    for(int i = 0; i < MAX; i++){
        printf(" | %d |: ", i);
        NodePTR current = T->childNode[i];
        while(current != NULL){
            printf("%d -> ", current->child);
            current = current->next;
        }
        printf("NULL\n");
    }
}
