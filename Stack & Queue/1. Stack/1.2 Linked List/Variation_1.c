#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Stack* initialize();
bool isFull(Stack* s);
bool isEmpty(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
void display(Stack* s);

int main () {

    Stack* s = initialize();
        int num, choice;
    do{
        printf("\nMenu:\n[1]: Push\n[2]: Pop\n[3]: Peek\n[4]: Display\n[0]: Exit\n");
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
    newStack->top = NULL;
    return newStack;
}

bool isFull(Stack* s){
    return false;
}

bool isEmpty(Stack* s){
    return (s->top == NULL);
}

void push(Stack* s, int value){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty.\n");
        return -1;
    }

    Node* temp = s->top;
    int value = s->top->data;
    s->top = s->top->next;
    free(temp);

    return value;
}

int peek(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty.\n");
        return -1;
    }
    return s->top->data;
}

void display(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty.\n");
        return;
    }

    Node* temp = s->top;
    printf("top -> ");
    for(int i = 0; temp != NULL; i++){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

