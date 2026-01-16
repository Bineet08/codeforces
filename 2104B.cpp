#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> suffix_sum(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        suffix_sum[i] = suffix_sum[i + 1] + a[i];
    }
    vector<ll> prefix_max(n, LLONG_MIN);
    if (n > 0) prefix_max[0] = a[0];
    for (int i = 1; i < n; ++i) {
        prefix_max[i] = max(prefix_max[i - 1], a[i]);
    }
    
    // For each k
    for (int k = 1; k <= n; ++k) {
        ll max_sum = suffix_sum[n - k]; 
        if (n - k > 0) {
            ll sum_with_move = (n - k + 1 < n ? suffix_sum[n - k + 1] : 0) + prefix_max[n - k - 1];
            max_sum = max(max_sum, sum_with_move);
        }
        cout << max_sum << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}