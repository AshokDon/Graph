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
void DFS(struct Graph *graph, int start, int visited[]){
    visited[start] = 1; // 3
    printf("%d",start); // 1 3
    struct Node *temp = graph->adjList[start]; //head -> start
    while(temp){
        if(!visited[temp->data]){
            DFS(graph,temp->data,visited);
        }
        temp = temp->next;
    }
}
void BFS(struct Graph *graph, int start, int visited[]){
    int queue[graph->numVertices]; //
    int front = 0 , rear = 0; //
    queue[rear] = start;
    rear++;
    visited[start] = 1;
    while(front < rear){
        int current = queue[front];
        printf("%d",current);//
        front++;//pop
        struct Node *temp = graph->adjList[current];
        while(temp){
            if(!visited[temp->data]){
                queue[rear] = temp->data;
                rear++;
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
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
    int visited[numVertices+1];
    for(int i = 0; i < numVertices; i++){
        visited[i] = 0;
    }
    //DFS(graph,1,visited);
    BFS(graph,1,visited);
    
}
