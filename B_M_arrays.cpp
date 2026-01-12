#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int>arr(n);
    unordered_map<int,int>mp;
    for(auto &a:arr){
        cin>>a;
        mp[a%m]++;
    }
    int ans = 0;
    for(int i=0;i<m;i++){
        if(mp[i]>0 && mp[(m-i)%m]>0){
            ans++;
            int minm = min(mp[i],mp[(m-i)%m]);

            mp[i]-=minm;
            if(mp[i]>0) mp[i]-=1;
            if(mp[(m-i)%m]>0)mp[m-i] -= minm;
            if(mp[(m-i)%m]>0) mp[(m-i)%m] -= 1;
            ans += mp[i];
        }
        else ans += mp[i];
        // cout<<ans<<" ";
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