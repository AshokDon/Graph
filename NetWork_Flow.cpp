#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;


bool BFS(vector<vector<ll>>&RCgraph, int source, int sink, int n, vector<ll>&parent){
    vector<bool>visited(n,0);
    visited[source] = 1;
    queue<ll>Q;
    Q.push(source);
    bool foundAugmentedPath = false;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(int v = 0 ; v < n ; v++){
            if(!visited[v] and RCgraph[u][v] > 0){
                parent[v] = u;
                visited[v] = 1;
                Q.push(v);
                if(v==sink){
                    foundAugmentedPath = true;
                    break;
                }
            } 
        }
    }


    return foundAugmentedPath;

}
void PrintAlltheAugmentPaths(vector<vector<ll>>&RCgraphs){
    for(int i = 0 ; i < RCgraphs.size() ; i++){
        for(int j = 0 ; j < RCgraphs[i].size(); j++){
            cout<<RCgraphs[i][j]<<" ";
        }
        cout<<endl;
    }
}
ll Max_Flow(vector<vector<ll>>&graph, int source, int sink, int v){
    vector<vector<ll>>RCgraph(graph);
    vector<ll>parent(1001,0);
    vector<vector<ll>>AugmentPaths;
    ll max_flow = 0;
    while(BFS(RCgraph, source, sink, v, parent)){
        vector<ll>CurrAugPath;
        ll flow = INT_MAX;
        ll v = sink;
        while(v!=source){
            CurrAugPath.pb(v);
            ll u = parent[v];
            if(flow > RCgraph[u][v]){
                flow = RCgraph[u][v];
            }
            v = u;
        }
        CurrAugPath.pb(source);
        reverse(CurrAugPath.begin(),CurrAugPath.end());
        AugmentPaths.pb(CurrAugPath);
        max_flow+=flow;
        v = sink;
        while(v!=source){
            ll u = parent[v];
            RCgraph[u][v]-=flow;
            RCgraph[v][u]+=flow;
            v = u;
        }
    }
    PrintAlltheAugmentPaths(AugmentPaths);
    return max_flow;
}
int main(){
    ll n , e;
    cin >> n >> e;
    vector<vector<ll>>graph(n,vector<ll>(n,0));
    for(int i = 0 ; i < e ; i++){
        int u, v, c;
        cin >> u >> v >> c;
        graph[u][v] = c;
    }
    ll ans = Max_Flow(graph,0,1,n);
    cout<<ans<<endl;
}
