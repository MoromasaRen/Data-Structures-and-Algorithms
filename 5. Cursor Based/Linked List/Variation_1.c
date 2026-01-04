#include <stdio.h>
#include <stdlib.h>
#define MAX 4
#define NIL -1

typedef struct {
    int elem;
    int next;
} Cell, HeapSpace[MAX];

typedef struct {
    HeapSpace H;
    int avail;
} VHeap;

typedef int List;

// Function Prototypes
void initialize(VHeap *V);
int  allocSpace(VHeap *V);
void deallocSpace(VHeap *V, int index);
void insertFirst(List *L, VHeap *V, int elem);
void insertLast(List *L, VHeap *V, int elem);
void insertSorted(List *L, VHeap *V, int elem);
void deleteElem(List *L, VHeap *V, int elem);
void deleteAllOccurrence(List *L, VHeap *V, int elem);
void display(List L, VHeap V);

int main(void) {
    VHeap V;
    List L = NIL;

    initialize(&V);

    insertFirst(&L, &V, 30);
    insertFirst(&L, &V, 10);
    insertLast(&L, &V, 50);
    insertSorted(&L, &V, 20);

    display(L, V); // expected: 10 20 30 50

    deleteElem(&L, &V, 20);
    display(L, V); // expected: 10 30 50

    deleteAllOccurrence(&L, &V, 10);
    display(L, V); // expected: 30 50

    return 0;
}

void initialize(VHeap *V) {
    // Build the free list: 0 -> 1 -> 2 -> ... -> MAX-1 -> NIL
    V->avail = 0;
    for (int i = 0; i < MAX - 1; i++) {
        V->H[i].next = i + 1;
    }
    V->H[MAX - 1].next = NIL;
}

int allocSpace(VHeap *V) {
    // Pop from free list
    int idx = V->avail;
    if (idx != NIL) {
        V->avail = V->H[idx].next;
    }
    return idx;
}

void deallocSpace(VHeap *V, int index) {
    // Push back into free list
    if (index >= 0 && index < MAX) {
        V->H[index].next = V->avail;
        V->avail = index;
    }
}

//  Insert Operations 

void insertFirst(List *L, VHeap *V, int elem) {
    int newCell = allocSpace(V);
    if (newCell != NIL) {
        V->H[newCell].elem = elem;
        V->H[newCell].next = *L;
        *L = newCell;
    }
}

void insertLast(List *L, VHeap *V, int elem) {
    int newCell = allocSpace(V);
    if (newCell != NIL) {
        V->H[newCell].elem = elem;
        V->H[newCell].next = NIL;

        // pointer-to-cursor traversal
        int *trav = L;
        while (*trav != NIL) {
            trav = &V->H[*trav].next;
        }
        *trav = newCell;
    }
}

void insertSorted(List *L, VHeap *V, int elem) {
    int newCell = allocSpace(V);
    if (newCell != NIL) {
        V->H[newCell].elem = elem;

        int *trav = L;
        while (*trav != NIL && V->H[*trav].elem < elem) {
            trav = &V->H[*trav].next;
        }

        V->H[newCell].next = *trav;
        *trav = newCell;
    }
}

//  Delete Operations 

void deleteElem(List *L, VHeap *V, int elem) {
    int *trav = L;

    while (*trav != NIL && V->H[*trav].elem != elem) {
        trav = &V->H[*trav].next;
    }

    if (*trav != NIL) {
        int temp = *trav;
        *trav = V->H[temp].next;
        deallocSpace(V, temp);
    }
}

void deleteAllOccurrence(List *L, VHeap *V, int elem) {
    int *trav = L;

    while (*trav != NIL) {
        if (V->H[*trav].elem == elem) {
            int temp = *trav;
            *trav = V->H[temp].next;
            deallocSpace(V, temp);
        } else {
            trav = &V->H[*trav].next;
        }
    }
} 

int isEmpty(List L) { 
    return L == NIL; 
}

int isFull(VHeap V) { 
    return V.avail == NIL; 
}

void display(List L, VHeap V) {
    for (int i = L; i != NIL; i = V.H[i].next) {
        printf("%d ", V.H[i].elem);
    }
    printf("\n");
}
