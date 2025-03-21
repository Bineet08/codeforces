#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int x, y, n;
        cin >> x >> y >> n;

        // Compute m
        int m = (n - y) / x;

        // Compute k
        int k = m * x + y;

        cout << k << endl;
    }

    return 0;
}
