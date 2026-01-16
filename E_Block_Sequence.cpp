#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &a:arr) cin>>a;
    vector<int> dp(n + 1,0);
		for (int i = n - 1; i >= 0; --i) {
			dp[i] = dp[i + 1] + 1;
			int j=i + arr[i] + 1;
			if (j <= n) {
				dp[i] = min(dp[i], dp[j]);
			}
		}
        cout<<dp[0]<<endl;
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}