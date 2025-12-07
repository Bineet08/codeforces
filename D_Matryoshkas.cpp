#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int>arr(n);
    map<int,int>mp;
    for(auto &a:arr) {
        cin>>a;
        mp[a]++;
    }
    int ans = 0;
    for(auto it:mp){
        if(mp.count(it.first-1))
        ans += max(0,it.second - mp[it.first-1]); 
        else ans += it.second;  
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