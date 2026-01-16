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
    int n,x;
    cin>>n>>x;
    int i=0,j=n-1;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    while(i<n && arr[i]!=1) i++;
    while(j>=0 && arr[j]!=1) j-=1;
    if(j-i > x-1) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
    } 
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