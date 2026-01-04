#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 30

/* Priority Queue using a Partially Ordered Tree (Heap)
   This version is a MAX-Priority Queue:
   - Highest number = highest priority
   - Heap property: parent >= children
*/

typedef struct {
    int elem[MAX];
    int size;
} PriorityQueue;

void initializePQ(PriorityQueue *PQ);
bool isEmptyPQ(PriorityQueue PQ);
bool isFullPQ(PriorityQueue PQ);
void enqueue(PriorityQueue *PQ, int value);   
int  dequeue(PriorityQueue *PQ);             
int  peek(PriorityQueue PQ);                
void heapifyUp(PriorityQueue *PQ, int index);
void heapifyDown(PriorityQueue *PQ, int index);
void displayPQ(PriorityQueue PQ);

int main() {
    PriorityQueue PQ;
    initializePQ(&PQ);

    printf("=== ENQUEUE (insert) ===\n");
    enqueue(&PQ, 15);
    enqueue(&PQ, 3);
    enqueue(&PQ, 20);
    enqueue(&PQ, 9);
    enqueue(&PQ, 30);
    enqueue(&PQ, 12);
    displayPQ(PQ);

    printf("\nPeek (highest priority) = %d\n", peek(PQ));

    printf("\n=== DEQUEUE (remove highest priority) ===\n");
    while (!isEmptyPQ(PQ)) {
        int x = dequeue(&PQ);
        printf("Dequeued: %d | ", x);
        displayPQ(PQ);
    }

    return 0;
}

void initializePQ(PriorityQueue *PQ) {
    PQ->size = 0;
}

bool isEmptyPQ(PriorityQueue PQ) {
    return PQ.size == 0;
}

bool isFullPQ(PriorityQueue PQ) {
    return PQ.size == MAX;
}

int peek(PriorityQueue PQ) {
    if (isEmptyPQ(PQ)) return -1;
    return PQ.elem[0];
}

/* Insert into the heap (bubble up) */
void enqueue(PriorityQueue *PQ, int value) {
    if (isFullPQ(*PQ)) return;

    PQ->elem[PQ->size] = value;
    PQ->size++;
    heapifyUp(PQ, PQ->size - 1);
}

/* Remove the root (max) (bubble down) */
int dequeue(PriorityQueue *PQ) {
    if (isEmptyPQ(*PQ)) return -1;

    int max = PQ->elem[0];
    PQ->elem[0] = PQ->elem[PQ->size - 1];
    PQ->size--;
    heapifyDown(PQ, 0);

    return max;
}

void heapifyUp(PriorityQueue *PQ, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (PQ->elem[parent] >= PQ->elem[index]) break;

        int temp = PQ->elem[parent];
        PQ->elem[parent] = PQ->elem[index];
        PQ->elem[index] = temp;

        index = parent;
    }
}

void heapifyDown(PriorityQueue *PQ, int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < PQ->size && PQ->elem[left] > PQ->elem[largest]) largest = left;
        if (right < PQ->size && PQ->elem[right] > PQ->elem[largest]) largest = right;

        if (largest == index) break;

        int temp = PQ->elem[index];
        PQ->elem[index] = PQ->elem[largest];
        PQ->elem[largest] = temp;

        index = largest;
    }
}

void displayPQ(PriorityQueue PQ) {
    printf("PQ(size=%d): ", PQ.size);
    for (int i = 0; i < PQ.size; i++) {
        printf("%d ", PQ.elem[i]);
    }
    printf("\n");
}
