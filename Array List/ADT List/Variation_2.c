#include <stdio.h>
#include <stdlib.h>
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
    EPtr L = (EPtr) malloc(sizeof(Etype));
    if (!L) return 1;

    initialize(L);
    L->elem[0] = 1;
    L->elem[1] = 3;
    L->elem[2] = 2;
    L->elem[3] = 5;
    L->count = 4;

    int operation;
    do {
        printf("\n1: Insert\n");
        printf("2: Delete\n");
        printf("3: Locate\n");
        printf("4: InsertSorted\n");
        printf("0: Exit\n");
        printf("Enter operation: ");
        scanf("%d", &operation);

        switch (operation){
            case 0:
                free(L);
                return 0;
            case 1:
                insertPos(L, 4, 2);
                display(L);
                printf("\nCount: %d\n", L->count);
                break;
            case 2:
                deletePos(L, 1);
                display(L);
                printf("\nCount: %d\n", L->count);
                break;
            case 3: {
                int location = locate(L, 1);
                if(location != -1){
                    printf("Data is found at index %d\n", location);
                } else {
                    printf("Data is not Found!\n");
                }
                display(L);
                printf("\nCount: %d\n", L->count);
                break;
            }
            case 4:
                insertSorted(L, 8);
                display(L);
                printf("count: %d\n", L->count);
                break;
        }
    } while (operation != 0);
}

void initialize(EPtr L){ 
    L->count = 0; 
}

void insertPos(EPtr L, int data, int position){
    if(position < 0 || position > L->count){
        printf("Invalid Position!\n");
        return;
    }
    if(L->count >= MAX){
        printf("List is full\n");
        return;
    }
    for(int i = L->count; i > position; i--){
        L->elem[i] = L->elem[i - 1];
    }
    L->elem[position] = data;
    L->count++;
}

void deletePos(EPtr L, int position){
    if(position < 0 || position >= L->count){
        printf("Invalid Position!\n");
        return;
    }
    for(int i = position; i < L->count - 1; i++){
        L->elem[i] = L->elem[i + 1];
    }
    L->count--;
}

int locate(EPtr L, int data){
    for(int i = 0; i < L->count; i++){
        if (L->elem[i] == data) return i;
    }
    return -1;
}

int retrieve(EPtr L, int position){
    if(position >= L->count || position < 0){
        printf("Invalid Position.");
        return -1;
    }
    return L->elem[position];    
}

void insertSorted(EPtr L, int data){
    if(L->count >= MAX){
        printf("List is full\n");
        return;
    }
    int i = L->count-1;
    while(i >= 0 && L->elem[i] > data){
        L->elem[i + 1] = L->elem[i];
        i--;
    }
    L->elem[i + 1] = data;
    L->count++;
}

void display(EPtr L){
    printf("elem: ");
    for(int i = 0; i < L->count; i++){
        printf("%d ", L->elem[i]);
    }
    printf("\n");
}

void makeNULL(EPtr L){
    L->count = 0; 
}
