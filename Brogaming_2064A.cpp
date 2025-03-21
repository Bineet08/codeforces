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
    int n=1;
    cin>>n;
    string str;
    cin>>str;
    int changing = 0;
    for(int i=1;i<n;i++){
        if(str[i-1]!=str[i]) changing+=1;
    }
    if(str[0]=='1') cout<<changing+1<<endl;
    else cout<<changing<<endl;
    return;
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