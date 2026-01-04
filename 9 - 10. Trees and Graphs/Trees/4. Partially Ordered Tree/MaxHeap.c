#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20

typedef struct {
    int elem[MAX];
    int size;
} MaxHeap;

void initialize(MaxHeap *H);
bool isEmpty(MaxHeap H);
bool isFull(MaxHeap H);
void insert(MaxHeap *H, int value);
int deleteMax(MaxHeap *H);
int peek(MaxHeap H);
void heapifyUp(MaxHeap *H, int index);
void heapifyDown(MaxHeap *H, int index);
void display(MaxHeap H);

int main() {
    MaxHeap H;
    initialize(&H);

    insert(&H, 50);
    insert(&H, 20);
    insert(&H, 30);
    insert(&H, 10);
    insert(&H, 40);
    insert(&H, 60);

    printf("After inserts:\n");
    display(H);

    printf("Peek (max) = %d\n", peek(H));

    printf("\nDeleteMax = %d\n", deleteMax(&H));
    display(H);

    printf("\nDeleteMax = %d\n", deleteMax(&H));
    display(H);

    return 0;
}

void initialize(MaxHeap *H) {
    H->size = 0;
}

bool isEmpty(MaxHeap H) {
    return H.size == 0;
}

bool isFull(MaxHeap H) {
    return H.size == MAX;
}

int peek(MaxHeap H) {
    return (H.size == 0) ? -1 : H.elem[0];
}

/* Insert value into maxheap (heapifyUp) */
void insert(MaxHeap *H, int value) {
    if (isFull(*H)) return;

    H->elem[H->size] = value;
    H->size++;
    heapifyUp(H, H->size - 1);
}

/* Remove and return maximum element (root) (heapifyDown) */
int deleteMax(MaxHeap *H) {
    if (isEmpty(*H)) return -1;

    int max = H->elem[0];
    H->elem[0] = H->elem[H->size - 1];
    H->size--;
    heapifyDown(H, 0);

    return max;
}

/* Move element up until heap property is restored */
void heapifyUp(MaxHeap *H, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (H->elem[parent] >= H->elem[index]) break;

        int temp = H->elem[parent];
        H->elem[parent] = H->elem[index];
        H->elem[index] = temp;

        index = parent;
    }
}

/* Move element down until heap property is restored */
void heapifyDown(MaxHeap *H, int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < H->size && H->elem[left] > H->elem[largest]) {
            largest = left;
        }
        if (right < H->size && H->elem[right] > H->elem[largest]) {
            largest = right;
        }

        if (largest == index) break;

        int temp = H->elem[index];
        H->elem[index] = H->elem[largest];
        H->elem[largest] = temp;

        index = largest;
    }
}

void display(MaxHeap H) {
    printf("Heap(size=%d): ", H.size);
    for (int i = 0; i < H.size; i++) {
        printf("%d ", H.elem[i]);
    }
    printf("\n");
}
