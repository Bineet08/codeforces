#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<tuple<int, int, int>> ops;
        ops.emplace_back(1, 1, n);
        for (int i = 2; i <= n; ++i) {
            int pre_len = n - i + 1;
            int suf_start = pre_len + 1;
            ops.emplace_back(i, 1, pre_len);
            if (suf_start <= n) {
                ops.emplace_back(i, suf_start, n);
            }
        }
        cout << ops.size() << '\n';
        for (auto &[row, l, r] : ops) {
            cout << row << " " << l << " " << r << '\n';
        }
    }

    return 0;
}