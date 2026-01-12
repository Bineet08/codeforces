#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> seq;
    seq.push_back(0);

    for (int step = 1; step <=n; step++) {
        vector<int> next;
        int limit = 1 << step;
        next.reserve(limit);
        for (int x : seq) {
            next.push_back((x << 1) | 1);
        }
        for (int i = 0; i < limit; i += 2) {
            next.push_back(i);
        }

        seq.swap(next);
    }

    for (int x : seq) cout << x << " ";
    cout << '\n';
}


int main() {
    fastio;
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}