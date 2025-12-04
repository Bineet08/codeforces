#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define int long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define ff first
#define ss second

const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve() {
    // Write your code here
    int n;
    cin>>n;
    int xmin = 0,xmax = INT_MAX, ymin =0,ymax = INT_MAX;
    unordered_map<int,vector<int>> rows;
    unordered_map<int,vector<int>> cols;
    vector<int>x(n) , y(n);
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
        xmin = min(xmin,x[i]);
        xmax = max(xmax,x[i]);
        ymin = min(ymin,y[i]);
        ymax = max(ymax,y[i]);
    }
    int dx = xmax-xmin +1;
    int dy = ymax - xmin +1;
    int pred = dx*dy;
    
    
}

int32_t main() {
    fastio;
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) {
        solve();
    }
    return 0;
}