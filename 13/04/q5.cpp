#include <iostream>
#include <string>

using namespace std;

void solve(){
    int t;
    cin >> t;
    while (t--) {
        string p, s;
        cin >> p >> s;
        int len_p = p.length();
        int len_s = s.length();
        if (len_s < len_p || len_s > 2 * len_p) {
            cout << "NO" << endl;
            continue;
        }
        
        int i = 0;
        int j = 0; 
        bool possible = true;
        while (i < len_p && j < len_s) {
            if (p[i] != s[j]) {
                possible = false;
                break;
            }
            if (j + 1 < len_s && s[j+1] == p[i]) {
                j += 2;
            } else {
                j += 1;
            }
            i += 1;
        }
        
        if (possible && i == len_p && j == len_s) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}