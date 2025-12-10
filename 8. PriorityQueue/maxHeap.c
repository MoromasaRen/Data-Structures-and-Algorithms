#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int elem[MAX];
    int size;
} MaxHeap;

void initialize(MaxHeap* M);
void insert(MaxHeap* M, int value);
int deleteMax(MaxHeap* M);
void heapifyUp(MaxHeap* M, int index);
void heapifyDown(MaxHeap* M, int index);
void makeNull(MaxHeap* M);
void printHeap(MaxHeap M);

int main (){
    MaxHeap M;
    initialize(&M);

    insert(&M, 50);
    insert(&M, 20);
    insert(&M, 30);
    insert(&M, 10);
    insert(&M, 40);

    printHeap(M);

    printf("Extracted Max: %d\n", deleteMax(&M));
    printHeap(M);

    return 0;
}

void initialize(MaxHeap *M){
    for(int i = 0; i < MAX; i++){
        M->elem[i] = -1;
    }
    M->size = 0;
}

void insert(MaxHeap* M, int value){
    if(M->size >= MAX) return;

    M->elem[M->size] = value;
    heapifyUp(M, M->size);
    M->size++;
}

int deleteMax(MaxHeap* M){
    if(M->size <= 0) return -1;

    int max = M->elem[0];
    M->elem[0] = M->elem[M->size - 1];
    M->size--;

    heapifyDown(M, 0);
    return max;
}

void heapifyUp(MaxHeap* M, int index){
    int parent = (index - 1) / 2;
    
    while(index > 0 && M->elem[index] > M->elem[parent]){
        int temp = M->elem[index];
        M->elem[index] = M->elem[parent];
        M->elem[parent] = temp;

        index = parent;
        parent = (index - 1) / 2;
    }
}

void heapifyDown(MaxHeap* M, int index){
    int largest = index;
    int left = (index * 2) + 1;
    int right = (index * 2) + 2;

    if(left < M->size && M->elem[left] > M->elem[largest])
        largest = left;
    if(right < M->size && M->elem[right] > M->elem[largest])
        largest = right;
    
    if(largest != index){
        int temp = M->elem[index];
        M->elem[index] = M->elem[largest];
        M->elem[largest] = temp;

        heapifyDown(M, largest);
    }
}

void makeNull(MaxHeap* M){
    for (int i = 0; i < MAX; i++) {
        M->elem[i] = -1;
    }
    M->size = 0;
}

void printHeap(MaxHeap M){
    printf("Heap: ");
    for (int i = 0; i < M.size; i++) {
        printf("%d ", M.elem[i]);
    }
    printf("\n");
}