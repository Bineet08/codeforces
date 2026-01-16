#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define int long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define ff first
#define ss second

const int MOD=1e9 + 7;
const int INF=1e18;

void solve() {
    // Write your code here
    int n,k;
    cin >> n >> k;
    vector<tuple<int, int, int>> cas(n); // (l, r, x)
    for (int i=0; i < n; i++) {
        int l, r, real;
        cin >> l>>r>>real;
        cas[i]={l,r,real};
    }

    sort(cas.begin(), cas.end(), [](const auto &a, const auto &b) {
        if(get<0>(a)==get<0>(b) && get<1>(a)==get<1>(b)) return get<2>(a) < get<2>(b);
        if (get<0>(a)==get<0>(b)) return get<1>(a)<get<1>(b);
        return get<0>(a) < get<0>(b);
    });


    int curr=k;
    int i=0;
    priority_queue<int> pq;
    while (i <n && get<0>(cas[i])<=curr) {
        pq.push(get<2>(cas[i]));
        i++;
    }

    while (!pq.empty()) {
        // Remove all entries where x <=curr (unusable)
        while (!pq.empty() && pq.top() <=curr) {
            pq.pop();
        }

        if (pq.empty()) break;

        // Jump to the top x
        curr=pq.top();
        pq.pop();

        // Add new reachable casinos after jump
        while (i < n && get<0>(cas[i]) <=curr) {
            pq.push(get<2>(cas[i]));
            i++;
        }
    }

    cout << curr << endl;
}

int32_t main() {
    fastio;
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
