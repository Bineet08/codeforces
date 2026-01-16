#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &a:arr) cin>>a;
    ll sum = 0,ans=0;
    for(int i=1;i<n;i++){
        sum += llabs(arr[i]-arr[i-1]);
    }
    ans = sum - llabs(arr[0]-arr[1]);
    ans=min(ans,sum-llabs(arr[n-1]-arr[n-2]));
    for(int i=1;i<n-1;i++){
        ll curr = sum - llabs(arr[i]-arr[i-1]) - llabs(arr[i+1]-arr[i]) + llabs(arr[i+1]-arr[i-1]);
        ans=min(curr,ans);
    }
    cout<<ans<<endl;
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}