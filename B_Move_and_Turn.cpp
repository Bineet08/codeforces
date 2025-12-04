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
     if(n%2==0){
        int x = n/2 + 1;
        int y = x;
        cout<<x*y<<endl;
        
     }
     else{
        int x = n/2 + 1;
        int y = x+1;
        cout<<2LL*x*y<<endl;
     }
     return;
}

int32_t main() {
    fast_io();
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}