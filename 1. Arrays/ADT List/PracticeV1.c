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

    
    return 0;
}

List initialize (List L){
    L.count = 0;
    return L;
}

List insertPos (List L, int data, int position){
    // Inserting First, Last, and Position shifting elements to right
    int i;
    // Check if position is valid
    if(position < 0 || position > L.count){
        printf("Invalid Position.\n");
        return L;
    }
    // If List is Full
    if(L.count >= MAX){
        printf("List is full.\n");
        return L;
    }
    // Insert First
    if(position == 0){
        for(i = L.count; i > 0; i--){
            L.elem[i] = L.elem[i - 1];
        }
        L.elem[0] = data;
        L.count++;
        return L;
    }
    // Insert Last
    if(position == L.count){
        L.elem[L.count] = data;
        L.count++;
        return L;
    }
    // Insert Position
    for(i = L.count; i > position; i--){
        L.elem[i] = L.elem[i - 1];
    }
    L.elem[position] = data;
    L.count++;
    return L;
}

List deletePos (List L, int position){
    // Deleting First, Last, and Position shifting elements to left
    int i;
    // Check if position is valid
    if(position < 0 || position >= L.count){
        printf("Invalid Position.\n");
        return L;
    }
    // Delete first
    if(position == 0){
        for(i = 0; i < L.count - 1; i++){
            L.elem[i] = L.elem[i + 1];
        }
        L.count--;
        return L;
    }
    // Delete Last
    if(position == L.count - 1){
        L.count--;
        return L;
    }
    // Delete Position
    for(i = position; i < L.count - 1; i++){
        L.elem[i] = L.elem[i + 1];
    }
    L.count--;
    return L;
}

List deleteOccurences (List L, int data){
    int i, j;
    // Normal Loop
    for(i = 0; i < L.count; i++){ 
        if(L.elem[i] == data){ // If data is elem is data loop through and shift left
            for(j = i; j < L.count; j--){
                L.elem[j] = L.elem[j + 1];
            }
            L.count--;
            i--;
        }
    }
    return L;
}

int locate (List L, int data) {
    // Loop through array to find and return index if found
    int i;
    for(i = 0; i < L.count; i++){
        if(L.elem[i] == data){
            return i;
        }
    }
    return -1;
}

List insertSorted (List L, int data){
    // If list is full
    if(L.count >= MAX){
        printf("List is full.\n");
        return L;
    }
    // Insert element into correct position
    int i;
    for(i = L.count - 1; i >= 0 && L.elem[i] > data; i--){
        L.elem[i + 1] = L.elem[i];
    }
    L.elem[i + 1] = data;
    L.count++;
    return L;
}

void display(List L){
    printf("Elem: ");
    for(int i = 0; i < L.count; i++){
        printf("%d ", L.elem[i]);
    }
}
