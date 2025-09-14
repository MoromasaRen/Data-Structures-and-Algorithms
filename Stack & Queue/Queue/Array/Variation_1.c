#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int count;
} List;

typedef struct {
    List list;
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
    newQueue->list.count = 0;
    newQueue->front = -1;
    newQueue->rear = -1;
    return newQueue;
}

bool isFull(Queue* q){
    return (q->list.count == MAX);
}

bool isEmpty(Queue* q){
    return(q->list.count == 0);
}

void enqueue(Queue* q, int value){
    if(isFull(q)){
        printf("Queue is full.\n");
        return;
    }

    if(isEmpty(q)){
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX;
        q->list.items[q->rear] = value;
        q->rear++;
        q->list.count++;
    }
}

int dequeue(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return -1;
    }

    int value = q->list.items[q->front];
    if(isFull(q)){
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
        q->list.count--;
    }
    return value;
}

int front(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return -1;
    }
    return q->list.items[q->front];
}

void display(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return;
    }
    int i;
    printf("items: [");
    for(i = q->front; i < q->rear; i++){
        printf("%d", q->list.items[i]);
        if(i < 0){
            printf(", ");
        }
    }
    printf("]\n");
}