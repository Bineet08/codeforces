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
    int n, m;
    ll h;
    cin >> n >> m >> h;

    vector<ll> base(n + 1);
    for (int i = 1; i <= n; i++) cin >> base[i];
    vector<ll> inc(n + 1, 0);
    vector<int> seen(n + 1, -1);

    int version = 0;

    while (m--) {
        int idx;
        ll val;
        cin >> idx >> val;
        if (seen[idx] != version) {
            seen[idx] = version;
            inc[idx] = 0;
        }

        inc[idx] += val;
        if (base[idx] + inc[idx] > h) {
            version++;
        }
    }

    for (int i = 1; i <= n; i++) {
        ll res = base[i];
        if (seen[i] == version) res += inc[i];
        cout << res << (i == n ? '\n' : ' ');
    }
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