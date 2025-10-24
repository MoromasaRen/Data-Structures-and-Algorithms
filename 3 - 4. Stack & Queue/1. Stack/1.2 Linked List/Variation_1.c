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

// Function Prototypes
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

// Functions
Stack* initialize(){
    /*
    Allocate memory for the stack structure
    Initialize the stack's top pointer to NULL
    Return the pointer to the stack
    */

    Stack* newStack = malloc(sizeof(Stack));
    newStack->top = NULL;
    return newStack;
}

bool isFull(Stack* s){
    // Return false (linked list can never be full)
    return false;
}

bool isEmpty(Stack* s){
    // The stack is empty if its top pointer is NULL
    return (s->top == NULL);
}

void push(Stack* s, int value){
    /*
    Allocate memory for a new node
    Set the data of the new node
    Link the new node to the current top of the stack
    Update the stack's top pointer to point to the new node
    */

    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack* s){
    /*
    Check if the stack is empty before attempting to pop
    Get a temporary pointer to the top node
    Store the data of the top node
    Move the top pointer to the next node
    Free the memory of the old top node using temp
    Return the stored value
    */

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
    /*
    Check if the stack is empty
    Return the data of the top node
    */

    if(isEmpty(s)){
        printf("Stack is empty.\n");
        return -1;
    }
    return s->top->data;
}

void display(Stack* s){
    /*
    Check if the stack is empty
    Create a temporary pointer to traverse the list
    Traverse the linked list and print each element's data
    */
   
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

