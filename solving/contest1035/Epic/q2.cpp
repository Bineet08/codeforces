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
    vector<int> arr(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    vector<int> minm(n), prefix(n);
    int minimum = arr[0], sum = arr[0];
    prefix[0] = sum;
    minm[0] = minimum;

    for (int i = 1; i < n; ++i) {
        minimum = min(minimum, arr[i]);
        sum += minimum;
        prefix[i] = sum;
        minm[i] = minimum;
    }

    int ans = prefix[n - 1];
    for (int i = 0; i < n - 1; ++i) {
        int a = (i ? minm[i - 1] : INT_MAX); 
        int b = (i ? prefix[i - 1] : 0);
        ans = min(ans, b + min(a, arr[i] + arr[i + 1]));
    }

    cout << ans << endl;
}

int32_t main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
