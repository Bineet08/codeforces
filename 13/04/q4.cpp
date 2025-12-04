#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> bitCount(30, 0);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            for (int b = 0; b < 30; ++b) {
                if (a[i] & (1 << b)) bitCount[b]++;
            }
        }

        ll max_sum = 0;

        for (int i = 0; i < n; ++i) {
            ll curr = 0;
            for (int b = 0; b < 30; ++b) {
                int bit = (a[i] >> b) & 1;
                int cnt = bitCount[b];
                int ones = bit ? (n - cnt) : cnt;
                curr += 1LL * ones * (1 << b);
            }
            max_sum = max(max_sum, curr);
        }

        cout << max_sum << '\n';
    }

    return 0;
}
