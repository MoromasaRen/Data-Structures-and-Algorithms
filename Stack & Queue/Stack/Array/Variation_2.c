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
bool isEmpty(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
int top(Stack* s);
void display(Stack* s);

int main (){

    Stack *s = initialize();
    int num, choice;
    do{
        printf("\nMenu:\n[1]: Push\n[2]: Pop\n[3]: Peek\n[4]: Top\n[5]: Display\n[0]: Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("Enter a number: ");
                scanf("%d", &num);
                push(s, num);
                break;
            case 2:
                num = pop(s);
                if(num != -1){
                    printf("%d popped\n", num);
                }
                break;
            case 3:
                if(!isEmpty(s)){
                    printf("Top element is %d\n", peek(s));
                } else {
                    printf("Stack is empty.\n");
                }
                break;
            case 4:
                int topval = top(s);
                printf("Top Value = %d\n", topval);
            case 5:
                display(s);
                break;
            case 0:
                printf("Exiting...");
                free(s);
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    } while(choice != 0);
    return 0;

}

Stack* initialize(){
    Stack* newStack = malloc(sizeof(Stack));
    newStack->top = MAX;
    return newStack;
}

bool isFull(Stack* s){
    return (s->top == 0) ? true : false;
}

bool isEmpty(Stack* s){
    return (s->top == MAX) ? true : false;
}

void push(Stack* s, int value){
    if(isFull(s)){
        printf("Stack is full.\n");
    }
    s->top--;
    s->items[s->top] = value;
}

int pop(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty.\n");
        return -1;
    }

    int value = s->items[s->top];
    s->top++;
    return value;
}

int peek(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty.\n");
        return 1;
    }

    return s->items[s->top];

}

int top(Stack* s){
    return s->top;
}

void display(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty.\n");
        return;
    }
    int i;
    printf("items: [");
    for(i = s->top; i < MAX; i++){
        printf("%d", s->items[i]);
        if(i < MAX - 1){
            printf(", ");
        }
    }
    printf("]\n");
    printf("top = %d\n", s->top);
}