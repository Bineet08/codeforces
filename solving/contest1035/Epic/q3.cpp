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

int gcd(int a,int b){
    if(a%b==0) return b;
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}

void solve() {
    // Write your code here
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &a:arr) cin>>a;
    int ans=1;
    int cf = arr[0];
    for(int i=1;i<n;i++){
        cf = gcd(arr[i],cf);
    }
    for(int i=0;i<n-1;i++){
        int a = arr[i]/cf;
        int b =arr[i+1]/cf;
        int x = gcd(a,b);
        ans = lcm(ans,a/x);
    }
    cout<<ans<<endl;
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