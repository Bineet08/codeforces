#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
bool solveOne(const string &p, const string &s) {
    int i = 0, j = 0;
    int n = p.size(), m = s.size();
    while (i < n && j < m) {
        if (p[i] != s[j]) return false;
        char c = p[i];
        int cntP = 0;
        while (i< n && p[i]==c) {
            cntP++;
            i++;
        }
        int cntS = 0;
        while (j < m && s[j] == c) {
            cntS++;
            j++;
        }
        if (!(cntS >= cntP && cntS <= 2 * cntP)) return false;
    }
    return (i==n && j==m);
}

int main() {
    fastio;
    int T;
    cin >> T;
    while (T--) {
        string p, s;
        cin >> p >> s;
        cout << (solveOne(p, s) ? "YES\n" : "NO\n");
    }
    return 0;
}
