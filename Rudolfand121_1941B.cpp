#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    for (int i = 0; i < n - 2; i++) {
        if (arr[i] < 0) {
            cout << "NO" << endl;
            return;
        }
        if (arr[i] == 0) continue; // Skip if already zero

        int to_subtract = arr[i];
        arr[i] -= to_subtract;
        arr[i + 1] -= 2 * to_subtract;
        arr[i + 2] -= to_subtract;
    }

    // Check if the last two elements are zero
    if (arr[n - 1] != 0 || arr[n - 2] != 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int32_t main() {
    fastio;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}