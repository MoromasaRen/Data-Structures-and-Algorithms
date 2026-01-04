#include <stdio.h>
#include <stdlib.h>
#define MAX 4

// ========== Structures ==========
typedef struct {
    int elem;
    int next;
} Cell;

typedef struct {
    HeapSpace H;
    int avail;
} VHeap;

typedef int List;
typedef Cell HeapSpace[MAX];

// ========== Function Prototypes ==========
void initialize(VHeap *V);
int allocSpace(VHeap *V);
void deallocSpace(VHeap *V, int index);
void insertFirst(int *L, VHeap *V, int elem);
void insertLast(int *L, VHeap *V, int elem);
void insertSorted(int *L, VHeap *V, int elem);
void deleteElem(int *L, VHeap *V, int elem);
void deleteAllOccurrence(int *L, VHeap *V, int elem);
void display(int L, VHeap V);

int main() {

    VHeap VH;
    List L = -1;

    initialize(&VH);

    insertFirst(&L, &VH, 10);
    insertLast(&L, &VH, 20);
    insertSorted(&L, &VH, 15);
    insertSorted(&L, &VH, 5);

    printf("List after inserts: ");
    display(L, VH);

    deleteElem(&L, &VH, 15);
    printf("After deleting 15: ");
    display(L, VH);

    insertFirst(&L, &VH, 20);
    deleteAllOccurrence(&L, &VH, 20);
    printf("After deleting all 20s: ");
    display(L, VH);

    return 0;
}

void initialize(VHeap *V) {
    V->avail = MAX - 1;

    for (int i = MAX - 1; i > 0; i--) {
        V->H[i].next = i - 1;
    }

    V->H[0].next = -1; 
}

int allocSpace(VHeap *V) {
    int ret = V->avail;
    if (ret != -1) {
        V->avail = V->H[ret].next;
    }
    return ret;
}

void deallocSpace(VHeap *V, int index) {
    if (index >= 0 && index < MAX) {
        V->H[index].next = V->avail;
        V->avail = index;
    }
}

void insertFirst(int *L, VHeap *V, int elem) {
    int newCell = allocSpace(V);
    if (newCell != -1) {
        V->H[newCell].elem = elem;
        V->H[newCell].next = *L;
        *L = newCell;
    }
}

void insertLast(int *L, VHeap *V, int elem) {
    int newCell = allocSpace(V);
    if (newCell == -1) return;

    V->H[newCell].elem = elem;
    V->H[newCell].next = -1;

    int *trav = L;

    while (*trav != -1) {
        trav = &V->H[*trav].next;
    }

    *trav = newCell;
}

void insertSorted(int *L, VHeap *V, int elem) {
    int newCell = allocSpace(V);
    if (newCell == -1) return;

    V->H[newCell].elem = elem;

    int *trav = L;
    while (*trav != -1 && V->H[*trav].elem < elem) {
        trav = &V->H[*trav].next;
    }

    V->H[newCell].next = *trav;
    *trav = newCell;
}

void deleteElem(int *L, VHeap *V, int elem) {
    int *trav = L;
    int temp;

    while (*trav != -1 && V->H[*trav].elem != elem) {
        trav = &V->H[*trav].next;
    }

    if (*trav != -1) {
        temp = *trav;
        *trav = V->H[temp].next;
        deallocSpace(V, temp);
    }
}

void deleteAllOccurrence(int *L, VHeap *V, int elem) {
    int *trav = L;
    int temp;

    while (*trav != -1) {
        if (V->H[*trav].elem == elem) {
            temp = *trav;
            *trav = V->H[temp].next;
            deallocSpace(V, temp);
        } else {
            trav = &V->H[*trav].next;
        }
    }
}

void display(int L, VHeap V) {
    for (int i = L; i != -1; i = V.H[i].next) {
        printf("%d ", V.H[i].elem);
    }
    printf("\n");
}
