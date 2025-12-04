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
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    int l_prime = max(l, -m); 
    int r_prime = l_prime + m;
    if (r_prime > r) {
        int shift = r_prime - r;
        l_prime -= shift;
        r_prime -= shift;
    }
    cout << l_prime << " " << r_prime << '\n';
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