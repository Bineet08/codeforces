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
     int n,w;
     cin>>n>>w;
     vector<int>arr(n,0);
     for(auto &a:arr) cin>>a;
     int h = 0;
     // sort(arr.begin(),arr.end(),greater<>());
     int used = 0;
     vector<int>wbox(21,0);
     for(auto &a:arr) wbox[log2(a)]++;
     while(used<n){
        int x = w;
        for(int i=20; i>=0; i--){
            while(wbox[i]>0 && (1<<i)<= x){
                x -= (1<<i);
                wbox[i]--;
                used++;
            }
        }
        h++;
     }
     cout<<h<<endl;

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