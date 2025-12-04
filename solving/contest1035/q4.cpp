#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define int long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define ff first
#define ss second

const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve() {
    // Write your code here
    int n;
    cin>>n;
    int mod;
    cin>>mod;
    vector<int>dp(n+1,0);
    dp[0] = 1;
    int maxm = 0;
    for(int i=n;i>0;--i){
        for(int j = maxm;j>=0;--j){
            if(dp[j]!=0){
                int x= n-i+1-j;
                if(x<=0) break;
                    int sum = (dp[j]*x*i)%mod;
                    dp[j+1] = (dp[j+1] +sum) %mod;
            }
        }
        if(dp[maxm +1]) maxm+=1;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans += dp[i]%mod;
        ans=ans%mod;
    }
    cout<<ans<<endl;
}

int32_t main() {
    fastio;
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) {
        solve();
    }
    return 0;
}

for (int p = n; p >= 1; --p) {
        for (int k = max_k; k >= 0; --k) {
            if (dp[k] == 0) continue;
            int free = n - p + 1 - k;
            if (free <= 0) break;

            long long add = (1LL * dp[k] * free) % mod;
            add = (add * p) % mod;

            dp[k + 1] = (dp[k + 1] + add) % mod;
        }
        if (dp[max_k + 1]) max_k++;
    }

    int res = 0;
    for (int val : dp) {
        res = (res + val) % mod;
    }
    return res;
}