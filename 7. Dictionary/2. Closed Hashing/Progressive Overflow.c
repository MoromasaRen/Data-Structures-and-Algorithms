#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
#define MAX_P 5
#define MAX_S 5
#define TOTAL_SIZE (MAX_P + MAX_S)
#define EMPTY 0
#define NIL -1 // Next In Line

typedef struct {
    int elem;
    int next;
    bool occupied;
} Entry;

typedef struct {
    Entry table[TOTAL_SIZE];
    int avail;
} Dictionary;

void initDictionary(Dictionary *Dict);
int hash(int value);
void insertDictionary(Dictionary *Dict, int data);
void deleteData(Dictionary *Dict, int data);
bool search(Dictionary Dict, int data);
void display(Dictionary Dict); 


void initDictionary(Dictionary *Dict){
    //Primary
    for(int i = 0; i < MAX_P; i++){
        Dict->table[i].occupied = false;
        Dict->table[i].elem = EMPTY;
        Dict->table[i].next = NIL;
    }

    //Secondary
    for(int i = 0; i < MAX_S; i++){
        Dict->table[i].occupied = false;
        Dict->table[i].elem = EMPTY;
        Dict->table[i].next = i + 1;
    }

    Dict->table[TOTAL_SIZE - 1].occupied = false;
    Dict->table[TOTAL_SIZE - 1].next = NIL;

    Dict->avail = MAX_P;
}

int hash(int value){
    return value % MAX_P;
}

void insertDictionary(Dictionary *Dict, int data){
    int index = hash(data);

    if(!Dict->table[index].occupied){
        Dict->table[index].elem = data;
        Dict->table[index].occupied = true;
        Dict->table[index].next = -1;
        printf("Inserted %d at primary [%d].\n", data, index);
    }

    
}

void deleteData(Dictionary *Dict, int data){

}

bool search(Dictionary Dict, int data){

}

void display(Dictionary Dict){

}
