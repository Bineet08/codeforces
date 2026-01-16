#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<long long> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    if (n < 2) {
        cout << 0 << "\n";
        return;
    }
    sort(x.begin(), x.end());
    vector<long long> d(n - 1);
    for (int i = 0; i + 1 < n; i++) {
        d[i] = x[i + 1] - x[i];
    }
    vector<long long> lnds;
    for (long long gap : d) {

        auto it = upper_bound(lnds.begin(), lnds.end(), gap);
        if (it == lnds.end()) {
            lnds.push_back(gap);
        } else {
            *it = gap;
        }
    }

    cout << lnds.size() << "\n";
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}