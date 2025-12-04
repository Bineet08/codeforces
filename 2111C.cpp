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
    int n;
    cin >> n;
    vector<int> a(n,0);
    for(int i = 0;i<n; i++) cin >> a[i];

    int res = INF;
    int prev = -1, count= 0;

    for(int i = 0; i <= n; i++) {
        if(i != n && a[i] == prev) {
            count++;
        } else {
            if(count != 0) {
                res = min(res, prev * (n - count));
            }
            if(i != n) {
                prev = a[i];
                count = 1;
            }
        }
    }

    cout << res << endl;
}

int32_t main() {
    fastio;
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
