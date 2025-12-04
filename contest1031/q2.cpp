#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define int long long

bool can_tile(int w, int h, int a, int b, int x1, int y1, int x2, int y2) {
    int rx1 = (x1 % a + a) % a;
    int rx2 = (x2 % a + a) % a;
    int ry1 = (y1 % b + b) % b;
    int ry2 = (y2 % b + b) % b;

    bool vert_ok = (rx1 == rx2) && ((x1 != x2) || (ry1 == ry2));
    bool horiz_ok = (ry1 == ry2) && ((y1 != y2) || (rx1 == rx2));

    return vert_ok || horiz_ok;
}

void solve() {
    int w, h, a, b;
    cin >> w >> h >> a >> b;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (can_tile(w, h, a, b, x1, y1, x2, y2)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
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
