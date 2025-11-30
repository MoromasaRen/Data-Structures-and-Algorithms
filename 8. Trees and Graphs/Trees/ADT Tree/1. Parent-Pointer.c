#include <stdio.h>
#include <stdlib.h>
#define ROOT -1
#define DNE
typedef struct {

} Node;

// Operations
// Return Parent node of tree
int Parent(Tree T, Node N);
int LeftMost_Child(Tree T, Node N);
int Right_Sibling(Tree T, Node N);
int Label();
void create();
void root();
void initialize();
void makeNull();

