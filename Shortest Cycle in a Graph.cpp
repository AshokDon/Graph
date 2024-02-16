#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
int BFS(int node, vector<int>adj[], int n){
    queue<pair<int,int>>Q;//{node,parent}
    vector<bool>visited(n+1,false);
    vector<int>distance(n+1,INT_MAX);
    visited[node] = true;
    distance[node] = 0;
    Q.push(mp(node,-1));
    int res = INT_MAX;
    while(!Q.empty()){
        auto top = Q.front();
        Q.pop();
        node = top.first;
        int parent = top.second;
        for(auto nbr : adj[node]){
            if(!visited[nbr]){
                Q.push(mp(nbr,node));
                visited[nbr] = true;
                distance[nbr] = 1 + distance[node];
            }
            else{
                if(nbr!=parent){
                    res = min(res,distance[nbr]+distance[node]+1);
                }
            }
        }
    }
    return res;
}
int main(){
    int n , m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i = 0 ; i < m ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int LenghtofShortCycle = INT_MAX;
    for(int i = 0 ; i < n ; i++){
        LenghtofShortCycle = min(LenghtofShortCycle,BFS(i,adj,n));
    }
    if(LenghtofShortCycle == INT_MAX){
        cout<<-1<<endl;
    }
    else{
        cout<<LenghtofShortCycle<<endl;
    }


}
