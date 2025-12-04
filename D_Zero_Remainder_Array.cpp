#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}

void solve() {
     // Cursor position after snippet insertion
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(auto &a:arr) cin>>a;
    map<int,int>mp;
    int count = 0;
    for(auto a:arr){
        if(a%k!=0){
            count++;
            mp[k-(a%k)]++;
        }
    }
    if(count==0){
        cout<<0<<endl;
        return;
    }
    int maxfreq = 0, maxm = 0;
    for(auto &it:mp){
        if(maxfreq<=it.second){
            maxfreq = it.second;
            maxm = it.first;
        }
    }
    cout<<(maxfreq-1)*k + maxm + 1<<endl;
    return;
}

int32_t main() {
    fast_io();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}