#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<ll>arr(n);
    for(auto &x:arr) cin>>x;
    vector<ll> res;
    res.push_back(arr[0]);
    for(int i=1;i<n-1;i++){
        if((arr[i]-arr[i-1])*(arr[i+1]-arr[i])<0) res.push_back(arr[i]);
    }
    res.push_back(arr[n-1]);
    cout<<res.size()<<endl;
    for(auto x:res) cout<<x<<" ";
    cout<<endl;
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}