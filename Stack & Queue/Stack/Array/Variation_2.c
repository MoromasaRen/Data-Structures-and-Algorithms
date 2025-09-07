#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int top;
} Stack;

Stack* initialize();
bool isFull(Stack* s);
void isEmpty(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
void display(Stack* s);


int main (){

    Stack *S = initialize();
    push(S, 1);
    push(S, 3);
    push(S, 2);
    push(S, 5);
    display(S);

    return 0;
}

Stack* initialize(){
    Stack* newStack = malloc(sizeof(Stack));
    newStack->top = MAX;
    return newStack;
}

bool isFull(Stack* s){
    if(s->top == 0){
        printf("Stack is full.");
        return -1;
    }
    return 0;
}

void isEmpty(Stack* s){
    if(s->top == MAX){
        printf("Stack is empty.");
    }
}

void push(Stack* s, int value){
    if(s->top == 0){
        printf("Stack is full.");
        return;
    }
    s->top--;
    s->items[s->top] = value;
}

int pop(Stack* s){
    if(s->top == MAX){
        printf("Stack is empty.");
        return -1;
    }
    int value = s->items[s->top];
    s->top++;
    return value;

}

int peek(Stack* s){
    if(s->top == MAX){
        printf("Stack is empty.");
        return -1;
    }
    return s->items[s->top];

}

void display(Stack* s){
    if(s->top == MAX){
        printf("Stack is empty.");
        return;
    }
    printf("items: [");
    int i;
    for(i = s->top; i < MAX; i++){
        printf("%d", s->items[i]);
        if(i < MAX - 1){
            printf(", ");
        }
    }
    printf("]\n");
    printf("top = %d\n", s->top);
    
}