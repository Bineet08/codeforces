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

struct X {
    int v;
    unsigned char f;
};

int main() {
    fastio;

    int T;
    cin >> T;
    while (T--) {
        int p, qs;
        cin >> p >> qs;

        const int BASE = 1 << p;

        vector<int> raw(BASE);
        for (int i = 0; i < BASE; ++i) cin >> raw[i];

        vector<X> t(2 * BASE);

        for (int i = 0; i < BASE; ++i) {
            t[BASE | i].v = raw[i];
            t[BASE | i].f = 0;
        }
        for (int i = BASE - 1; i; --i) {
            int l = i << 1, r = l | 1;
            int a = t[l].v, b = t[r].v;
            t[i].v = a ^ b;
            t[i].f = (a < b);
        }

        auto apply = [&](int id, int nv) {
            id |= BASE;
            t[id].v = nv;
            t[id].f = 0;
            while (id >>= 1) {
                int l = id << 1, r = l | 1;
                int a = t[l].v, b = t[r].v;
                t[id].v = a ^ b;
                t[id].f = (a < b);
            }
        };

        auto rank_of = [&](int id) {
            ll acc = 0, span = 1;
            for (id |= BASE; id > 1; id >>= 1) {
                int par = id >> 1;
                acc += (t[par].f == (id & 1)) * span;
                span <<= 1;
            }
            return acc;
        };

        while (qs--) {
            int i, x;
            cin >> i >> x;
            --i;

            int old = raw[i];
            apply(i, x);

            ll r = rank_of(i);
            cout << (BASE - 1 - r) << '\n';

            apply(i, old);
        }
    }
    return 0;
}
