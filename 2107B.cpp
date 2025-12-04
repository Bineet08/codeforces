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
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    int sum=0;
    int maxm=INT_MIN;
    int minm = INT_MAX;
    for(auto &x:a){
        cin>>x;
        maxm = max(maxm,x);
        minm = min(minm,x);
        sum+=x;
    }
    int count=0;
    for(auto x:a) if(x==maxm) count+=1;
    if(maxm -minm -1>k || (maxm-minm>k && count>1)){
        cout<<"Jerry"<<endl;
        return;
    }
    if(sum%2==1) cout<<"Tom"<<endl;
    else cout<<"Jerry"<<endl;
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