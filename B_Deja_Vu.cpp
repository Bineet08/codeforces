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
    cin >> n>>k;

    vector<int> arr(n), queries(k);
    for (int &x : arr) cin >> x;
    for(auto &a:queries) cin>>a;
    int prev = 31;

    for(auto q:queries){
        if(q>=prev) continue;
        ll val = pow(2,q);
        for(auto &a:arr){
            if(a%val==0){
                a += val/2;
            }
        }
        prev = q;
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