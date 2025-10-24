#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function Prototypes
Queue* initialize();
bool isEmpty(Queue* q);
bool isFull(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
void enqueueSorted(Queue* q, int value);
void display(Queue* q);

int main (){

    Queue* q = initialize();
    
    enqueueSorted(q, 7);
    enqueueSorted(q, 2);
    enqueueSorted(q, 4);
    enqueueSorted(q, 1);
    enqueueSorted(q, 5);
    enqueueSorted(q, 6);
    enqueueSorted(q, 3);
    enqueueSorted(q, 5);
    display(q);
    return 0;
}

Queue* initialize(){
    Queue* newQueue = malloc(sizeof(Queue));
    newQueue->front = 0;
    newQueue->rear = -1;
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

void enqueueSorted(Queue* q, int value){
    if(isFull(q)){
        printf("Queue is full.\n");
        return;
    }

    Queue temp;
    temp.front = 0;
    temp.rear = -1;

    while(q->front != (q->rear + 1) % MAX && q->items[q->front] < value){
        enqueue(&temp, dequeue(q));
    }
    enqueue(&temp, value);
    while(q->front != (q->rear + 1) % MAX){
        enqueue(&temp, dequeue(q));
    }
    *q = temp;
}

void display(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return;
    }

    int count = (q->rear - q->front + MAX) % MAX + 1;

    for(int i = 0; i < count; i++){
        int index = (q->front + i) % MAX;
        printf("%d -> ", q->items[index]);
    }
    printf("End\n");
}

