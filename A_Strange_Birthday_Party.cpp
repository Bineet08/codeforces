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
     int n,m;
     cin>>n>>m;
     vector<int>arr(n,0),c(m,0);
     for(auto &a:arr) cin>>a;
     for(auto &a:c) cin>>a;
     int ans = 0;
     int x=0;
     sort(arr.begin(),arr.end(),greater<>());
     for(int i =0;i<n;i++){
        if(x<m && c[x] <=c[arr[i]-1]){
            ans += c[x];
            x++;
        }
        else{
            ans += c[arr[i]-1];
        }
     }
     cout<<ans<<endl;

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