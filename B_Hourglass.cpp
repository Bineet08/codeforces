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
    int s,k,m;
    cin>>s>>k>>m;
    int a = m/k;
    int b = m%k;
    if(a%2==1){
        k = min(k,s);
        int ans = max(0,k-b);
        cout<<ans<<endl;
        return;
    }
    else{
        int ans = max(0,s-b);
        cout<<ans<<endl;
    }
    return ;

    

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