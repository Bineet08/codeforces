#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int drinks = (k * l) / nl;
    int limes = c * d;
    int salts = p / np;
    int maxToasts = min({drinks, limes, salts}) / n;
    cout << maxToasts << endl;
    return 0;
}
