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
    void deleteFirst(List *list);
    void deleteLast(List *list);
    void deletePos(List *list, int index);
    int retrieve(List *list, int index);
    int locate(List *list, int data);
    void display(List *list);

    int main (){

        List *list = initialize();
        insertFirst(list, 7);
        insertLast(list, 8);

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

    void insertLast(List *list, int data){
        Node* newNode = malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;
        if(list->head == NULL){
            list->head = newNode;
            list->count++;
            return;
        }

        Node* current = list->head;
        while(current->next != NULL){
            current = current->next;
        }

        current->next = newNode;
        list->count++;

    }

    void insertPos(List *list, int data, int index){
        if(index > list->count){
            return;
        }
        if(index == 0){
            insertFirst(list, data);
            return;
        }
        if(index == list->count){
            insertLast(list, data);
            return;
        }
        
        Node* newNode = malloc(sizeof(Node));
        newNode->data = data;
        Node* current = list->head;
        for(int i = 0; i < index - 1 && current->next != NULL; i++){
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        list->count++;
    
    }

    void deleteFirst(List *list){
        Node* current = list->head;
        list->head = list->head->next;
        free(current);
        list->count--;
         
    }

    void deleteLast(List *list){
        if(list->count = 1){
            free(list->head);
            list->head = NULL;
        }
    }
    

    void display(List *list){
        List *trav = list;
        for(int i = 0; i < list->count; i++){
            printf("%d ", list->head->data);   
            trav->head = trav->head->next;
        }
    }