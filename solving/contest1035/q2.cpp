#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define vec vector
#define pb push_back
#define INF LLONG_MAX
#define se second
#define fi first
#define pii pair<int, int>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define pll pair<long long, long long>
#define str string

using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;

const int MOD = 1e9 + 7;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

void solve() {
    int n;
    cin >> n;
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int x = abs(a - c);
    int y = abs(b - d);
    int dis = x * x + y * y;

    vector<int> arr(n);
    for (auto &val : arr) cin >> val;

    int maxm = *max_element(all(arr));
    int sum = accumulate(all(arr), 0LL);

    int minm;
    if (n == 0) {
        minm = 0;
    } else {
        minm = max(0LL, 2*maxm - sum);
    }

    int min1 = minm * minm;
    int max1 = sum * sum;

    if (dis >= min1 && dis <= max1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
