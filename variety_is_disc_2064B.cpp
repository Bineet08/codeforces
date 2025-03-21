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
    int n=1;
    cin>>n;
    unordered_map<int,int> freq;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        freq[arr[i]]+=1;
    }
    int l=0,r=0,max_len=0, curr=0;
    for(int i=0;i<n;i++){
        if(freq[arr[i]]==1) curr+=1;
        else curr = 0;
        if(curr>max_len){
            max_len = curr;
            r= i;
            l = i-curr+1;
        }
    }
    if(max_len==0) cout<<0<<endl;
    else cout<<l+1<<" "<<r+1<<endl;
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