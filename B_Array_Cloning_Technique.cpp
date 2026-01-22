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

    unordered_map<int,int>mp;
    for(auto x:arr) mp[x]++;

    int maxFreq= 0;
    for(auto it:mp){
        maxFreq = max(maxFreq,it.second);
    }

    long long curr = maxFreq;
    long long ans = 0;
    while(curr<n){
        ans++;
        if(2*curr <= n){
            ans += curr;
            curr *= 2;
        }
        else{
            ans += n-curr;
            break;
        }
    }
    cout<<ans<<endl;

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