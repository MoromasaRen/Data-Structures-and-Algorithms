#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Bit field that holds exactly 8 bits wide
typedef struct {
    unsigned int field : 8;
} Set;

// Prototypes with parameters
void initialize(Set *set);
void insert(Set *set, int element);
void delete(Set *set, int element);
bool find(Set set, int element);
Set set_union(Set A, Set B);
Set intersection(Set A, Set B);
Set difference(Set A, Set B);
void display(Set *set);

int main (){
    Set A, B, C;

    initialize(&A);
    initialize(&B);

    insert(&A, 0);
    insert(&A, 4);
    insert(&A, 5);

    insert(&B, 2);
    insert(&B, 5);

    printf("Set A.field = ");
    display(&A);
    printf("Set B.field = ");
    display(&B);

    printf("Find: ");
    bool found = find(A, 5);
    if(found){
        printf("Element is found\n");
    } else {
        printf("Element is not found\n");
    }

    printf("Union A, B is Set C.field = ");
    C = set_union(A, B);
    display(&C);

    printf("Intersection A, B is Set C.field = ");
    C = intersection(A, B);
    display(&C);

    printf("Difference A, B is Set C.field = ");
    C = difference(A, B);
    display(&C);

    return 0;
}

/*
Access the 'field' member of the structure via the pointer
Set the value of this bit field directly to 0, clearing all bits within it
*/
void initialize(Set *set){
    set->field = 0;
}

/*
Safety check: ensure element index is within the bit range
Create the bitmask
Use Bitwise OR to set the corresponding bit within the 'field' member
*/
void insert(Set *set, int element){
    if(element < 0 || element > 7){
        printf("Error: element %d out of range (0-7)\n", element);
        return;
    }
    unsigned int mask = 1 << element;
    set->field |= mask;
}

/*
Safety check: ensure element index is within the bit range
Create the mask and invert it
Use Bitwise AND NOT to clear the corresponding bit in the field
*/
void delete(Set *set, int element){
    if(element < 0 || element > 7){
        printf("Error: element %d out of range (0-7)\n", element);
        return;
    }
    unsigned int mask = 1 << element;
    set->field &= ~mask;
}

/*
Create a mask
Use Bitwise AND to check the status of the corresponding bit in the field
*/
bool find(Set set, int element){
    if(element < 0 || element > 7) return false;
    unsigned int mask = 1 << element;
    return (set.field & mask) != 0;
}

// BITWISE OR [ | ]
Set set_union(Set A, Set B){
    Set C;
    C.field = A.field | B.field;
    return C;
}

// BITWISE AND [ & ]
Set intersection(Set A, Set B){
    Set C;
    C.field = A.field & B.field;
    return C;
}

// BITWISE A AND NOT B [ & (~) ]
Set difference(Set A, Set B){
    Set C;
    C.field = A.field & (~B.field);
    return C;
}

/*
Iterate through all possible elements (0 to 7)
Check if the bit corresponding to element i is set field
If present, print the element, separated by commas
*/
void display(Set *set){

    printf("%u ", set->field);
    
    printf("{");
    bool first = true;
    for(int i = 0; i < 8; i++){
        if(set->field & (1 << i)){
            if(!first) printf(", ");
            printf("%d", i);
            first = false;
        }
    }
    printf("}\n");
}