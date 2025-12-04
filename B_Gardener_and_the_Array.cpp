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
     int n;
     cin>>n;
     vector<vector<int>>arr;
     unordered_map<int,int>mp;
     for(int i=0;i<n;i++){
        int x;
        cin>>x;
        vector<int> c(x);
        for(auto &a:c){
            cin>>a;
            mp[a]++;
        }
        arr.push_back(c);
     }
     string ans = "No";
     for(auto &a:arr){
        int f = 1;
        for(auto x:a){
            if(mp[x]==1){
                f=0;
                break;
            }
        }
        if(f==1){
            ans = "Yes";
            break;
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