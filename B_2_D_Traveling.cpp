#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second

const ll INF = 1e18;
const int MOD = 1e9 + 7;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << '\n';
#else
#define debug(x)
#endif

void solve() {
    ll n,k,a,b;
    cin >> n >> k>>a>>b;
    vector<vector<ll>> coord(n,vector<ll>(2,0));
    for(auto &c:coord){
        for(auto &x:c) cin>>x;
    }
    a-=1;
    b-=1;

    ll ans = abs(coord[a][0] - coord[b][0]) + abs(coord[a][1] - coord[b][1]);
    ll mina = 1e17,minb = 1e17;
    for(int i=0;i<k;i++){
        mina = min(mina,(abs(coord[a][0] - coord[i][0]) + abs(coord[a][1] - coord[i][1])));
        minb = min(minb,(abs(coord[b][0] - coord[i][0]) + abs(coord[b][1] - coord[i][1])));
    }
    ans = min(ans,mina+minb);
    cout<<ans<<endl;
    return;
}

int main() {
    fastio;

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}