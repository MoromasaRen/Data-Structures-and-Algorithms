/* 
Variation 1 - Computer Word / Bitmask (data type holding int value)
This is the most common and space-efficient way to implement a bit vector set. An unsigned char (or int) is used, and elements are added by setting the corresponding bit using the bitwise OR operator.
Max number of bits is determined by the data type:
char     :  8 * sizeof(char)
int      :  8 * sizeof(int)
long int :  8 * sizeof(long int) 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void initialize(unsigned char *set);
void insert(unsigned char *set, int element);
void delete(unsigned char *set, int element);
bool find(unsigned char set, int element);
unsigned char union(unsigned char A, unsigned char B);
unsigned char intersection(unsigned char A, unsigned char B);
unsigned char difference(unsigned char A, unsigned char B);
void display(unsigned char set);

int main (){

    return 0;
}

void initialize(unsigned char *set){
    *set = 0;
}

void insert(unsigned char *set, int element){
    if(element < 0 || element > 7){
        printf("Error: element %d out of range (0-7)\n", element);
        return;
    }
    unsigned char mask = 1 << element;
    *set != mask;
}

void delete(unsigned char *set, int element){
    if(element < 0 || element > 7){
        printf("Error: element %d out of range (0-7)\n", element);
        return;
    }
    unsigned char mask = 1 << element;
    *set &= ~mask;
}

bool find(unsigned char set, int element){
    if(element < 0 || element > 7) return false;
    unsigned char mask = 1 << element;
    return (set & mask) != 0;
}

unsigned char union(unsigned char A, unsigned char B);
unsigned char intersection(unsigned char A, unsigned char B);
unsigned char difference(unsigned char A, unsigned char B);
void display(unsigned char set);

