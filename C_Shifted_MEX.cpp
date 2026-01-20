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

    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    sort(all(arr));
    arr.erase(unique(all(arr)),arr.end());
    ll ans = 0, curr = 0;
    for(int i=0;i<(int)arr.size();i++){
        if(arr[i]-1==arr[i-1] || i==0) curr++;
        else{
            ans = max(ans,curr);
            curr = 1;
        }
    }
    ans = max(ans,curr);
    cout<<ans<<endl;
    return;

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