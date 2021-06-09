#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool checkcycledfs(int node,vector<int>&dfsvis,vector<int>adj[],vector<int>&vis)
{
    vis[node]=1;
    dfsvis[node]=1;
    for(auto it:adj[node])
    {
       if(vis[it]==0)
       {
           if(checkcycledfs(it,dfsvis,adj,vis)) return true;
       }
       else if(dfsvis[it]==1){
           cout<<"hi";
           return true;
       }
        dfsvis[node]=0;
    }
   
    return false;
}
int main() {
	int n,m;
	cin>>n>>m;
	vector<int>adj[n+1];
	for(int i=0;i<m;i++)
	{
	    int u,v;
	    cin>>u>>v;
	    adj[u].push_back(v);
	    //adj[v].push_back(u);
	}
	vector<int>vis(n+1,0);
	vector<int>dfsvis(n+1,0);
	int cycle=0;
	for(int i=1;i<=n;i++)
	{
	    if(!vis[i])
	    {
	        if(checkcycledfs(i,dfsvis,adj,vis))
	        {
	            cout<<"hi";
	            cycle=1;
	            break;
	        }
	    }
	}
	if(cycle){
	    cout<<"yes";
	}
	else{
	    cout<<"No";
	}
	return 0;
}