#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct DSU{
    vector<int>parent;
    DSU(int val){
        parent.resize(val+2);
        iota(parent.begin(),parent.end(),0);
    }
    int get(int x){
        return (x == parent[x] ? x : parent[x]=get(parent[x]));
    }
    void Union(int x, int y){
        x = get(x);
        y = get(y);
        if(x!=y){
            parent[x] = max(parent[x],parent[y]);
            parent[y] = max(parent[x], parent[y]);
        }
        for(int i = x ; i <= y ; i++){
            cout<<i<<" "<<parent[i]<<endl;
        }
    }
};
int main(){
    
        ll n , q;
        cin >> n >> q;
        DSU G(n);
        vector<ll>l(q),r(q),c(q);
        vector<ll>color(n+2,0);
        for(int i = 0 ; i < q  ; i++){
            cin >> l[i] >> r[i] >> c[i];
        }
        for(int i = q - 1 ; i >= 0 ; i--){
            int idx = G.get(l[i]);
            while(idx <= r[i]){
                color[idx] = c[i];
                G.Union(idx,idx+1);
                idx = G.get(idx);
            }
        }
        for(int i  = 1 ; i <= n ; i++){
            cout<<color[i]<<" ";
        }
        cout<<endl;
        // for(int i = 1 ; i <= n ; i++){
        //     cout<<G.parent[i]<<" ";
        // }
        
        
    

}
