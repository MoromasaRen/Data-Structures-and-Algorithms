#include <stdio.h>
#include <stdlib.h>
#define MAX 4

typedef struct {
    int elem;
    int next;
} Cell, HeapSpace[MAX];

typedef struct {
    HeapSpace H;
    int avail;
}; VHeap;

typedef int List;

void initialize(Vheap *V);
int allocSpace(VHeap* V);
void deallocSpace(VHeap* V, int index);
void insertFirst(int* L, VHeap* V, int elem);
void insertLast(int* L, VHeap* V, int elem);
void insertSorted(int* L, VHeap* V, int elem);
void delete(int* L, VHeap* V, int elem);
void deleteAllOccurrence(int* L, VHeap* V, int elem);
void display(int L, VHeap V);

int main (){

    VHeap* V = initialize(V);

    return 0;
}


void initialize(Vheap *V){
    
}

int allocSpace(VHeap* V){

}

void deallocSpace(VHeap* V, int index){

}

void insertFirst(int* L, VHeap* V, int elem){

}

void insertLast(int* L, VHeap* V, int elem){
    int newCell = allocSpace(&V);
    if(newCell != -1){
        V->H[newCell].elem = elem;
        V->H[newCell].next = -1;
        int *trav = L;
        while(*trav != -1){
            trav = &V->H[newCell].next;
        }
        *trav = newCell;
    }
}

void insertSorted(int* L, VHeap* V, int elem){

}

void delete(int* L, VHeap* V, int elem);
void deleteAllOccurrence(int* L, VHeap* V, int elem);
void display(int L, VHeap V);

