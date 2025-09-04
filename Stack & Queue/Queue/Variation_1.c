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
    push(S, 1);
    push(S, 3);
    push(S, 2);
    push(S, 5);
    display(S);
    push(S, 4);

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

    int value = stackPtr->items[stackPtr->top];  
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
    printf("items: [");
    for(i = stackPtr->top; i >= 0; i--){
        printf("%d", stackPtr->items[i]);
        if(i > 0){
            printf(", ");
        }
    }
    printf("]\n");

    printf("top: %d", stackPtr->top);
}

