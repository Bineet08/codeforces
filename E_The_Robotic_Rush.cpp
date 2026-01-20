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

const ll INF = 1e9;
const int MOD = 1e9 + 7;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << '\n';
#else
#define debug(x)
#endif

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> A(n),B(m);
    for (ll &x : A) cin >> x;
    for (ll &x : B) cin >> x;
    sort(all(B));
    string moves;
    cin >> moves;
    vector<int> posHit(k+2,0), negHit(k+2,0);
    int cur = 0, maxPos = 0, maxNeg = 0;

    for (int i = 1; i <= k; i++) {
        cur += (moves[i - 1] == 'R' ? 1 : -1);

        if (cur > maxPos) {
            maxPos = cur;
            posHit[maxPos] = i;
        }
        if (cur < maxNeg) {
            maxNeg = cur;
            negHit[-maxNeg] = i;
        }
    }

    vector<int> pos(k + 2, 0);

    for (ll x : A) {
        int y = INF;

        auto it = lower_bound(all(B), x);

        if (it != B.end()) {
            ll d = *it - x;
            if (d > 0 && d <= maxPos)
                y = min(y, posHit[d]);
        }

        if (it != B.begin()) {
            ll d = x - *prev(it);
            if (d > 0 && d <= -maxNeg)
                y = min(y, negHit[d]);
        }

        if (y != INF)
            pos[y]++;
    }

    int eli = 0;
    for (int i = 1; i <= k; i++) {
        eli += pos[i];
        cout << (n - eli) << (i == k ? '\n' : ' ');
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