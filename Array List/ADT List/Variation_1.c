#include <stdio.h>

#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} List;

List initialize (List L);
List insertPos (List L, int data, int position);
List deletePos(List L, int position);
int locate (List L, int data);
List insertSorted (List L, int data);
void display(List L);

int main (){
    List L = initialize(L);
    int position, data, operation;
    L.elem[0] = 1;
    L.elem[1] = 3;
    L.elem[2] = 2;
    L.elem[3] = 5;
    L.count = 4;
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
            return 0;
        break;
        case 1:
        //Insert
        L = insertPos (L, 4, 2);
        //Display
        display(L);
        printf("\nCount: %d\n", L.count);
        break;
        case 2:   
        //Delete
        L = deletePos(L, 1);
        //Display
        display(L);
        printf("\nCount: %d\n", L.count);
        break;
        case 3:
        //Locate
        int location = locate(L, 1);
        if(location != -1){
            printf("Data is found at index %d\n", location);
        } else {
            printf("Data is not Found!\n");
        }
        //Display
        display(L);
        printf("\nCount: %d\n", L.count);
        break;
        case 4:
        // Insert Sorted
        L = insertSorted (L, 8);
        //Display
        display(L);
        printf("\nCount: %d\n", L.count);
        break;
    }
    } while (operation != 0);

    return 0;
}

List initialize (List L){
    // Set count to 0
    L.count = 0;
    for(int i = 0; i < MAX; i++){
        L.elem[i] = 0;
    }
    // Return List
    return L;
}

List insertPos (List L, int data, int position){
    // Valid Pos
    if(position < 0 || position > L.count){
        printf("Invalid Position.\n");
        return L;
    }
    // If List is full
    if(L.count >= MAX){
        printf("List is full.\n");
        return L;
    }
    // Insert into specified position
    int i;
    for(i = L.count; i > position; i--){
        L.elem[i] = L.elem[i - 1];
    }
    L.elem[position] = data;
    L.count++;
    return L;
}

List deletePos(List L, int position){
    // Valid Pos
    if(position < 0 || position >= L.count){
        printf("Invalid Position.\n");
        return L;
    }
    // Shift to left
    int i;
    for(i = position; i < L.count-1; i++){
        L.elem[i] = L.elem[i+1];
    }
    L.elem[L.count - 1] = -1;
    L.count--;
    return L;
}

int locate (List L, int data){
    // Loop through the array and return the position of the data if found
    int i;
    for(i = 0; i < L.count; i++){
        if(L.elem[i] == data){
            return i;
        }
    }
        return -1;
}

List insertSorted (List L, int data){
    // If List is full
    if(L.count >= MAX){
        printf("List is full.\n");
        return L;
    }
    // Insert the element into the correct position based on the value
    int i = L.count-1;
    while(i >= 0 && L.elem[i] > data){
        L.elem[i+1] = L.elem[i];
        i--;
    }
    L.elem[i+1] = data;
    L.count++;
    return L;
}

void display(List L){
    printf("elem: ");
    for(int i = 0; i < L.count; i++){
        printf("%d ", L.elem[i]);
    }
}