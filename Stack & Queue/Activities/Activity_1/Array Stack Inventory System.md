# Array Stack - Warehouse Inventory System  
*by Edwin Bartlett*

---

## Description

Design a C program for a simplified warehouse inventory management system.  
This system will track stacks of containers, adhering to specific storage and retrieval rules to manage space efficiently. The program will be interactive, allowing a user to manage the inventory through a simple menu.

---

## Key Features

- The system will use **three separate stacks** to store containers. Think of them as physical columns where containers are placed on top of one another.
- Each of the three stacks has a strict capacity limit of **5 containers**.
- When a user attempts to add a new container to a stack that is already full, the program must automatically switch to the **next available stack**. This process continues until all three stacks are full.
- Each container is uniquely identified by an integer ID. The program will not need to validate if these IDs are unique, but it should use this ID to perform operations like searching for a container.

---

## Constraints

You can only use the following functions to interact with the stacks. Place these in `arrayStack.h`:

```c
void initialize(Stack *s);
bool isFull(Stack *s);
bool isEmpty(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
int top(Stack *s);
void display(Stack* s);

Sample Output 1
--- Warehouse Inventory Management System ---
1. Push a container
2. Pop a container
3. Check if a container exists
4. Display all stacks
5. Exit
Enter your choice: 1
Enter container ID to push: 10
Container 10 pushed successfully.

--- Warehouse Inventory Management System ---
1. Push a container
2. Pop a container
3. Check if a container exists
4. Display all stacks
5. Exit
Enter your choice: 1
Enter container ID to push: 20
Container 20 pushed successfully.

--- Warehouse Inventory Management System ---
1. Push a container
2. Pop a container
3. Check if a container exists
4. Display all stacks
5. Exit
Enter your choice: 1
Enter container ID to push: 30
Container 30 pushed successfully.

--- Warehouse Inventory Management System ---
1. Push a container
2. Pop a container
3. Check if a container exists
4. Display all stacks
5. Exit
Enter your choice: 4

--- Stack 1 ---
30
20
10

--- Stack 2 ---
Stack is empty.

--- Stack 3 ---
Stack is empty.

--- Warehouse Inventory Management System ---
1. Push a container
2. Pop a container
3. Check if a container exists
4. Display all stacks
5. Exit
Enter your choice: 5
Exiting program.

Sample Output 2
--- Warehouse Inventory Management System ---
1. Push a container
2. Pop a container
3. Check if a container exists
4. Display all stacks
5. Exit
Enter your choice: 1
Enter container ID to push: 10
Container 10 pushed successfully.

--- Warehouse Inventory Management System ---
1. Push a container
2. Pop a container
3. Check if a container exists
4. Display all stacks
5. Exit
Enter your choice: 1
Enter container ID to push: 20
Container 20 pushed successfully.

--- Warehouse Inventory Management System ---
1. Push a container
2. Pop a container
3. Check if a container exists
4. Display all stacks
5. Exit
Enter your choice: 1
Enter container ID to push: 30
Container 30 pushed successfully.

--- Warehouse Inventory Management System ---
1. Push a container
2. Pop a container
3. Check if a container exists
4. Display all stacks
5. Exit
Enter your choice: 1
Enter container ID to push: 40
Container 40 pushed successfully.

--- Warehouse Inventory Management System ---
1. Push a container
2. Pop a container
3. Check if a container exists
4. Display all stacks
5. Exit
Enter your choice: 1
Enter container ID to push: 50
Container 50 pushed successfully.

--- Warehouse Inventory Management System ---
1. Push a container
2. Pop a container
3. Check if a container exists
4. Display all stacks
5. Exit
Enter your choice: 1
Enter container ID to push: 60
Container 60 pushed successfully.

--- Warehouse Inventory Management System ---
1. Push a container
2. Pop a container
3. Check if a container exists
4. Display all stacks
5. Exit
Enter your choice: 4

--- Stack 1 ---
50
40
30
20
10

--- Stack 2 ---
60

--- Stack 3 ---
Stack is empty.

--- Warehouse Inventory Management System ---
1. Push a container
2. Pop a container
3. Check if a container exists
4. Display all stacks
5. Exit
Enter your choice: 5
Exiting program.

Sample Output 3
--- Warehouse Inventory Management System ---
1. Push a container
2. Pop a container
3. Check if a container exists
4. Display all stacks
5. Exit
Enter your choice: 1
Enter container ID to push: 5
Container 5 pushed successfully.

--- Warehouse Inventory Management System ---
1. Push a container
2. Pop a container
3. Check if a container exists
4. Display all stacks
5. Exit
Enter your choice: 1
Enter container ID to push: 10
Container 10 pushed successfully.

--- Warehouse Inventory Management System ---
1. Push a container
2. Pop a container
3. Check if a container exists
4. Display all stacks
5. Exit
Enter your choice: 1
Enter container ID to push: 15
Container 15 pushed successfully.

--- Warehouse Inventory Management System ---
1. Push a container
2. Pop a container
3. Check if a container exists
4. Display all stacks
5. Exit
Enter your choice: 2
Container 15 popped successfully.

--- Warehouse Inventory Management System ---
1. Push a container
2. Pop a container
3. Check if a container exists
4. Display all stacks
5. Exit
Enter your choice: 4

--- Stack 1 ---
10
5

--- Stack 2 ---
Stack is empty.

--- Stack 3 ---
Stack is empty.

--- Warehouse Inventory Management System ---
1. Push a container
2. Pop a container
3. Check if a container exists
4. Display all stacks
5. Exit
Enter your choice: 5
Exiting program.