#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool checkcycledfs(int node,int parent,vector<int>adj[],vector<int>&vis)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(vis[it]==0)
        {
            if(checkcycledfs(it,node,adj,vis))
            {
                return true;
            }
        }
        else if(it!=parent)
        {
            return true;
        }
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
	    adj[v].push_back(u);
	}
	vector<int>vis(n+1,0);
	int cycle=0;
	for(int i=1;i<=n;i++)
	{
	    if(!vis[i])
	    {
	        if(checkcycledfs(i,-1,adj,vis))
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