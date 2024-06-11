#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Graph
struct Graph {
    int numVertices;
    struct Node** adjList;
};

//creating a graph with n vertices and making them null initially

struct Graph* CreatAGraph(int Vertices) {
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = Vertices;
    graph->adjList = malloc(Vertices * sizeof(struct Node*));
    for(int i = 0; i < Vertices; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}
//creat a node 
struct Node* CreatANode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
//add the edges
void addEdges(struct Graph *graph, int src, int dest) {
    struct Node *newNode = CreatANode(dest); // Create a node for destination
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = CreatANode(src); // Create a node for source
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void PrintTheGraph(struct Graph *graph) {
    for(int i = 0; i < graph->numVertices; i++) {
        struct Node *temp = graph->adjList[i];
        printf("The Adjacency List of vertex %d\n", i);
        while(temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int numVertices, numEdges;
    scanf("%d %d", &numVertices, &numEdges);
    struct Graph *graph = CreatAGraph(numVertices);

    for(int i = 0; i < numEdges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdges(graph, u, v);
    }

    PrintTheGraph(graph);

    
    return 0;
}
