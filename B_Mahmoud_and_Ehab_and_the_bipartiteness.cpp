#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

void dfs(int node,int color,vector<vector<int>>adj,vector<int>&visited){
    visited[node] = color;
    for(int neigh: adj[node]){
        if(visited[neigh]==-1) dfs(neigh,abs(color-1),adj,visited);
    }
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>>adj(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
    }
    vector<int>visited(n,-1);
    dfs(0,0,adj, visited);
    int x = accumulate(visited.begin(),visited.end(),0);
    //cout<<x<<endl;
    cout<< 1LL*x*(n-x) - (n-1)<<endl;
    return;
}

int main() {
    fastio;
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}