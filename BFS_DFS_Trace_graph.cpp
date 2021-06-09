#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>adj[1000005];
int vis[1000005];
void bfs(int node)
{
    queue<int>q;
    q.push(node);
    vis[node]=1;
    while(!q.empty())
    {
        node=q.front();
        q.pop();
        cout<<node<<" ";
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                q.push(it);
                vis[it]=1;
            }
        }
        
    }
    
}
void dfs(int node)
{
    cout<<node<<" ";
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it);
        }
    }
}
int main() {
	int n,m;
	cin>>n>>m;
	//using adjucent matrix
	
	//using adjucent list 
	
	for(int i=0;i<m;i++)
	{
	    int u,v;
	    cin>>u>>v;
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
	    if(!vis[i])
	    {
	        dfs(i);
	    }
	}
	return 0;
}