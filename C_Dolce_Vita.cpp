#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

ll maxDays(ll ps,int idx,int k){
    int l=0,r=1e9+5;
    ll ans = 0;
    while(l<=r){
        ll mid = l + (r-l)/2;
        if(ps + (1LL*(idx+1)*(mid-1))<=k){
            ans = mid;
            l = mid+1;
        } 
        else{
            r = mid-1;
        }
    }
    return ans;
}

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    ll ans = 0;
    sort(arr.begin(),arr.end());
    vector<ll>ps(n);
    ps[0] = arr[0];
    for(int i=1;i<n;i++){
        ps[i] = ps[i-1] + arr[i];
    }
    for(int i=0;i<n;i++){
        ans += maxDays(ps[i],i,k);
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