#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

typedef struct {
    int *elemPtr;
    int count;
    int max;
} List;

void initialize(List *L);
void insertPos(List *L, int data, int position);
void deletePos(List *L, int position);
int locate(List *L, int data);
int retrieve(List *L, int position);
void insertSorted(List *L, int data);
void display(List *L);
void resize(List *L);
void makeNULL(List *L);

int main (){
    List L;
    initialize(&L);

    insertSorted(&L, 5);
    insertSorted(&L, 2);
    insertSorted(&L, 9);
    insertSorted(&L, 1);

    display(&L);

    deletePos(&L, 2);
    display(&L);

    printf("Index of 5: %d\n", locate(&L, 5));
    printf("Element at index 1: %d\n", retrieve(&L, 1));

    makeNULL(&L);
    return 0;
}

/* Initialize list */
void initialize(List *L){
    L->elemPtr = malloc(sizeof(int) * LENGTH);
    L->count = 0;
    L->max = LENGTH;
}

/* Insert at specific position */
void insertPos(List *L, int data, int position){
    if(position < 0 || position > L->count){
        printf("Invalid position.\n");
        return;
    }

    if(L->count == L->max){
        resize(L);
    }

    for(int i = L->count; i > position; i--){
        L->elemPtr[i] = L->elemPtr[i - 1];
    }

    L->elemPtr[position] = data;
    L->count++;
}

/* Delete element at position */
void deletePos(List *L, int position){
    if(position < 0 || position >= L->count){
        printf("Invalid position.\n");
        return;
    }

    for(int i = position; i < L->count - 1; i++){
        L->elemPtr[i] = L->elemPtr[i + 1];
    }

    L->count--;
}

/* Locate element and return index */
int locate(List *L, int data){
    for(int i = 0; i < L->count; i++){
        if(L->elemPtr[i] == data){
            return i;
        }
    }
    return -1;
}

/* Retrieve element at position */
int retrieve(List *L, int position){
    if(position < 0 || position >= L->count){
        printf("Invalid position.\n");
        return -1;
    }
    return L->elemPtr[position];
}

/* Insert element in sorted order */
void insertSorted(List *L, int data){
    if(L->count == L->max){
        resize(L);
    }

    int i;
    for(i = L->count - 1; i >= 0 && L->elemPtr[i] > data; i--){
        L->elemPtr[i + 1] = L->elemPtr[i];
    }

    L->elemPtr[i + 1] = data;
    L->count++;
}

/* Display list */
void display(List *L){
    printf("List: ");
    for(int i = 0; i < L->count; i++){
        printf("%d ", L->elemPtr[i]);
    }
    printf("\n");
}

/* Resize list when full */
void resize(List *L){
    L->max *= 2;
    L->elemPtr = realloc(L->elemPtr, sizeof(int) * L->max);
}

/* Free memory */
void makeNULL(List *L){
    free(L->elemPtr);
    L->elemPtr = NULL;
    L->count = 0;
    L->max = 0;
}
