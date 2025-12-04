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
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    vector<int>ps(n+1,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        ps[i+1] = ps[i] + arr[i];
    }
    int p = 0;
    int i=0;
    while(i<n-k+1){
        if(ps[i]==ps[i+k]){
            p+=1;
            i+=k+1;
        }
        else i++;
    }
    cout<<p<<endl;
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