#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

int finding(vector<pair<ll,int>>& temp, int idx, vector<ll>& ps) {
    int i = idx;
    int n = temp.size();
    int found = i;

    while (i < n) {
        pair<ll,int> p = {ps[i] + 1, -1};
        int x = lower_bound(temp.begin(), temp.end(), p) - temp.begin();
        x--;
        if (x == i) break;
        found += x - i;
        i = x;
    }
    return found;
}

void solve() {
    int n;
    cin >> n;

    vector<ll> arr(n);
    for (ll &x : arr) cin >> x;

    vector<pair<ll,int>> temp(n);
    for (int i = 0; i < n; i++)
        temp[i] = {arr[i], i};

    sort(temp.begin(), temp.end());

    vector<ll> ps(n);
    ps[0] = temp[0].first;
    for (int i = 1; i < n; i++)
        ps[i] = ps[i - 1] + temp[i].first;

    vector<int> ans(n);

    for (int i = 0; i < n; i++)
        ans[temp[i].second] = finding(temp, i, ps);

    for (int x : ans) cout << x << " ";
    cout << "\n";
}

int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
