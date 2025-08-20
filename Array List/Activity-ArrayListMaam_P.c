#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10

typedef struct {
    char elem[MAX];
    int count;
} charList;

bool findElem(charList L, char X);

int main (){

    charList L;
    strcpy(L.elem, "USC");
    int len = strlen(L.elem);
    L.count = len;
    
    if(findElem(L, 'X')){
        printf("The list is not empty and element X is in the list");
    } else if (L.count != 0){
        printf("The list is not empty and element X is not in the list");
    } else {
        printf("List is empty");
    }
    return 0;
}

bool findElem(charList L, char X){
    int i;
    for(i = 0; i < L.count && L.elem[i] != X; i++){}
    return (i < L.count) ? true : false;
}

