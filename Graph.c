#include<stdio.h>
#define ll long long
#define TABLE_SIZE 10
//adjacency list

struct Node{
    int data;
    struct Node *next;
};

struct Graph{
    struct Node *head[TABLE_SIZE];
};

struct Node *Creat_A_Node(int val){
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->next = NULL;
    return node;
}
void insert(struct Graph *graph, int u, struct Node *V){
    struct Node *temp = graph->head[u];
    while(temp!=NULL){
        temp = temp->next;
    }
    temp = V;
}
void Creat_A_Graph(int n, int e){
    struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
    for(int i = 0; i < e ; i++){
        int u , v; 
        scanf("%d %d",&u,&v);
        //step 1 -> to creat two nodes U and V
        struct Node* U = Creat_A_Node(u);
        struct Node *V = Creat_A_Node(v);
        //insert v at u
        insert(graph,u,V);

        insert(graph,v,U);
    }
        
        
}

int main(){
    int n , e; // nodes , edges 
    scanf("%d %d",&n,&e);
    Creat_A_Graph(n,e);
}
