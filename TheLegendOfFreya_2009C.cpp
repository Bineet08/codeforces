#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define int long long

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    x = (x+k-1)/k;
    y=(y+k-1)/k;
    cout<<2*(x>y?x:y)-(x>y)<<endl;
    return;
}

int32_t main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
