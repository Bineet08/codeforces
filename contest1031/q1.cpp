#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

void solve() {
    long long k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;
    
    // Option 1: type 1 first
    long long temp = k, ans1 = 0;
    if (temp >= a) {
        long long cnt = (temp - a) / x + 1;
        ans1 += cnt;
        temp -= cnt * x;
    }
    if (temp >= b) {
        long long cnt = (temp - b) / y + 1;
        ans1 += cnt;
    }
    
    // Option 2: type 2 first
    temp = k;
    long long ans2 = 0;
    if (temp >= b) {
        long long cnt = (temp - b) / y + 1;
        ans2 += cnt;
        temp -= cnt * y;
    }
    if (temp >= a) {
        long long cnt = (temp - a) / x + 1;
        ans2 += cnt;
    }

    cout << max(ans1, ans2) << endl;
}

int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
