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
    int n;
    cin >> n;

    vector<int> arr;
    n-=1;
    ll bit = log2(n);
    ll x = pow(2,bit) - 1;
    while(x>=0){
        arr.push_back(x);
        x--;
    }
    x = pow(2,bit);
    while(x<=n){
        arr.push_back(x);
        x++;
    }
    
    for(auto a:arr) cout<<a<<" ";
    cout<<endl;

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