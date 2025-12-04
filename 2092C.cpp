#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0, odd = 0, mx = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        if (a[i] % 2 == 1) odd++;
        mx = max(mx, a[i]);
    }

    if (odd == 0 || odd == n) {
        cout << mx << '\n'; 
    } else {
        cout << sum - odd + 1 << '\n';
    }
}

int32_t main() {
    fastio;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
