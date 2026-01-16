#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}



int solve1(vector<int>&a, vector<int>&b,int idx, int takeA,vector<vector<int>>dp) {
    if (idx == 0) {
        return takeA ? a[0] : b[0];
    }
    if (dp[idx][takeA] != -1) return dp[idx][takeA];

    if (takeA)
        return dp[idx][takeA] = max(solve1(a,b,idx - 1, 1,dp), solve1(a,b,idx - 1, 0,dp) + a[idx]);
    else
        return dp[idx][takeA] = max(solve1(a,b,idx - 1, 0,dp), solve1(a,b,idx - 1, 1,dp) + b[idx]);
}


void solve() {
     // Cursor position after snippet insertion
     int n;
     cin>>n;
     vector<int>a(n),b(n);
     for(auto &x:a) cin>>x;
     for(auto &x:b) cin>>x;
     //vector<vector<int>>dp(n,vector<int>(2,-1));

     vector<int> dp1(n),dp2(n);
     dp1[0] = a[0];
     dp2[0] = b[0];
     for(int i=1;i<n;i++){
        dp1[i] = max(dp1[i-1],dp2[i-1] + a[i]);
        dp2[i] = max(dp2[i-1],dp1[i-1] + b[i]);
     }
     cout<<max(dp1[n-1],dp2[n-1])<<endl;
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