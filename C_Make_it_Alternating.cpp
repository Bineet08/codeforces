#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}

const int mod = 998244353;
void solve() {
     // Cursor position after snippet insertion
    string s;
    cin>>s;
    int n = s.size();
    int x = 1;
    int y=1;
    int curr = 1;
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1]) curr++;
        else{
            x++;
            y = (y*curr)%mod;
            curr=1;
        }
    }
        y = (y*curr)%mod;
        for(int i=1;i<=n-x;i++){
            y = (y*i)%mod;
        }

        cout<<n-x<<" "<<y<<endl;
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