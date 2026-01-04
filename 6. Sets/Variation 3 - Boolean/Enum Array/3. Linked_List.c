#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 8

typedef struct Node {
    int elem;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} Set;

/* Prototypes with parameters*/
void initialize(Set *set);
void insert(Set *set, int element);
void delete(Set *set, int element);
bool find(Set set, int element);
void set_union(Set A, Set B, Set *C);
void intersection(Set A, Set B, Set *C);
void difference(Set A, Set B, Set *C);
void display(Set set);
void destroy(Set *set);

int main() {
    Set A, B, C;

    initialize(&A);
    initialize(&B);
    initialize(&C);

    insert(&A, 0);
    insert(&A, 2);
    insert(&A, 7);

    insert(&B, 2);
    insert(&B, 4);
    insert(&B, 5);

    printf("Set A = ");
    display(A);
    printf("Set B = ");
    display(B);

    printf("Find: ");
    bool found = find(B, 5);
    if (found) {
        printf("Element is found\n");
    } else {
        printf("Element is not found\n");
    }

    printf("Union A, B is Set C = ");
    set_union(A, B, &C);
    display(C);

    printf("Intersection A, B is Set C = ");
    intersection(A, B, &C);
    display(C);

    printf("Difference A, B is Set C = ");
    difference(A, B, &C);
    display(C);

    destroy(&A);
    destroy(&B);
    destroy(&C);

    return 0;
}

/* Clear the set (free everything) */
void initialize(Set *set) {
    set->head = NULL;
}

/* Insert element */
void insert(Set *set, int element) {
    if (element < 0 || element >= ARRAY_SIZE) {
        printf("Error: element %d out of range (0-7)\n", element);
        return;
    }

    Node **trav = &set->head;

    // find position (sorted ascending)
    while (*trav != NULL && (*trav)->elem < element) {
        trav = &(*trav)->next;
    }

    // already present => do nothing
    if (*trav != NULL && (*trav)->elem == element) return;

    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return;

    newNode->elem = element;
    newNode->next = *trav;
    *trav = newNode;
}

/* Delete element if present */
void delete(Set *set, int element) {
    if (element < 0 || element >= ARRAY_SIZE) {
        printf("Error: element %d out of range (0-7)\n", element);
        return;
    }

    Node **trav = &set->head;

    while (*trav != NULL && (*trav)->elem != element) {
        // early stop if sorted and current > element
        if ((*trav)->elem > element) return;
        trav = &(*trav)->next;
    }

    if (*trav != NULL) {
        Node *temp = *trav;
        *trav = temp->next;
        free(temp);
    }
}

bool find(Set set, int element) {
    if (element < 0 || element >= ARRAY_SIZE) return false;

    Node *cur = set.head;
    while (cur != NULL) {
        if (cur->elem == element) return true;
        if (cur->elem > element) return false;
        cur = cur->next;
    }
    return false;
}

void set_union(Set A, Set B, Set *C) {
    destroy(C);
    initialize(C);

    for (Node *p = A.head; p != NULL; p = p->next) insert(C, p->elem);
    for (Node *q = B.head; q != NULL; q = q->next) insert(C, q->elem);
}

void intersection(Set A, Set B, Set *C) {
    destroy(C);
    initialize(C);

    for (Node *p = A.head; p != NULL; p = p->next) {
        if (find(B, p->elem)) insert(C, p->elem);
    }
}

void difference(Set A, Set B, Set *C) {
    destroy(C);
    initialize(C);

    for (Node *p = A.head; p != NULL; p = p->next) {
        if (!find(B, p->elem)) insert(C, p->elem);
    }
}

void display(Set set) {
    // bits
    printf("[");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d", find(set, i) ? 1 : 0);
        if (i != ARRAY_SIZE - 1) printf(", ");
    }
    printf("] ");

    // elems
    printf("{");
    bool first = true;
    for (Node *cur = set.head; cur != NULL; cur = cur->next) {
        if (!first) printf(", ");
        printf("%d", cur->elem);
        first = false;
    }
    printf("}\n");
}

/* Free all nodes */
void destroy(Set *set) {
    Node *cur = set->head;
    while (cur != NULL) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
    set->head = NULL;
}
