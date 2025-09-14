#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node *top;
    int front;
    int rear;
} Queue;

Queue* initialize();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int front(Queue* q);
void display(Queue* q);

int main (){

    Queue *q = initialize();
    int num, choice;
    do{
        printf("\nMenu:\n[1]: enqueue\n[2]: dequeue\n[3]: front\n[4]: Display\n[0]: Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("Enter a number: ");
                scanf("%d", &num);
                enqueue(q, num);
                break;
            case 2:
                num = dequeue(q);
                if(num != -1){
                    printf("%d dequeued\n", num);
                }
                break;
            case 3:
                if(!isEmpty(q)){
                    printf("front element is %d\n", front(q));
                } else {
                    printf("Queue is empty.\n");
                }
                break;
            case 4:
                display(q);
                break;
            case 0:
                printf("Exiting...");
                free(q);
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    } while(choice != 0);

    return 0;
}

Queue* initialize(){
    Queue* newQueue = malloc(sizeof(Queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
}

bool isFull(Queue* q){
    return false;
}

bool isEmpty(Queue* q){
    return (q->front == NULL);
}

void enqueue(Queue* q, int value){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->data = NULL;

    if(isEmpty(q)){
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear = newNode;
    }
    q->rear = newNode;
}

int dequeue(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return -1;
    }
    
    Node* temp = q->top;
    int value = q->top->data;
    q->front = temp->next;
    if(isEmpty(q)){
        q->rear = NULL;
    }
    free(temp);
    return value;
}

int front(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return -1;
    }
    return q->top->data;
}

void display(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return;
    }
    Node* temp = q->top;
    printf("front -> ");
    for(int i = 0; temp != NULL; i++){
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

