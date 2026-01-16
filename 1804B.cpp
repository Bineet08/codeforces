#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, k, d, w;
    cin >> n >> k >> d >> w;
    vector<ll> t(n);
    for (ll i = 0; i < n; i++) {
        cin >> t[i];
    }

    ll packs = 0;
    ll i = 0;
    while (i < n) {
        ll earliest = t[i];
        ll count = 0;
        ll j = i;
        ll open_time = earliest;
        while (j < n && count < k && t[j] <= open_time + d && open_time <= t[j] + w) {
            j++;
            count++;
        }
        for (ll next = i; next < n && next < i + k; next++) {
            ll new_open_time = min(t[next] + w, t[i] + w);
            ll new_count = 0;
            ll new_j = i;
            while (new_j < n && new_count < k && t[new_j] <= new_open_time + d && new_open_time <= t[new_j] + w) {
                new_j++;
                new_count++;
            }
            if (new_count > count) {
                count = new_count;
                j = new_j;
                open_time = new_open_time;
            }
        }
        i = j; 
        packs++;
    }
    cout << packs << '\n';
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