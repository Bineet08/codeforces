#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

bool cansum(int target, vector<int> &arr, vector<int> &memo) {
    if (target == 0) return true;
    if (target < 0) return false;
    if (memo[target] != -1) return memo[target];

    for (int num : arr) {
        if (cansum(target - num, arr, memo)) {
            return memo[target] = true;
        }
    }

    return memo[target] = false;
}

void solve() {
    int target, n;
    cin >> target >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<int> memo(target + 1, -1);
    if (cansum(target, arr, memo)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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
