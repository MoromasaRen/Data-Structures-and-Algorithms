#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 9
#define VISITED -1
#define UNVISITED 100

typedef struct Node {
    int elem;
    struct Node* link;
} Node, *ptr;

typedef ptr Graph[MAX];
typedef int Vertex;

Node* createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->elem = data;
    newNode->link = NULL;
    return newNode;
}

void initGraph(Graph G) {
    for(int i = 0; i < MAX; i++){
        G[i] = NULL;
    }
}

void addEdge(Graph G, Vertex src, Vertex dest){
    Node* newNode = createNode(dest);
    newNode->link = G[src];
    G[src] = newNode;

    newNode = createNode(src);
    newNode->link = G[dest];
    G[dest] = newNode;

}

void dfs(Graph G, Vertex V, int mark[3]) {
    Node* current = G[V];

    mark[V] = VISITED;
    printf("Visited: %d\n", V);

    while(current != NULL){
        Vertex neighbor = current->elem;

        if(mark[neighbor] == UNVISITED){
            dfs(G, neighbor, mark);
        }
        current = current->link;
    }
}

int main() {
    Graph myGraph;
    initGraph(myGraph);

    addEdge(myGraph, 0, 1);
    addEdge(myGraph, 0, 2);
    addEdge(myGraph, 1, 3);
    addEdge(myGraph, 1, 4);
    addEdge(myGraph, 2, 4);

    int visited_status[MAX];
    for (int i = 0; i < MAX; i++) {
        visited_status[i] = UNVISITED;
    }

    printf("Depth First Traversal starting from vertex 0:\n");
    dfs(myGraph, 0, visited_status);

    return 0;
}