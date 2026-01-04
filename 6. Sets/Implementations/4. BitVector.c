#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BITS 8
#define TOTAL_BITS 10

typedef int Set[TOTAL_BITS];

Set* initSet();
void displayBits(Set set);
void displayElems(Set set);
void insertBit(Set *set, int pos);
void deleteBit(Set *set, int pos);
bool isMember(Set set, int data);
bool isSubset(Set A, Set B);
Set* Union(Set A, Set B);
Set* Intersection(Set A, Set B);
Set* Difference(Set A, Set B);

#define BYTES_NEEDED ((TOTAL_BITS + BITS - 1) / BITS)
static bool inRange(int pos) { return pos >= 0 && pos < TOTAL_BITS; }
static int byteIndex(int pos) { return pos / BITS; }
static int bitIndex(int pos)  { return pos % BITS; }

int main() {
    Set *A, *B, *C;

    A = initSet();
    B = initSet();

    insertBit(A, 8);
    insertBit(A, 6);
    insertBit(A, 4);
    insertBit(A, 2);
    insertBit(A, 0);

    insertBit(B, 9);
    insertBit(B, 7);
    insertBit(B, 4);
    insertBit(B, 2);
    insertBit(B, 1);

    printf("Set A\n");
    printf("Bits: ");
    displayBits(*A);
    printf("Elements: ");
    displayElems(*A);

    printf("\nSet B\n");
    printf("Bits: ");
    displayBits(*B);
    printf("Elements: ");
    displayElems(*B);

    printf("\nUnion of A, B\n");
    C = Union(*A, *B);
    printf("Bits: ");
    displayBits(*C);
    printf("Elements: ");
    displayElems(*C);
    free(C);

    printf("\nIntersection of A, B\n");
    C = Intersection(*A, *B);
    printf("Bits: ");
    displayBits(*C);
    printf("Elements: ");
    displayElems(*C);
    free(C);

    printf("\nDifference of A, B (A - B)\n");
    C = Difference(*A, *B);
    printf("Bits: ");
    displayBits(*C);
    printf("Elements: ");
    displayElems(*C);
    free(C);

    free(A);
    free(B);

    return 0;
}

Set* initSet() {
    Set *newSet = malloc(sizeof(Set));
    if (newSet == NULL) return NULL;

    for (int i = 0; i < TOTAL_BITS; i++) {
        (*newSet)[i] = 0;
    }
    return newSet;
}

void insertBit(Set *set, int pos) {
    if (set == NULL || !inRange(pos)) return;

    int b = byteIndex(pos);
    int k = bitIndex(pos);

    (*set)[b] |= (1u << k); 
}

void deleteBit(Set *set, int pos) {
    if (set == NULL || !inRange(pos)) return;

    int b = byteIndex(pos);
    int k = bitIndex(pos);

    (*set)[b] &= ~(1u << k);
}

bool isMember(Set set, int data) {
    if (!inRange(data)) return false;

    int b = byteIndex(data);
    int k = bitIndex(data);

    return (set[b] & (1u << k)) != 0;
}

bool isSubset(Set A, Set B) {
    for (int i = 0; i < BYTES_NEEDED; i++) {
        if ( (A[i] & ~B[i]) != 0 ) return false;
    }
    return true;
}

void displayBits(Set set) {
    for (int pos = 0; pos < TOTAL_BITS; pos++) {
        printf("%d ", isMember(set, pos) ? 1 : 0);
    }
    printf("\n");
}

void displayElems(Set set) {
    for (int pos = 0; pos < TOTAL_BITS; pos++) {
        if (isMember(set, pos)) printf("%d ", pos);
    }
    printf("\n");
}

Set* Union(Set A, Set B) {
    Set *result = initSet();
    if (result == NULL) return NULL;

    for (int i = 0; i < BYTES_NEEDED; i++) {
        (*result)[i] = A[i] | B[i];
    }
    return result;
}

Set* Intersection(Set A, Set B) {
    Set *result = initSet();
    if (result == NULL) return NULL;

    for (int i = 0; i < BYTES_NEEDED; i++) {
        (*result)[i] = A[i] & B[i];
    }
    return result;
}

Set* Difference(Set A, Set B) {
    Set *result = initSet();
    if (result == NULL) return NULL;

    for (int i = 0; i < BYTES_NEEDED; i++) {
        (*result)[i] = A[i] & ~B[i];
    }
    return result;
}
