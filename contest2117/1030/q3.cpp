#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int ones(ll val) {
    return __builtin_popcountll(val);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int len;
        ll budget;
        cin >> len >> budget;

        vector<ll> arr(len), steps;
        ll res = 0;

        for (int i = 0; i < len; ++i) {
            cin >> arr[i];
            ll num = arr[i];
            res += ones(num);
            while (true) {
                int p = __builtin_ctzll(~num);
                ll c = 1LL << p;
                if (budget < c) break;
                steps.push_back(c);
                num += c;
            }
        }

        sort(steps.begin(), steps.end());
        for (ll c : steps) {
            if (budget >= c) {
                budget -= c;
                res++;
            } else break;
        }
        cout << res << '\n';
    }
    return 0;
}
