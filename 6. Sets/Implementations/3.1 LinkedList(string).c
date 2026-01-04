#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char String[30];
typedef struct Node {
    String spell;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
}Set;

// Create a new empty set
Set* createSet();

// Add a spell to the set (no duplicates)
bool addSpell(Set* set, String spell);

// Remove a spell from the set
bool removeSpell(Set** set, String spell);

// Check if a spell exists in the set
bool containsSpell(Set* set, String spell);

// Print all spells in the set
void printSet(Set* set);

// Free all memory associated with the set
void destroySet(Set* set);

Set* unionSets(Set* set1, Set* set2);
Set* intersectSets(Set* set1, Set* set2);

int main() {
    String spell;
    Set* fireSpells = createSet();
    Set* waterSpells = createSet();

	strncpy(spell,"Flame Burst",12);
	spell[11]='\0';
	addSpell(fireSpells, spell);

	strncpy(spell,"Inferno",8);
	spell[7]='\0';
	addSpell(fireSpells, spell);

	strncpy(spell,"Aqua Jet",9);
	spell[8]='\0';
	addSpell(waterSpells, spell);

	strncpy(spell,"Inferno",8);
	spell[7]='\0';
	addSpell(waterSpells, spell);

	Set* commonSpells = intersectSets(fireSpells, waterSpells);
	Set* allSpells = unionSets(fireSpells, waterSpells);

	printf("Common Spells:\n");
	printSet(commonSpells);

	printf("\nAll Spells:\n");
	printSet(allSpells);

	strncpy(spell,"Aqua Jet",9);
	spell[8]='\0';
	removeSpell(&allSpells,spell);

	printf("\nAll Spells:\n");
	printSet(allSpells);

	destroySet(fireSpells);
	destroySet(waterSpells);
	destroySet(commonSpells);
	destroySet(allSpells);

return 0;
}

// write your functions here...
// Create a new empty set
Set* createSet(){
    Set *set = malloc(sizeof(Set));
    set->head = NULL;
    set->size = 0;
    return set;
}

// Add a spell to the set (no duplicates)
bool addSpell(Set* set, String spell){
    Node* newNode = malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory Allocation Failed.\n");
        return false;
    }
    strcpy(newNode->spell, spell);
    newNode->next = NULL;
    if(newNode == NULL){
        printf("Invalid.\n");
        return false;
    }
    
    if(containsSpell(set, spell)){
        printf("Spell is already in book.\n");
        return false;
    }
    strcpy(newNode->spell, spell);
    newNode->next = set->head;
    set->head = newNode;
    set->size++;
    return true;
}

// Remove a spell from the set
bool removeSpell(Set** set, String spell){
    Node* temp = (*set)->head;
    Node* prev = NULL;
    
    while(temp != NULL && strcmp(temp->spell, spell) != 0){
        prev = temp;
        temp = temp->next;
    }
    
    if(temp == NULL) return false;
    
    if(prev == NULL){
        (*set)->head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

// Check if a spell exists in the set
bool containsSpell(Set* set, String spell){
    Node* trav = set->head;
    while(trav != NULL){
        if(strcmp(trav->spell, spell) == 0)
            return true;
        trav = trav->next;
    }
    return false;
}

// Print all spells in the set
void printSet(Set* set){
    Node* current = set->head;
    for(int i = 1; current != NULL; current = current->next){
        printf("  %d. %s\n", i++, current->spell);
    }
}

// Free all memory associated with the set
void destroySet(Set* set){
    Node* current = set->head;
    while(current != NULL){
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(set);
}

Set* unionSets(Set* set1, Set* set2){
    Set* result = createSet();
    Node* temp = set1->head;
    while(temp != NULL){
        addSpell(result, temp->spell);
        temp = temp->next;
    }
    
    temp = set2->head;
    while(temp != NULL){
        if(!containsSpell(result, temp->spell)){
        addSpell(result, temp->spell);
        }
        temp = temp->next;
    }
    return result;
    
}

Set* intersectSets(Set* set1, Set* set2){
    Set* result = createSet();
    Node* temp = set1->head;
    while(temp != NULL){
        if(containsSpell(set2, temp->spell)){
            addSpell(result,temp->spell);
        }
        temp = temp->next;
    }
    return result;
}