#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count1 = 0, countl = 0, i = 0, j = n - 1;
    while (i < n && count1 < k) {
        if (arr[i] == arr[0]) {
            count1++;
        }
        i++;
    }
    if (arr[0] == arr[n - 1]) {
        if (count1 >= k) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return;
    }
    while (j >= 0 && countl < k) {
        if (arr[j] == arr[n - 1]) {
            countl++;
        }
        j--;
    }

    // Check if segments with required conditions exist
    if (count1 >= k && countl >= k && i <= j + 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
