#include <bits/stdc++.h>
using namespace std;


int Paths(int m, int n, vector<vector<int>> &memo) {
    if (m == 1 || n == 1)
        return 1;
    if (memo[m][n] == 0)
        memo[m][n] = Paths(m - 1, n, memo) + Paths(m, n - 1, memo);
    return memo[m][n];
}

int numberOfPaths(int m, int n) {
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0));
    return Paths(m, n, memo);
}

void solve() {
    int m, n;
    cin >> m >> n;
    cout << numberOfPaths(m, n) << endl;
}

int main() {
    ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
