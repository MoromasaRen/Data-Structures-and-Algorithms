#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int elem[MAX];
    int size;
} MinHeap;

void initialize(MinHeap* M);
void insert(MinHeap* M, int value);
int deleteMin(MinHeap* M);
void heapifyUp(MinHeap* M, int index);
void heapifyDown(MinHeap* M, int index);
void makeNull(MinHeap* M);
void printHeap(MinHeap M);

int main() {
    MinHeap M;
    initialize(&M);

    insert(&M, 50);
    insert(&M, 20);
    insert(&M, 30);
    insert(&M, 10);
    insert(&M, 40);

    printHeap(M);

    printf("Extracted Min: %d\n", deleteMin(&M));
    printHeap(M);

    return 0;
}

void initialize(MinHeap* M){
    for(int i = 0; i < MAX; i++){
        M->elem[i] = -1;
    }
    M->size = 0;
}

void insert(MinHeap* M, int value){
    if(M->size >= MAX) return;

    M->elem[M->size] = value;
    heapifyUp(M, M->size);
    M->size++; 
}

int deleteMin(MinHeap* M){
    if(M->size <= 0) return -1;

    int min = M->elem[0];
    M->elem[0] = M->elem[M->size - 1];
    M->size--;
    heapifyDown(M, 0);

    return min;
}

void heapifyUp(MinHeap* M, int index){
    int parent = (index - 1) / 2;

    while(index > 0 && M->elem[index] < M->elem[parent]){
        int temp = M->elem[index];
        M->elem[index] = M->elem[parent];
        M->elem[parent] = temp;

        index = parent;
        parent = (index - 1) / 2;
    }
}

void heapifyDown(MinHeap* M, int index){
    int smallest = index;
    int left = (index * 2) + 1;
    int right = (index * 2) + 2;

    if(left < M->size && M->elem[left] < M->elem[smallest])
        smallest = left;
    if(right < M->size && M->elem[right] < M->elem[smallest])
        smallest = right;

    if(smallest != index){
        int temp = M->elem[index];
        M->elem[index] = M->elem[smallest];
        M->elem[smallest] = temp;

        heapifyDown(M, smallest);
    }
}

void makeNull(MinHeap* M){
    for(int i = 0; i < MAX; i++){
        M->elem[i] = -1;
    }
    M->size = 0;
}

void printHeap(MinHeap M){
    printf("Heap: ");
    for(int i = 0; i < M.size; i++){
        printf("%d ", M.elem[i]);
    }
    printf("\n");
}