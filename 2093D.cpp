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

int val(int n, int x, int y){
    if(n == 0) return 1;
    int h = 1 << (n - 1);
    int b = h * h;

    if(x <= h && y <= h){
        return val(n - 1, x, y);
    }
    else if(x > h && y > h){
        return b + val(n - 1, x - h, y - h);
    }
    else if(y > h){
        return 2 * b + val(n - 1, x, y - h);
    }
    else{
        return 3 * b + val(n - 1, x - h, y);
    }
}
pair<int,int> coord(int n, int d){
    if(n == 0) return {1, 1};
    int h = 1 << (n - 1);
    int b = h * h;
    pair<int, int> ans;

    if(d <= b){
        ans = coord(n - 1, d);
    }
    else if(d <= 2 * b){
        ans = coord(n - 1, d - b);
        ans.first += h;
        ans.second += h;
    }
    else if(d <= 3 * b){
        ans = coord(n - 1, d - 2 * b);
        ans.first += h;
    }
    else{
        ans = coord(n - 1, d - 3 * b);
        ans.second += h;
    }

    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> arr(3, vector<int>(3));
    arr[1][1] = 1;
    arr[1][2] = 4;
    arr[2][1] = 3;
    arr[2][2] = 2;

    int q;
    cin >> q;
    string str;

    for(int i = 0; i < q; i++){
        cin >> str;
        if(str == "->"){
            int x, y;
            cin >> x >> y;
            int d = val(n, y, x);
            cout << d << endl;
        }
        else{
            int d;
            cin >> d;
            pair<int,int> p = coord(n, d);
            cout << p.first << " " << p.second << endl;
        }
    }
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
