#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve() {
    int n;
    cin >> n;

    string arr;
    cin >> arr;

    int sq = sqrt(n);
    if (sq * sq != n) {
        cout << "NO" << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        int row = i / sq, col = i % sq;

        if (row == 0 || row == sq - 1 || col == 0 || col == sq - 1) {
            // Boundary cells
            if (arr[i] == '0') {
                cout << "NO" << endl;
                return;
            }
        } else {
            // Inner cells
            if (arr[i] == '1') {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
