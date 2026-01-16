#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

const ll MOD = 998244353;


static vector<ll> g_a;
static vector<unordered_map<ll, vector<int>>> g_mp;
// memo[p] maps c -> count for ordered pair (p,c)
static vector<unordered_map<int, ll>> g_memo;

ll dfs(int p, int c){
    auto it = g_memo[p].find(c);
    if(it!=g_memo[p].end()) return it->second;
    ll need = g_a[p] + g_a[c];
    ll res = 1 % MOD;
    auto it2 = g_mp[c].find(need);
    if(it2!=g_mp[c].end()){
        for(int w: it2->second){
            res += dfs(c,w);
            if(res >= MOD) res -= MOD;
        }
    }
    g_memo[p][c] = res;
    return res;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<ll>a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<vector<int>> adj(n+1);
    vector<pair<int,int>> edges;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        edges.emplace_back(u,v);
    }
    vector<unordered_map<ll, vector<int>>> mp(n+1);
    for(int u=1;u<=n;u++){
        mp[u].reserve(adj[u].size()*2+1);
        for(int v: adj[u]){
            mp[u][a[v]].push_back(v);
        }
    }
    g_a = a;
    g_mp = mp;
    g_memo.assign(n+1, unordered_map<int,ll>());
    for(int i=1;i<=n;i++) g_memo[i].reserve(4);

    ll ans = 0;
    for(auto &e: edges){
        ans = (ans+dfs(e.first, e.second))%MOD;
    }

    cout << ans << '\n';
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}