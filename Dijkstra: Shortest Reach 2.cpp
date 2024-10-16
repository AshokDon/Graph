#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pb push_back
#define F first
#define S second
#ifndef ONLINE_JUDGE
/*============================Run Debug code =============================*/
#define debug(x) cerr << #x<<" " ; _print(x); cerr<<endl;
#else
#define debug(x)    
#endif
/*----------------------------------------------------------------------------*/
#define rep(i,a,b) for(int i = a ; i < b ; i++)
#define rrep(i,a,b) for(int i = a ; i >= b ;i--);
#define vi vector<ll>
#define StoB(A) sort(A.begin(),A.end())
#define BtoS(A) sort(A.rbegin(),A.rend())
using namespace std;
const int mod = (int)1e9 + 7;
vector<ll>bit;


/*===============================debugging templates ==============================================*/
template<class T>void _print(T a){cerr << a;}
template<class T> void _print(vector<T>v1){cerr<<"[";for(T i : v1)cerr<<i<<" ";cerr<<"]";}
template<class T> void _print(set<T>st){cerr <<"[" ; for(T i : st)cerr<<i<<" ";cerr<<"]";}
template<class T, class U> void _print(map<T,U>mp){for(T i : mp){cerr << i.F <<" : "<<i.S;}}
template<class T, class U> void _print(unordered_map<T,U>mp){for(T i : mp){cerr << i.F <<" : "<<i.S;}}


/*======================================MATHS================================================*/
ll gcd(ll x, ll y){
    if(y == 0)return x;
    else return gcd(y,x % y);
}
ll power(ll a, ll b){
    if(b == 0)return 1;
    ll x = power(a , b / 2);
    if(b % 2){
        return (x%mod*x%mod*a%mod) % mod;
    }
    else{
        return (x*x) % mod;
    }
}
ll inverse(ll a){
    return power(a,mod-2);
}
// NcR -> Primes ->

/*======================================================================================================================*/



void Don() {
    int n , m, scr;
    cin >> n >> m;
    vector<pair<int,int>>adj[n+1];
    for(int i = 0 ; i < m ; i++){
        int v , u , wt;
        cin >> v >> u >> wt;
        adj[u].pb({v,wt});
        adj[v].pb({u,wt});
    }
    cin >> scr;
    //min heap with pair {distance , node}
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>Q;
    Q.push({0,scr}); //{0,1};
    vi Distance(n+1,INT_MAX);
    //Distance[scr] = 0;
    
    vi vis(n+1,0);
    while(!Q.empty()){
        auto front = Q.top();
        Q.pop();
        int node = front.second;
        int d = front.first;
        for(auto nbr : adj[node]){
            if(vis[node] == 0 && Distance[nbr.first] > d + nbr.second){
                Distance[nbr.first] = d + nbr.second;
                Q.push({d+nbr.second, nbr.first});
            }
        }
        vis[node] = 1;
    }
    for(int i = 1 ; i <= n ; i++){
        if(scr==i)continue;
        else if(Distance[i]!=INT_MAX ) cout << Distance[i]<<" ";
        else cout << -1 <<" ";
    }
    cout << "\n";
    


}





int main(){
    #ifndef ONLINE_JUDGE

    freopen("Error.txt","w",stderr);
    #endif
    fast_io;
    ll t;
    cin >> t;
    while(t--)Don();
    
    
}

