#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20

typedef struct {
    int elem[MAX];
    int size;
} MinHeap;

void initialize(MinHeap *H);
bool isEmpty(MinHeap H);
bool isFull(MinHeap H);
void insert(MinHeap *H, int value);
int deleteMin(MinHeap *H);
int peek(MinHeap H);
void heapifyUp(MinHeap *H, int index);
void heapifyDown(MinHeap *H, int index);
void display(MinHeap H);

int main() {
    MinHeap H;
    initialize(&H);

    insert(&H, 50);
    insert(&H, 20);
    insert(&H, 30);
    insert(&H, 10);
    insert(&H, 40);
    insert(&H, 60);

    printf("After inserts:\n");
    display(H);

    printf("Peek (min) = %d\n", peek(H));

    printf("\nDeleteMin = %d\n", deleteMin(&H));
    display(H);

    printf("\nDeleteMin = %d\n", deleteMin(&H));
    display(H);

    return 0;
}

void initialize(MinHeap *H) {
    H->size = 0;
}

bool isEmpty(MinHeap H) {
    return H.size == 0;
}

bool isFull(MinHeap H) {
    return H.size == MAX;
}

int peek(MinHeap H) {
    return (H.size == 0) ? -1 : H.elem[0];
}

void insert(MinHeap *H, int value) {
    if (isFull(*H)) return;

    H->elem[H->size] = value;
    H->size++;
    heapifyUp(H, H->size - 1);
}

/* Remove and return minimum element (root) (heapifyDown) */
int deleteMin(MinHeap *H) {
    if (isEmpty(*H)) return -1;

    int min = H->elem[0];
    H->elem[0] = H->elem[H->size - 1];
    H->size--;
    heapifyDown(H, 0);

    return min;
}

/* Move element up until heap property is restored */
void heapifyUp(MinHeap *H, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (H->elem[parent] <= H->elem[index]) break;

        int temp = H->elem[parent];
        H->elem[parent] = H->elem[index];
        H->elem[index] = temp;

        index = parent;
    }
}

/* Move element down until heap property is restored */
void heapifyDown(MinHeap *H, int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < H->size && H->elem[left] < H->elem[smallest]) {
            smallest = left;
        }
        if (right < H->size && H->elem[right] < H->elem[smallest]) {
            smallest = right;
        }

        if (smallest == index) break;

        int temp = H->elem[index];
        H->elem[index] = H->elem[smallest];
        H->elem[smallest] = temp;

        index = smallest;
    }
}

void display(MinHeap H) {
    printf("Heap(size=%d): ", H.size);
    for (int i = 0; i < H.size; i++) {
        printf("%d ", H.elem[i]);
    }
    printf("\n");
}
