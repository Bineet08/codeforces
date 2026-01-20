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

    long long ans = 0;
    long long sum = 0;
            int maxm = 0;
            for(auto &a:arr){
                maxm = max(maxm,a);
                sum += maxm;
            }
            ans=sum;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(arr[i],arr[j]);
             sum = 0;
             maxm = 0;
            for(auto &a:arr){
                maxm = max(maxm,a);
                sum += maxm;
            }
            ans = max(ans,sum);
            swap(arr[i],arr[j]);
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