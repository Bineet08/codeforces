#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string ans = string(k, '1') + string(n - k, '0');
        cout << ans << '\n';
    }

    return 0;
}