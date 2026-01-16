#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> cells;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int d = max(i, n - 1 - i) + max(j, m - 1 - j);
            cells.push_back({d, {i + 1, j + 1}});
        }
    }
    sort(cells.begin(), cells.end());

    for(auto &cell : cells) {
        cout << cell.second.first << " " << cell.second.second << '\n';
    }
}
int main() {
    int t;
    cin >> t;
    while(t--) solve();
}
