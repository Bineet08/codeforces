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
    int n,k;
    cin >> n >>k;

    vector<int> arr(n),b(n);
    for (int &x : arr) cin >> x;
    for(int &x:b) cin>>x;
    vector<int>ps(n,0);
    ps[0] = arr[0];
    for(int i=1;i<min(n,k);i++){
        ps[i] = ps[i-1] + arr[i];
    }
    int maxm = b[0];
    int ans = ps[0];
    for(int i=0;i<min(n,k);i++){
        maxm = max(maxm,b[i]);
        ps[i] = ps[i] + maxm*(k-i-1);
        ans = max(ps[i],ans);

    }
    cout<<ans<<endl;
    

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