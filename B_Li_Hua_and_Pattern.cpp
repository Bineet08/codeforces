#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second

const ll INF = 1e18;
const int MOD = 1e9 + 7;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << '\n';
#else
#define debug(x)
#endif

void solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> arr(n, vector<int>(n));
    for(auto &row : arr)
        for(auto &x : row)
            cin >> x;
    for(int i = 0; i < n/2; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] != arr[n-1-i][n-1-j])
                k--;
            if(k < 0){
                cout << "NO\n";
                return;
            }
        }
    }

    if(n % 2 == 1){
        int mid = n / 2;
        for(int j = 0; j < n/2; j++){
            if(arr[mid][j] != arr[mid][n-1-j])
                k--;
            if(k < 0){
                cout << "NO\n";
                return;
            }
        }
    }
    if(k % 2 == 0 || n % 2 == 1)
        cout << "YES\n";
    else
        cout << "NO\n";
}


int main() {
    fastio;

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}