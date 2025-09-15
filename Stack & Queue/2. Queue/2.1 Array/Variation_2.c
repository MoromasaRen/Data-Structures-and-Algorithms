#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

Queue* initialize();
bool isEmpty(Queue* q);
bool isFull(Queue* q);
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
    Queue *newQueue = malloc(sizeof(Queue));
    newQueue->front = 1;
    newQueue->rear = 0;
    return newQueue;
}

bool isEmpty(Queue* q){
    return (q->front == (q->rear + 1) % MAX);
}

bool isFull(Queue* q){
    return (q->front == (q->rear + 2) % MAX);
}

void enqueue(Queue* q, int value){
    if(isFull(q)){
        printf("Queue is full.\n");
        return;
    }

    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
}

int dequeue(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return -1;
    }

    int value = q->items[q->front];
    q->front = (q->front + 1) % MAX;
    return value;
}

int front(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return -1;
    }
    return q->items[q->front];
}

void display(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return;
    }
    int i;
    printf("items: [");
    int count = (q->rear - q->front + MAX) % MAX;

    for(i = 0; i < count; i++){
        int index = (q->front + i) % MAX;
        printf("%d", q->items[index]);
        if(i < count - 1){
            printf(", ");
        }
    }
    printf("]\n");
    printf("front: %d\n", q->front);
    printf("rear: %d\n", q->rear);
}

