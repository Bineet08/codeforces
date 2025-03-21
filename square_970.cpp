#include<iostream>
using namespace std;

void solve() {
    // Lambda function to compute the floor square root of a number
    auto sqrt = [&](int x) {
        if(x == 1) return 1;
        if(x == 0) return 0;

        int l = 0, r = 1e9 + 7;
        while(l < r) {
            long long mid = (l + r + 1) / 2;
            if(mid * mid <= x) l = mid;
            else r = mid - 1;
        }
        return l;
    };

    int n;
    cin >> n;  // Input the length of the binary string

    int k = sqrt(n);
    if(k * k != n || n == 0) {
        cout << "No" << endl;
        return;
    }

    string mat;
    cin >> mat;
    if(n == 1 && mat == "1") {
        cout << "Yes" << endl;
        return;
    }
    for(int i = 0; i < k; i++) {
        if(mat[i] == '0') {
            cout << "No" << endl;
            return;
        }
    }
    for(int i = k; i < n; i += k) {
        if(mat[i] == '0') {
            cout << "No" << endl;
            return;
        }
    }
    for(int i = k - 1; i < n; i += k) {
        if(mat[i] == '0') {
            cout << "No" << endl;
            return;
        }
    }
    for(int i = k * (k - 1); i < n; i++) {
        if(mat[i] == '0') {
            cout << "No" << endl;
            return;
        }
    }

    // If all checks pass, print "Yes"
    cout << "Yes" << endl;
}

int main() {
    int t;
    cin >> t;  // Number of test cases

    // Loop through all test cases
    while(t--) {
        solve();
    }
}
