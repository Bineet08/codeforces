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
    vector<int>height(n);
    for(auto &a:height){
        cin>>a;
    }
    int maxm = *max_element(height.begin(),height.end());
    int r = height[k-1];
    if(maxm == r){
        cout<<"YES"<<endl;
        return;
    }
    sort(height.begin(),height.end());
    height.push_back(-1);
    vector<int> temp;
    for(int i=0;i<n;i++){
        if(height[i]==height[i+1]) continue;
        temp.push_back(height[i]);
    }
    for(int i=1;i<temp.size();i++){
        if(temp[i]>(temp[i-1]+r)){
            cout<<"NO"<<endl;
            return;
        }
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