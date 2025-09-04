#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int top;
} Stack;

Stack* initialize();
void push(Stack* stackPtr, int value);
int pop(Stack* stackPtr);
int peek(Stack* stackPtr);
void display(Stack* stackPtr);

int main (){

    Stack *S = initialize();

    
    return 0;
}

Stack* initialize(){
    Stack* newStack = malloc(sizeof(Stack));
    newStack->top = -1;
    return newStack;
}

void push(Stack* stackPtr, int value){
    if(stackPtr->top == MAX - 1){
        printf("Stack is full.");
        return;
    } 
    stackPtr->top++;
    stackPtr->items[stackPtr->top] = value;

}

int pop(Stack* stackPtr){
    if(stackPtr->top == -1){
        printf("Stack is empty.");
        return -1;
    }

    int value = stackPtr->top;  
    stackPtr->top--;
    return value;
}

int peek(Stack* stackPtr){
    if(stackPtr->top == -1){
        printf("Stack is empty.");
        return -1;
    }
    return stackPtr->items[stackPtr->top];

}

void display(Stack* stackPtr){
    if(stackPtr->top == -1){
        printf("Stack is empty.");
        return;
    }

    int i;
    for(i = stackPtr->top; i > stackPtr->top; i--){
        printf("items: [ %d, ", stackPtr->items)
    }
}

