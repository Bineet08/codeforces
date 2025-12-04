#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define int long long

const int MOD = 998244353;
const int INF = 1e18;

void solve() {
    // Write your code here
    int n=1;
    cin>>n;
    vector<int> p(n,0);
    vector<int> q(n,0);
    for(int i=0;i<n;i++) cin>>p[i];
    for(int i=0;i<n;i++) cin>>q[i];
    vector<int> r(n,0);
    vector<int> power(n,0);
    power[0] = 1;
    for(int i=1;i<n;i++){
        power[i] = (2*power[i-1]) % MOD;
    }
    vector<int> idxP(n),idxQ(n);
    for(int i=0;i<n;i++){
        idxP[p[i]] = i;
        idxQ[q[i]] = i;
    }
    int a = p[0], b= q[0];
    for(int i=0;i<n;i++){
        a = max(a,p[i]);
        b = max(b,q[i]);
        pair<int,int> a1 = {a, q[i - idxP[a]]};
        pair<int,int> b1 = {b, p[i - idxQ[b]]};
        pair<int,int> R = max(a1,b1);
        r[i] = (power[R.first] + power[R.second]) %MOD;
    }
    for(auto &a: r){
        cout<<a<<" ";
    }
    cout<<endl;
}

int32_t main() {
    fastio;
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) {
        solve();
    }
    return 0;
}