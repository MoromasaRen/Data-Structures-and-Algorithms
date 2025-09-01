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

List initialize(List L);
List empty(List list);
List insertFirst(List list, int data);
List insertLast(List list, int data);
List insertPos(List list, int data, int index);
List deleteStart(List list);
List deleteLast(List list);
List deletePos(List list, int index);
int retrieve(List list, int index);
int locate(List list, int data);
void display(List list);

