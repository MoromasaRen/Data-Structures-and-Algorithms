#include <stdio.h>
#include <stdlib.h>
#define ROOT -1
#define DNE -2
#define MAX 10

typedef struct {
    int data;
    int parent;
} Node;

typedef Node Tree[MAX];

// Operations
int Parent(Tree T, int index);
int Left_Child(Tree T, int index);
int Right_Sibling(Tree T, int index);
int Label(Tree T, int index);
int createNode(Tree T, int data, int parentIndex);
int root(Tree T);
void initialize(Tree T);
void makeNull(Tree T);
void display(Tree T);

int main () {
    Tree T;
    initialize(T);

    int r = createNode(T, 10, ROOT);
    int a = createNode(T, 30, 0);
    int b = createNode(T, 24, 0);

    display(T);
    printf("Parent of index %d is %d\n", b, Parent(T, b));
    printf("Left child of root = %d\n", Left_Child(T, r));
    printf("Right sibling of Index %d is Index %d\n", a, Right_Sibling(T, a));
    
    return 0;
}

int Parent(Tree T, int index){
    return T[index].parent;
}

int Left_Child(Tree T, int index){
    for(int i = 0; i < MAX; i++){
        if(T[i].parent == index){
            return i;
        }
    }
    return DNE;
}

int Right_Sibling(Tree T, int index){
    int p = T[index].parent;
    for(int i = index + 1; i < MAX; i++){
        if(T[i].parent == p){
            return i;
        }
    }
    return DNE;
}

int Label(Tree T, int index){
    if (index < 0 || index >= MAX) return DNE;
    return T[index].data;
}

int createNode(Tree T, int data, int parentIndex){
    
    for(int i = 0; i < MAX; i++){
        if(T[i].data == DNE){
            T[i].data = data;
            T[i].parent = parentIndex;
            return i;
        }
    }
    return DNE;
}

int root(Tree T){
    for(int i = 0; i < MAX; i++){
        if(T[i].parent == ROOT){
            return i;
        }
    }
    return DNE;
}

void initialize(Tree T){
    for(int i = 0; i < MAX; i++){
        T[i].data = DNE;
        T[i].parent = DNE;
    }
}

void makeNull(Tree T){
    for(int i = 0; i < MAX; i++){
        T[i].data = DNE;
        T[i].parent = DNE;
    }
}

void display(Tree T){  
    printf("Index Data Parent\n");
    for(int i = 0; i < MAX; i++){
        printf("%3d | %3d | %3d\n", i, T[i].data, T[i].parent);
    }
}