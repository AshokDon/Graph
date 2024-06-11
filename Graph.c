//
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Graph{
    int numVertices;
    struct Node** adjList;
};
struct Graph* CreatAGraph(int vertices){
    struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjList = (struct Node**)malloc(vertices * sizeof(struct Node*));
    for(int i = 0; i < vertices; i++){
        graph->adjList[i] = NULL;
    }
    return graph;
    
}
struct Node* creatANode(int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdges(struct Graph *graph, int u, int v){
    //adding u -> v
    struct Node *newNode = creatANode(v);
    newNode->next = graph->adjList[u];
    graph->adjList[u] = newNode;

    //adding v -> u
    newNode = creatANode(u);
    newNode->next = graph->adjList[v];
    graph->adjList[v] = newNode;

}
void PrintTheGraph(struct Graph *graph){
    for(int i = 0; i < graph->numVertices; i++){
        struct Node *temp = graph->adjList[i];
        printf("The Adjacency List of vertex %d\n",i);
        while(temp){
            printf("%d -> ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    int numVertices , numEges; // n --> no of nodes , e --> no of edges
    scanf("%d %d",&numVertices,&numEges);
    struct Graph *graph = CreatAGraph(numVertices);
    for(int i = 0 ; i < numEges ; i++){
        int u , v;
        scanf("%d %d",&u,&v);
        addEdges(graph,u,v);
    }
    PrintTheGraph(graph);
    
}
