
// Array to ArrayList Implementation

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

typedef struct {
    int *data;      
    int size;       
    int capacity;   
} ArrayList;

typedef ArrayList Dictionary[MAX_SIZE];

// Prototypes
void initDictionary(Dictionary Dict);
int hash(int value);
void initList(ArrayList *L);
void ensureCapacity(ArrayList *L);
void insertDictionary(Dictionary Dict, int data);
void deleteData(Dictionary Dict, int data);
bool search(Dictionary Dict, int data);
void display(Dictionary Dict);
void freeDictionary(Dictionary Dict);

int main() {
    Dictionary Dict;
    initDictionary(Dict);

    insertDictionary(Dict, 10);
    insertDictionary(Dict, 20);
    insertDictionary(Dict, 13);
    insertDictionary(Dict, 15);
    insertDictionary(Dict, 25);
    insertDictionary(Dict, 39);
    insertDictionary(Dict, 5);
    insertDictionary(Dict, 2);

    printf("Before Delete:\n");
    display(Dict);

    int findVal = 25;
    if (search(Dict, findVal)) {
        printf("\n%d found in dictionary at index %d.\n", findVal, hash(findVal));
    } else {
        printf("\n%d not found in dictionary.\n", findVal);
    }

    deleteData(Dict, 25);

    printf("\nAfter Delete:\n");
    display(Dict);

    freeDictionary(Dict);
    return 0;
}

void initList(ArrayList *L) {
    L->data = NULL;
    L->size = 0;
    L->capacity = 0;
}

void initDictionary(Dictionary Dict) {
    for (int i = 0; i < MAX_SIZE; i++) {
        initList(&Dict[i]);
    }
}

int hash(int value) {
    return value % MAX_SIZE;
}

void ensureCapacity(ArrayList *L) {
    if (L->size < L->capacity) return;

    int newCap = (L->capacity == 0) ? 2 : L->capacity * 2;
    int *newData = (int*)realloc(L->data, newCap * sizeof(int));
    if (newData == NULL) return;

    L->data = newData;
    L->capacity = newCap;
}

void insertDictionary(Dictionary Dict, int data) {
    int index = hash(data);
    ArrayList *bucket = &Dict[index];

    ensureCapacity(bucket);
    if (bucket->size < bucket->capacity) {
        bucket->data[bucket->size++] = data;
    }
}

void deleteData(Dictionary Dict, int data) {
    int index = hash(data);
    ArrayList *bucket = &Dict[index];

    if (bucket->size == 0) {
        printf("Value %d is not found\n", data);
        return;
    }

    int pos = -1;
    for (int i = 0; i < bucket->size; i++) {
        if (bucket->data[i] == data) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Value %d is not found\n", data);
        return;
    }

    for (int i = pos; i < bucket->size - 1; i++) {
        bucket->data[i] = bucket->data[i + 1];
    }
    bucket->size--;

    printf("%d Data deleted successfully\n", data);
}

bool search(Dictionary Dict, int data) {
    int index = hash(data);
    ArrayList bucket = Dict[index];

    for (int i = 0; i < bucket.size; i++) {
        if (bucket.data[i] == data) return true;
    }
    return false;
}

void display(Dictionary Dict) {
    printf("Hash Table:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("[%d] = ", i);

        if (Dict[i].size == 0) {
            printf("Empty.\n");
        } else {
            for (int j = 0; j < Dict[i].size; j++) {
                printf("%d", Dict[i].data[j]);
                if (j != Dict[i].size - 1) printf(", ");
            }
            printf("\n");
        }
    }
}

void freeDictionary(Dictionary Dict) {
    for (int i = 0; i < MAX_SIZE; i++) {
        free(Dict[i].data);
        Dict[i].data = NULL;
        Dict[i].size = 0;
        Dict[i].capacity = 0;
    }
}
