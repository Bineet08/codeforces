#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;

    if(m >= 3 && n >= 3) {
        cout << "YES\n";
        return;
    }

    if(m == 2) {
        bool ok = false;
        for(int shift = 0; shift < n; shift++) {
            bool same = true;
            for(int i = 0; i < n; i++) {
                if(a[(i + shift) % n] != b[i]) {
                    same = false;
                    break;
                }
            }
            if(same) ok = true;
        }
        cout << (ok ? "YES\n" : "NO\n");
        return;
    }

    if(m >= 3 && n == 2) {
        if(abs(a[0]-a[1]) >= 2) {
            cout << "YES\n";
            return;
        } else {
            bool ok = false;
            for(int shift = 0; shift < n; shift++) {
                bool same = true;
                for(int i = 0; i < n; i++) {
                    if(a[(i + shift) % n] != b[i]) {
                        same = false;
                        break;
                    }
                }
                if(same) ok = true;
            }
            cout << (ok ? "YES\n" : "NO\n");
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
}
