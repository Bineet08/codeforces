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
    if(a<b) swap(a,b);
    if(a%b==0) return b;
    return gcd(b,a%b);
}

void solve() {
    // Write your code here
    int n;
    cin>>n;
    vector<int>p(n),s(n);
    bool isNO = false;
    for(auto &a:p) cin>>a;
    for(auto &a:s) cin>>a;
    if(p[n-1]!=s[0]) isNO = true;
    for(int i=0;i<n-1;i++){
        if(gcd(p[i],s[i])!=s[0] || gcd(p[i],s[i+1])!= s[0]) isNO = true;
        if(p[i]%p[i+1]!=0) isNO = true;
        if(s[i+1]%s[i]!=0) isNO = true;
        if(isNO){
            cout<<"NO"<<endl;
            return;
        }
    }
    if(gcd(p[n-1],s[n-1])!=s[0]){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
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