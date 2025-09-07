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
    if(q->list.count == MAX){
        printf("Queue is full.");
        return 1;
    }
    return -1;
}

bool isEmpty(Queue* q){
    if(q->list.count == 0){
        printf("Queue is empty.");
        return 1;
    }
    return -1;
}

void enqueue(Queue* q, int value){
    if(q->list.count == MAX){
        printf("Queue is full.");
    }
    if(q->list.count == 0){
        q->front = 0;
        q->rear = 0;
    } else {
        int i;
        for(i = 0; i q->list.count; i++){
            
        }
    }
}

int dequeue(Queue* q){

}

int front(Queue* q){

}

void display(Queue* q){

}