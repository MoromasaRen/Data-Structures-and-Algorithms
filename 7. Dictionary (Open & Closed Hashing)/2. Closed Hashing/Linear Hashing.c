#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10
#define EMPTY -1
#define DELETED -2
#define NIL -1

typedef int Dictionary[MAX_SIZE];

void initDictionary(Dictionary Dict);
int hash(int value);
void insertDictionary(Dictionary Dict, int data);
void deleteData(Dictionary Dict, int data);
bool search(Dictionary Dict, int data); // isMember
void display(Dictionary Dict); 

int main (){
    Dictionary Dict;
    initDictionary(Dict);

    insertDictionary(Dict, 10);
    insertDictionary(Dict, 22);
    insertDictionary(Dict, 33);
    insertDictionary(Dict, 42);
    insertDictionary(Dict, 55);
    insertDictionary(Dict, 62);
    insertDictionary(Dict, 75);
    insertDictionary(Dict, 86);
    insertDictionary(Dict, 97);
    insertDictionary(Dict, 99);
    
    display(Dict);
    
    bool found = search(Dict, 20);
    if(found){
        printf("20 is in the dictionary\n");
    } else {
        printf("20 is not found\n");
    }
    
    deleteData(Dict, 10);
    
    insertDictionary(Dict, 10);
    display(Dict);

    return 0;
}

void initDictionary(Dictionary Dict){
    for(int i = 0; i < MAX_SIZE; i++){
        Dict[i] = EMPTY;
    }
}

int hash(int value){
    return value % MAX_SIZE;
}

void insertDictionary(Dictionary Dict, int data){
    int index = hash(data);
    int start = index;

    do{
        if(Dict[index] == EMPTY || Dict[index] == DELETED){
            Dict[index] = data;
            printf("Inserted %d at index [%d]\n", data, index);
            return;
        }
        index = (index + 1) % MAX_SIZE;
    } while(index != start);

    printf("Table is full, cannot insert\n");
}

void deleteData(Dictionary Dict, int data){
    int index = hash(data);
    int start = index;

    do {
        if(Dict[index] == data){
            Dict[index] = DELETED;
            printf("Deleted %d from index [%d]\n", data, index);
            return;
        }
        if(Dict[index] == EMPTY){
            printf("%d not found in dictionary\n", data);
            return;
        }
        index = (index + 1) % MAX_SIZE;
    } while (index != start);
    printf("%d not found in dictionary,\n", data);
}

bool search(Dictionary Dict, int data){
    int index = hash(data);
    int start = index;

    do{
        if(Dict[index] == data){
            return true;
        } 
        if(Dict[index] == EMPTY){
            return false;
        }
        index = (index + 1) % MAX_SIZE;
    } while (index != start);

    return false;
}

void display(Dictionary Dict){
    printf("\n%-8s %-8s\n", "Index", "Elem");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("[%2d]    %-8d\n", i, Dict[i]);
    }
    printf("\n");
}


