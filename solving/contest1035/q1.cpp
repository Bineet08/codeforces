#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define int long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define ff first
#define ss second

int dfs(int x, int y, int tx, int ty, map<long long, int> &memo) {
    if (x > tx || y > ty) return 1e9;
    if (x == tx && y == ty) return 0;

    long long key = ((long long)x << 32) | y;
    if (memo.count(key)) return memo[key];

    int addY = dfs(x + y, y, tx, ty, memo);
    int addX = dfs(x, x + y, tx, ty, memo);

    return memo[key] = 1 + min(addX, addY);
}

int minMoves(int sx, int sy, int tx, int ty) {
    map<long long, int> memo;
    int res = dfs(sx, sy, tx, ty, memo);
    return (res >= 1e9) ? -1 : res;
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << minMoves(a, b, c, d) << endl;
}

int32_t main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
