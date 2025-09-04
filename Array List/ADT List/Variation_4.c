#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct {
    int *elemPtr;
    int count;
    int max;
}List;

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

    return 0;
}

void initialize(List *L){
    L->elemPtr = malloc(sizeof(List) * LENGTH);
    L->max = LENGTH;
    L->count = 0;
}

void insertPos(List *L, int data, int position){
    if(position >= L->count || position < 0){
        printf("Invalid Position.");
        return;
    }
    if(L->count >= L->max){
        resize(&L);
        return;
    }
    int i;
    for(i = L->count; i > position; i++){
        L->elemPtr[i] = L->elemPtr[i - 1];
    }
    L->elemPtr[position] = data;
    L->count++;

}

void deletePos(List *L, int position){
    if(position >= L->count || position < 0){
        printf("Invalid Position.");
        return;
    }
    int i;
    for(i = L->count; i < position; i++){
        L->elemPtr[i] = L->elemPtr[i + 1];
    }
    L->count--;

}

int locate(List *L, int data){
    int i;
    for(i = 0; i < L->count; i++){
        if(L->elemPtr[i] == data){
            return 1;
        }
    }
    return -1;

}

int retrieve(List *L, int position){
    if(position >= L->count || position < 0){
        printf("Invalid Position.");
        return -1;
    }
    return L->elemPtr[position];    
}

void insertSorted(List *L, int data){
    

}
void display(List *L);
void resize(List *L);
void makeNULL(List *L);