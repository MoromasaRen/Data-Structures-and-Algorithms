#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// Define the structure of a tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node, *NodePTR;

typedef NodePTR Tree[MAX];

/* ===== PROTOTYPES ===== */
void initializeTree(Tree* T);
NodePTR createNode(int data);
void insertTree(Tree* T, int data);
NodePTR deleteNode(NodePTR root, int data);
void deleteTree(Tree T);
NodePTR search(Tree T, int data);
// DFS
void Preorder(Tree T);
void Inorder(Tree T);
void Postorder(Tree T);
// BFS
void BFS(Tree T);

int main() {
    Tree T;
    initializeTree(&T);

    insertTree(&T, 50);
    insertTree(&T, 30);
    insertTree(&T, 70);
    insertTree(&T, 20);
    insertTree(&T, 40);
    insertTree(&T, 60);
    insertTree(&T, 80);

    printf("Preorder: ");
    Preorder(T);

    printf("Inorder: ");
    Inorder(T);

    printf("Postorder: ");
    Postorder(T);

    printf("BFS: ");
    BFS(T);

    int key = 60;
    printf("Search %d: %s\n", key, search(T, key) ? "FOUND" : "NOT FOUND");

    printf("\nDelete 70\n");
    T[0] = deleteNode(T[0], 70);

    printf("Inorder after delete: ");
    Inorder(T);

    deleteTree(T);
    printf("BFS after deleteTree: ");
    BFS(T);

    return 0;
}


void initializeTree(Tree* T) {
    for (int i = 0; i < MAX; i++) {
        (*T)[i] = NULL;
    }
}

NodePTR createNode(int data) {
    NodePTR n = (NodePTR)malloc(sizeof(Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void insertTree(Tree* T, int data) {
    NodePTR newNode = createNode(data);

    if ((*T)[0] == NULL) {
        (*T)[0] = newNode;
        return;
    }

    NodePTR cur = (*T)[0];
    NodePTR parent = NULL;

    while (cur != NULL) {
        parent = cur;
        if (data < cur->data)
            cur = cur->left;
        else if (data > cur->data)
            cur = cur->right;
        else
            return;
    }

    if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
}

NodePTR search(Tree T, int data) {
    NodePTR cur = T[0];
    while (cur != NULL) {
        if (cur->data == data) return cur;
        if (data < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }
    return NULL;
}

NodePTR deleteNode(NodePTR root, int data) {
    if (root == NULL) return NULL;

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } 
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } 
    else {
        // Case 1 & 2: 0 or 1 child
        if (root->left == NULL) {
            NodePTR temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            NodePTR temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: two children
        NodePTR succParent = root;
        NodePTR succ = root->right;

        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }

        root->data = succ->data;

        if (succParent->left == succ)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;

        free(succ);
    }
    return root;
}

void deleteTree(Tree T) {
    if (T[0] == NULL) return;

    NodePTR stack[MAX];
    int top = -1;

    stack[++top] = T[0];

    while (top >= 0) {
        NodePTR cur = stack[top--];
        if (cur->left) stack[++top] = cur->left;
        if (cur->right) stack[++top] = cur->right;
        free(cur);
    }
    T[0] = NULL;
}

void Preorder(Tree T) {
    if (T[0] == NULL) {
        printf("(empty)\n");
        return;
    }

    NodePTR stack[MAX];
    int top = -1;
    stack[++top] = T[0];

    while (top >= 0) {
        NodePTR cur = stack[top--];
        printf("%d ", cur->data);
        if (cur->right) stack[++top] = cur->right;
        if (cur->left) stack[++top] = cur->left;
    }
    printf("\n");
}

void Inorder(Tree T) {
    NodePTR stack[MAX];
    int top = -1;
    NodePTR cur = T[0];

    while (cur != NULL || top >= 0) {
        while (cur != NULL) {
            stack[++top] = cur;
            cur = cur->left;
        }
        cur = stack[top--];
        printf("%d ", cur->data);
        cur = cur->right;
    }
    printf("\n");
}

void Postorder(Tree T) {
    if (T[0] == NULL) {
        printf("(empty)\n");
        return;
    }

    NodePTR stack1[MAX], stack2[MAX];
    int top1 = -1, top2 = -1;

    stack1[++top1] = T[0];

    while (top1 >= 0) {
        NodePTR cur = stack1[top1--];
        stack2[++top2] = cur;

        if (cur->left) stack1[++top1] = cur->left;
        if (cur->right) stack1[++top1] = cur->right;
    }

    while (top2 >= 0) {
        printf("%d ", stack2[top2--]->data);
    }
    printf("\n");
}

void BFS(Tree T) {
    if (T[0] == NULL) {
        printf("(empty)\n");
        return;
    }

    NodePTR queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = T[0];

    while (front < rear) {
        NodePTR cur = queue[front++];
        printf("%d ", cur->data);

        if (cur->left) queue[rear++] = cur->left;
        if (cur->right) queue[rear++] = cur->right;
    }
    printf("\n");
}