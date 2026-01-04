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
    insertSorted(&L, 8);
    insertSorted(&L, 1);

    display(&L);

    makeNULL(&L);
    return 0;
}

void initialize(List *L){
    L->elemPtr = malloc(sizeof(int) * LENGTH);
    L->max = LENGTH;
    L->count = 0;
}

void insertPos(List *L, int data, int position){
    if(position > L->count || position < 0){
        printf("Invalid Position.\n");
        return;
    }

    if(L->count >= L->max){
        resize(L);
    }

    int i;
    for(i = L->count; i > position; i--){
        L->elemPtr[i] = L->elemPtr[i - 1];
    }

    L->elemPtr[position] = data;
    L->count++;
}

void deletePos(List *L, int position){
    if(position >= L->count || position < 0){
        printf("Invalid Position.\n");
        return;
    }

    int i;
    for(i = position; i < L->count - 1; i++){
        L->elemPtr[i] = L->elemPtr[i + 1];
    }
    L->count--;
}

int locate(List *L, int data){
    int i;
    for(i = 0; i < L->count; i++){
        if(L->elemPtr[i] == data){
            return i;
        }
    }
    return -1;
}

int retrieve(List *L, int position){
    if(position >= L->count || position < 0){
        printf("Invalid Position.\n");
        return -1;
    }
    return L->elemPtr[position];
}

void insertSorted(List *L, int data){
    if(L->count >= L->max){
        resize(L);
    }

    int i;
    for(i = L->count - 1; i >= 0 && L->elemPtr[i] > data; i--){
        L->elemPtr[i + 1] = L->elemPtr[i];
    }

    L->elemPtr[i + 1] = data;
    L->count++;
}

void display(List *L){
    int i;
    for(i = 0; i < L->count; i++){
        printf("%d ", L->elemPtr[i]);
    }
    printf("\n");
}

void resize(List *L){
    L->max *= 2;
    L->elemPtr = realloc(L->elemPtr, sizeof(int) * L->max);
}

void makeNULL(List *L){
    free(L->elemPtr);
    L->elemPtr = NULL;
    L->count = 0;
    L->max = 0;
}
