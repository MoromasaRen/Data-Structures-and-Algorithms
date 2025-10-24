#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int top;
} Stack;

// Function Prototypes
Stack* initialize();
bool isFull(Stack* s);
bool isEmpty(Stack* s);
void pushSorted(Stack* s, int value);
void display(Stack* s);

int main (){

    Stack* s = initialize();

    pushSorted(s, 7);
    pushSorted(s, 4);
    pushSorted(s, 2);
    pushSorted(s, 6);
    pushSorted(s, 1);
    display(s);
    return 0;
}

// Functions
Stack* initialize(){
    Stack* newStack = malloc(sizeof(Stack));
    newStack->top = -1;
    return newStack;
}

bool isFull(Stack* s){
    return (s->top == MAX - 1);
}
bool isEmpty(Stack* s){
    return (s->top == -1);
}

void push(Stack* s, int value){
    if(isFull(s)){
        printf("Stack is full.\n");
        return;
    }
    s->top++;
    s->items[s->top] = value;
}

int pop(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty.\n");
        return -1;
    }
    int value = s->items[s->top];
    s->top--;
    return value;
}

void pushSorted(Stack* s, int value){
    if(isFull(s)){
        printf("Stack is full.\n");
        return;
    }

    Stack* temp = initialize();
    while(!isEmpty(s) && s->items[s->top] > value){
        push(temp, pop(s));
    }

    push(s, value);

    while(!isEmpty(temp)){
        push(s, pop(temp));
    }
}

void display(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty.\n");
        return;
    }

    for(int i = s->top; i >= 0; i--){
        printf("%d\n", s->items[i]);
    }
}