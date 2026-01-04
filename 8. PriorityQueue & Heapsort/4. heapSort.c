#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct {
    int arr[MAX];
    int size;
} MaxHeap;

// Function Prototypes MAX HEAP Version
void initialize(MaxHeap *H);
void swap(int *a, int *b);
void heapifyUp(MaxHeap *H, int index);
void heapifyDown(MaxHeap *H, int index);
void insertHeap(MaxHeap *H, int value);
int deleteMax(MaxHeap *H);
void buildMaxHeap(MaxHeap *H);
void heapSort(int arr[], int n);
void printHeap(MaxHeap H);
void printArray(int arr[], int n);

int main() {
    int arr[] = {4, 10, 3, 5, 1, 2, 8, 7, 6, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    printArray(arr, n);

    printf("\n=== Insert Operations ===\n");
    MaxHeap H;
    initialize(&H);

    for (int i = 0; i < n; i++) {
        insertHeap(&H, arr[i]);
        printf("After inserting %d: ", arr[i]);
        printHeap(H);
    }

    printf("\n=== Delete Max Operations ===\n");
    while (H.size > 0) {
        int max = deleteMax(&H);
        printf("Deleted max %d -> ", max);
        printHeap(H);
    }

    printf("\n=== Heap Sort Process ===\n");
    heapSort(arr, n);

    printf("\nSorted Array (Ascending):\n");
    printArray(arr, n);

    return 0;
}

void initialize(MaxHeap *H) {
    H->size = 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Move value UP to restore max-heap property */
void heapifyUp(MaxHeap *H, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (H->arr[parent] >= H->arr[index])
            break;

        swap(&H->arr[parent], &H->arr[index]);
        index = parent;
    }
}

/* Move value DOWN to restore max-heap property */
void heapifyDown(MaxHeap *H, int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < H->size && H->arr[left] > H->arr[largest])
            largest = left;

        if (right < H->size && H->arr[right] > H->arr[largest])
            largest = right;

        if (largest == index)
            break;

        swap(&H->arr[index], &H->arr[largest]);
        index = largest;
    }
}

/* Insert element into heap */
void insertHeap(MaxHeap *H, int value) {
    if (H->size >= MAX)
        return;

    H->arr[H->size] = value;
    H->size++;
    heapifyUp(H, H->size - 1);
}

/* Remove and return maximum element */
int deleteMax(MaxHeap *H) {
    if (H->size == 0)
        return -1;

    int max = H->arr[0];
    H->arr[0] = H->arr[H->size - 1];
    H->size--;
    heapifyDown(H, 0);

    return max;
}

/* Build heap using bottom-up method */
void buildMaxHeap(MaxHeap *H) {
    for (int i = (H->size / 2) - 1; i >= 0; i--) {
        heapifyDown(H, i);
    }
}

/* Heap Sort (Ascending order) */
void heapSort(int arr[], int n) {
    MaxHeap H;
    initialize(&H);

    for (int i = 0; i < n; i++) {
        H.arr[i] = arr[i];
    }
    H.size = n;

    printf("Building Max Heap...\n");
    buildMaxHeap(&H);
    printHeap(H);

    for (int i = n - 1; i >= 0; i--) {
        arr[i] = deleteMax(&H);
        printf("After placing max at index %d: ", i);
        printArray(arr, n);
    }
}

/* Print heap array */
void printHeap(MaxHeap H) {
    printf("Heap: ");
    for (int i = 0; i < H.size; i++) {
        printf("%d ", H.arr[i]);
    }
    printf("\n");
}

/* Print array */
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
