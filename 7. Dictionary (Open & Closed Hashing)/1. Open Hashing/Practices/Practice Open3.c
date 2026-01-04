#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10

typedef struct Node {
    int lockerID;  
    char owner[32];
    char code[8];    
    int isActive;
    struct Node* next;   
} Locker, *LockerPtr;

typedef LockerPtr Dictionary[MAX];

void initDict(Dictionary D);
Locker* createLocker(Locker L);
int total_numOfLetters(char* string);
int total_numOfBits(int x);
int hash(Locker L);
void insert(Dictionary D, Locker L);
void delete(Dictionary D, Locker L);
bool isMember(Dictionary D, Locker L);
void display(Dictionary D);
void deleteDict(Dictionary D);
void populateDict(Dictionary D);

int main() {
    Dictionary D;
    initDict(D);

    populateDict(D);

    printf("Initial Dictionary:\n");
    display(D);

    Locker newLocker = {4231, "Jem", "9090", 1};
    printf("\nInserting new locker:\n");
    insert(D, newLocker);
    display(D);

    Locker searchLocker = {0, "", "5010", 0}; // search by code only
    printf("\nSearching for locker with code %s...\n", searchLocker.code);
    if (isMember(D, searchLocker)) {
        printf("Locker with code %s FOUND!\n", searchLocker.code);
    } else {
        printf("Locker with code %s NOT FOUND!\n", searchLocker.code);
    }

    Locker deleteLocker = {0, "", "1050", 0}; // delete by code
    printf("\nDeleting locker with code %s...\n", deleteLocker.code);
    delete(D, deleteLocker);

    printf("\nDictionary after deletion:\n");
    display(D);

    deleteDict(D);
    return 0;
}

void initDict(Dictionary D){
    for(int i = 0; i < MAX; i++){
        D[i] = 0;
    }
}

void populateDict(Dictionary D){
    Locker L[] = {
        {4187, "Ren", "1000", 1},
        {4156, "Naz", "1060", 0},
        {4156, "Sieg", "5010", 1},
        {4156, "Al", "1050", 1},
        {4156, "Mart", "2030", 0}
    };
    int length = sizeof(L) / sizeof(L[0]);
    for(int i = 0; i < length; i++){
        insert(D, L[i]);
    }
}

Locker* createLocker(Locker L){
    Locker* newLocker = malloc(sizeof(Locker));
    newLocker->lockerID = L.lockerID;
    strcpy(newLocker->owner, L.owner);
    strcpy(newLocker->code, L.code);
    newLocker->isActive = L.isActive;
    newLocker->next = NULL;
    return newLocker;
}

int total_numOfLetters(char* string){
    int length = strlen(string);
    int total = 0;

    for(int i = 0; i < length; i++){
        total += string[i];
    }
    return total;
}

int total_numOfBits(int x){
    unsigned int mask = 1 << (sizeof(int) * 8 - 1);
    int total = 0;

    while(mask != 0){
        if(mask & x) total++;
        mask >>= 1;
    }
    return total;
}

int hash(Locker L){
    return (total_numOfBits(total_numOfLetters(L.code)) * total_numOfLetters(L.owner)) % MAX;
}

void insert(Dictionary D, Locker L){
    int index = hash(L);
    Locker* newLocker = createLocker(L);

    if(D[index] == NULL){
        D[index] = newLocker;
    } else {
        Locker* current = D[index];
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newLocker;
    }
}

void delete(Dictionary D, Locker L){
    for (int i = 0; i < MAX; i++) {
        Locker* current = D[i];
        Locker* prev = NULL;

        while (current != NULL) {
            if (strcmp(current->code, L.code) == 0) {
                if (prev == NULL) {
                    D[i] = current->next;
                } else {
                    prev->next = current->next;
                }
                free(current);
                printf("Locker with code %s deleted.\n", L.code);
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    printf("Locker with code %s not found.\n", L.code);
}

bool isMember(Dictionary D, Locker L){
    for(int i = 0; i < MAX; i++){
        Locker* current = D[i];
        while(current != NULL){
            if(strcmp(current->code, L.code) == 0){
                return true;
            }
            current = current->next;
        }
    }
    return false;
}

void display(Dictionary D){
    for(int i = 0; i < MAX; i++){
        printf("[%d]: ", i);
        if(D[i] == NULL){
            printf("Empty.\n");
        } else {
            Locker* current = D[i];
            while(current != NULL){
                printf("%d, %s, %s, %d -> ",
                current->lockerID, current->owner, current->code, current->isActive);
                current = current->next;
            }
            printf("NULL\n");
        }
    }
}

void deleteDict(Dictionary D){
    for(int i = 0; i < MAX; i++){
        Locker* current = D[i];
        while(current != NULL){
            Locker* next = current->next;
            free(current);
            current = next;
        }
    }
}
