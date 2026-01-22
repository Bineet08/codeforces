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
    int n;
    cin >> n;

    string str;
    cin>>str;
    int ans = 0;
    int cnt = 0;
    char curr = str[0];
    for(int i=0;i<n;i++){
        if(curr == str[i]) cnt ++;
        else{
            ans = max(ans,cnt);
            cnt = 1;
            curr = str[i];
        }
    }
    ans = max(ans,cnt);
    cout<<ans+1<<endl;
    

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