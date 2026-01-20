#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second

const ll INF = 1e18;
const int MOD = 1e9 + 7;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << '\n';
#else
#define debug(x)
#endif

void solve() {
    int n;
    cin >> n;

    vector<vector<ll>> arr(n);
    ll total = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        int len;
        cin >> len;
        arr[i].resize(len);
        for (ll &x : arr[i]) cin >> x;
        total += len;
        maxLen = max(maxLen, len);
    }
    vector<ll> freq(maxLen + 3, 0);
    for (auto &a : arr) {
        for (int x : a) {
            if (x <= maxLen + 1)
                freq[x]++;
        }
    }

    vector<int> mex(n), gap(n);
    ll sumMex = 0;
    ll imbalance = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int L = arr[i].size();
        vector<char> seen(L + 3, 0);
        vector<int> cnt(L + 2, 0);

        for (int x : arr[i]) {
            if (x <= L + 1) seen[x] = 1;
            if (x <= L) cnt[x]++;
        }

        int m = 0;
        while (m <= L && seen[m]) m++;

        int nextM = m + 1;
        while (nextM <= L + 1 && seen[nextM]) nextM++;

        mex[i] = m;
        gap[i] = nextM - m;
        sumMex += m;

        ll local = 0;
        for (int x = 0; x < m; x++) {
            if (cnt[x] == 1)
                local += 1LL*x - m;
        }
        imbalance += local;
    }

    ll cross = 0;
    for (int i = 0; i < n; i++) {
        cross += 1LL*gap[i] * freq[mex[i]];
    }

    ll operations = total * (n - 1LL);
     ans = sumMex * operations + (n - 1LL)*imbalance+cross;

    cout << ans << '\n';
}

int main() {
    fastio;

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}