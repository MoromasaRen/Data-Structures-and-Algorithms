#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 50

/* ===== Priority Queue (Max-Priority) using Binary Heap =====
   Higher priority = larger key/value
*/
typedef struct {
    int arr[MAX];
    int size;
} PriorityQueue;

void initializePQ(PriorityQueue *PQ);
bool isEmptyPQ(PriorityQueue PQ);
bool isFullPQ(PriorityQueue PQ);
void swap(int *a, int *b);
void heapifyUp(PriorityQueue *PQ, int index);
void heapifyDown(PriorityQueue *PQ, int index);
void enqueue(PriorityQueue *PQ, int value);     
int  peek(PriorityQueue PQ);                    
int  dequeue(PriorityQueue *PQ);               
bool changePriority(PriorityQueue *PQ, int oldVal, int newVal); 
bool contains(PriorityQueue PQ, int value);                   
void displayPQ(PriorityQueue PQ);                            

int main() {
    PriorityQueue PQ;
    initializePQ(&PQ);

    printf("=== ENQUEUE (insert) ===\n");
    enqueue(&PQ, 10);
    displayPQ(PQ);

    enqueue(&PQ, 5);
    displayPQ(PQ);

    enqueue(&PQ, 20);
    displayPQ(PQ);

    enqueue(&PQ, 15);
    displayPQ(PQ);

    enqueue(&PQ, 30);
    displayPQ(PQ);

    printf("\n=== PEEK (highest priority) ===\n");
    printf("Peek: %d\n", peek(PQ));

    printf("\n=== CONTAINS (search) ===\n");
    int x = 15;
    printf("Contains %d? %s\n", x, contains(PQ, x) ? "true" : "false");

    printf("\n=== CHANGE PRIORITY (update) ===\n");
    if (changePriority(&PQ, 15, 40)) {
        printf("Changed 15 to 40\n");
    } else {
        printf("15 not found\n");
    }
    displayPQ(PQ);

    printf("\n=== DEQUEUE (remove highest priority) ===\n");
    while (!isEmptyPQ(PQ)) {
        int m = dequeue(&PQ);
        printf("Dequeued: %d | ", m);
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
    return PQ.size >= MAX;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* Restore heap upward (used after insert or increasing key) */
void heapifyUp(PriorityQueue *PQ, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (PQ->arr[parent] >= PQ->arr[index]) break;
        swap(&PQ->arr[parent], &PQ->arr[index]);
        index = parent;
    }
}

/* Restore heap downward (used after delete max or decreasing key) */
void heapifyDown(PriorityQueue *PQ, int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < PQ->size && PQ->arr[left] > PQ->arr[largest]) largest = left;
        if (right < PQ->size && PQ->arr[right] > PQ->arr[largest]) largest = right;

        if (largest == index) break;

        swap(&PQ->arr[index], &PQ->arr[largest]);
        index = largest;
    }
}

/* Insert into priority queue */
void enqueue(PriorityQueue *PQ, int value) {
    if (isFullPQ(*PQ)) {
        printf("PQ is full. Cannot enqueue %d\n", value);
        return;
    }

    PQ->arr[PQ->size] = value;
    PQ->size++;
    heapifyUp(PQ, PQ->size - 1);
}

/* View highest priority (max) without removing */
int peek(PriorityQueue PQ) {
    if (isEmptyPQ(PQ)) return -1;
    return PQ.arr[0];
}

/* Remove highest priority (max) */
int dequeue(PriorityQueue *PQ) {
    if (isEmptyPQ(*PQ)) return -1;

    int max = PQ->arr[0];
    PQ->arr[0] = PQ->arr[PQ->size - 1];
    PQ->size--;
    heapifyDown(PQ, 0);

    return max;
}

/* Search (linear) */
bool contains(PriorityQueue PQ, int value) {
    for (int i = 0; i < PQ.size; i++) {
        if (PQ.arr[i] == value) return true;
    }
    return false;
}

/* Change priority: replace oldVal with newVal and fix heap */
bool changePriority(PriorityQueue *PQ, int oldVal, int newVal) {
    int idx = -1;
    for (int i = 0; i < PQ->size; i++) {
        if (PQ->arr[i] == oldVal) {
            idx = i;
            break;
        }
    }
    if (idx == -1) return false;

    int prev = PQ->arr[idx];
    PQ->arr[idx] = newVal;

    if (newVal > prev) heapifyUp(PQ, idx);
    else if (newVal < prev) heapifyDown(PQ, idx);

    return true;
}

/* Display internal heap array order */
void displayPQ(PriorityQueue PQ) {
    printf("PQ(size=%d): ", PQ.size);
    for (int i = 0; i < PQ.size; i++) {
        printf("%d ", PQ.arr[i]);
    }
    printf("\n");
}
