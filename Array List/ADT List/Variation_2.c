#include <stdio.h>
#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} Etype, *EPtr;

void initialize(EPtr L);
void insertPos(EPtr L, int data, int position);
void deletePos(EPtr L, int position);
int locate(EPtr L, int data);
int retrieve(EPtr L, int position);
void insertSorted(EPtr L, int data);
void display(EPtr L);
void makeNULL(EPtr L);

int main (){
    EPtr L;
    initialize(L);
    L->elem[0] = 1;
    L->elem[1] = 3;
    L->elem[2] = 2;
    L->elem[3] = 5;
    L->count = 4;
    insertPos(L, 10, 0);
    
}

void initialize(EPtr L){
    L->count = 0;
}

void insertPos(EPtr L, int data, int position){
    if(position < 0 || position > L->count){
        printf("Invalid Position!\n");
    }
    if(L->count >= MAX){
        printf("List is full");
    }
    int i;
    for(i = 0; i < L->count; i--){
        L->elem[i] = L->elem[i - 1];
    }
    L->elem[position] = data;
    L->count++;
}

void deletePos(EPtr L, int position){
    if(position < 0 || position > L->count){
        printf("Invalid Position!\n");
    }
    int i;
    for(i = position; i < L->count - 1; i++){
        L->elem[i] = L->elem[i + 1];
    }
    L->count--;
}

int locate(EPtr L, int data){
    int i;
    for(i = 0; i < L->count; i++){
        if(L->elem == data){
            return i;
        }
    }
    return -1;
}

int retrieve(EPtr L, int position){
    int elem, i;
    if(L->count >= MAX){
        printf("List is full.");
    } else {
        for(i = 0; i < position; i++){
                elem = L->elem;
            return elem;
        }
    }
    return -1;
}

void insertSorted(EPtr L, int data){
    if(L->count >= MAX){
        printf("List is full");
        return;
    }
    int i = L->count-1;
    
}
void display(EPtr L){
    
}

void makeNULL(EPtr L){
    free(L);
}
