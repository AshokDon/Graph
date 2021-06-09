#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool checkcycle(int s,int n,vector<int>adj[],vector<int>&vis)
{
    queue<pair<int,int>>q;
    q.push({s,-1});
    vis[s]=1;
    while(!q.empty())
    {
        auto it=q.front();
        int node=it.first;
        int pre=it.second;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                q.push({it,node});
                vis[it]=1;
            }
            else if(it!=pre)
            {
                return true;
            }
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
	        if(checkcycle(i,n,adj,vis))
	        {
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
