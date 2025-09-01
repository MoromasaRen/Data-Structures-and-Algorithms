#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *head;
    int count;
} List;

List* initialize();
void empty(List *list);
void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos(List *list, int data, int index);
void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);
int retrieve(List *list, int index);
int locate(List *list, int data);
void display(List *list);

int main (){

    List *list = initialize();
    insertFirst(list, 7);

    display(list);
    return 0;
}

List* initialize(){

    List *List = malloc(sizeof(List));
    if(List == NULL){
        printf("Memory Allocation Failed");
        return NULL;
    }
    List->head = NULL;
    List->count = 0;
    return List;

}

void empty(List *list){
    int i;
}

void insertFirst(List *list, int data){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->count++;
}

void display(List *list){
    List *trav = list;
    for(int i = 0; i < list->count; i++){
        printf("%d ", list->head->data);   
        trav->head = trav->head->next;
    }
}