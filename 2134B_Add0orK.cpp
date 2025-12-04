#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    vector<long long> arr(n);
    for (auto &a : arr) cin >> a;

    // if (n == 1) {
    //     if (arr[0] != 1) {
    //         cout << arr[0] << "\n";
    //     } else {
    //         cout << arr[0] + k << "\n";
    //     }
    //     return;
    // }

    // if (k % 2 != 0) {
    //     for (int i = 0; i < n; i++) {
    //         if (arr[i] & 1) arr[i] += k;
    //     }
    // } else {
    //     long long x = 3;
    //     while (k % x == 0) x += 2;
    //     for (int i = 0; i < n; i++) {
    //         while (arr[i] % x != 0) arr[i] += k;
    //     }
    // }
    for(auto &a:arr){
        long long c = a%(k+1);
        a = a + c*k;
    }
    for (auto a : arr) cout << a << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
