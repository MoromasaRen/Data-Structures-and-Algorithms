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
} VHeap;

typedef int List;

//Function Prototypes
void initialize(VHeap *V);
int allocSpace(VHeap* V);
void deallocSpace(VHeap* V, int index);
void insertFirst(int* L, VHeap* V, int elem);
void insertLast(int* L, VHeap* V, int elem);
void insertSorted(int* L, VHeap* V, int elem);
void delete(int* L, VHeap* V, int elem);
void deleteAllOccurrence(int* L, VHeap* V, int elem);
void display(int L, VHeap V);

int main (){

    VHeap* V;
    initialize(V);

    return 0;
}

// Functions
void initialize(VHeap *V){
    int i;
    V->avail = 0;
    for(i = V->avail; i < MAX - 1; i++){
        V->H[i].next = i + 1;
    }
    V->H[i].next = -1;
}

int allocSpace(VHeap* V){
    int ret = V->avail;
    if(ret != -1){
        V->avail = V->H[ret].next;
    }
    return ret;
}

void deallocSpace(VHeap* V, int index){
    if(index < MAX - 1 &&  index >= 0){
        V->H[index].next = V->avail;
        V->avail = index;
    }
}

void insertFirst(int* L, VHeap* V, int elem){
    int newCell = allocSpace(&V);
    if(newCell != -1){
        V->H[newCell].elem = elem;
        V->H[newCell].next = *L;
    }
    *L = newCell;
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

void delete(int* L, VHeap* V, int elem){
    int *trav, temp;
    trav = L;

    for(int i = 0; *trav != -1 && V->H[*trav].elem != elem; i++){
        trav = V->H[*trav].next;
    }
    if(*trav != -1){
        temp = *trav;
        *trav = V->H[temp].next;
        deallocSpace(V, temp);
    }
}

void deleteAllOccurrence(int* L, VHeap* V, int elem){

}

void display(int L, VHeap V){
    
}