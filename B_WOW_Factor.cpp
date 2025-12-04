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
    string str;
    cin>>str;
    int n = str.size();
    vector<vector<int>> dp(n+1,vector<int>(4,0));
    for(int i=0;i<n;i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<n;i++){
        if(str[i]=='v' && str[i-1]=='v'){
           dp[i+1][1] += dp[i-1][0];
           dp[i+1][3] += dp[i-1][2]; 
        }
        else if(str[i]=='o'){
            dp[i+1][2] += dp[i][1];
        }
        dp[i+1][1] += dp[i][1];
        dp[i+1][2] += dp[i][2];
        dp[i+1][3] += dp[i][3];
    }
    cout<<dp[n][3]<<endl;
}

int32_t main() {
    fast_io();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}