#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);


const ll INF = 1e18;
const int MOD = 1e9 + 7;


void solve() {
    ll n,c;
    cin >> n>>c;

    vector<ll> arr(n);
    for (ll &x : arr){
        cin >> x;
    }
    ll l = 1, r = 1e9;
    ll ans=0;
    while(l<=r){
        ll mid = l + (r-l)/2;
        ll sum = 0;
        for(auto a:arr){
            sum += (a + 2LL*mid)*(a + 2LL*mid);
            if(sum>c) break;
        }
        if(sum<=c){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
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