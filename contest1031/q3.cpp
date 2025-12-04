#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9 + 5;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> g(n);
    for (auto& s : g) cin >> s;

    vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
    int total = 0;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            int add = (g[i][j] == 'g');
            total += add;
            pref[i + 1][j + 1] =
                pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + add;
        }

    // Lambda to get gold count in subrectangle
    auto goldInRect = [&](int x1, int y1, int x2, int y2) -> int {
        if (x1 > x2 || y1 > y2) return 0;
        return pref[x2 + 1][y2 + 1] - pref[x1][y2 + 1]
             - pref[x2 + 1][y1]   + pref[x1][y1];
    };

    int bestLoss = INF;
    int inner = k - 1;
    for (int x = 0; x < n; ++x)
        for (int y = 0; y < m; ++y)
            if (g[x][y] == '.') {
                int x1 = max(0, x - inner);
                int y1 = max(0, y - inner);
                int x2 = min(n - 1, x + inner);
                int y2 = min(m - 1, y + inner);
                int loss = goldInRect(x1, y1, x2, y2);
                bestLoss = min(bestLoss, loss);
            }

    cout << total - bestLoss << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}
