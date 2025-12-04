#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define int long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define ff first
#define ss second

const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve() {
    // Write your code here
    int n=1;
    cin>>n;
    vector<int> res(n,0);
    for(int i=0;2*i<n;i++){
        res[i] = 2*i+1;
        res[n-i-1] = 2*(i+1);
    }
    if(n%2==1) res[n/2] = n;
    for(auto &a:res){
        cout<<a<<" ";
    }
    cout<<endl;
    return;
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