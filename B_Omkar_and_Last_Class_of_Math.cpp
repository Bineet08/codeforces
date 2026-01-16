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
     int sq = sqrt(n);
     for(int i=2;i<=sq;i++){
        if(n%i==0){
            cout<<n/i<<" "<<n - n/i<<endl;
            return;
        }
     }
     cout<<1<<" "<<n-1<<endl;
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