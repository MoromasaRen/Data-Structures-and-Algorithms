#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
char elem;
struct Node *link;
}*charList; //List datatype

void populateList (charList *List, char X);
bool findElem (charList *List, char X);

int main (){

    charList List = NULL;
    populateList(&List, 'U');
    populateList(&List, 'S');
    populateList(&List, 'C');

    if(List != NULL){
        bool result = findElem(&List, 'U');
            if(result){
                printf("The list is not empty and element X is in the list");
            } else {
                printf("the list is not empty and element X is not in the list");
            }
    } else {
        printf("List is empty");
    }

    return 0;
}

void populateList (charList *List, char X){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->elem = X;
    newNode->link = *List;
    *List = newNode;
}

bool findElem (charList *List, char X){
    struct Node *trav = *List;
    bool found = false;
    while(trav != NULL){
        found = (trav->elem == X) ? true : found;
        trav = trav->link;
    }
    return found;
}