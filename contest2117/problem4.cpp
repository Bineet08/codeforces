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

bool isIncreasing(vector<int> arr){
    for(int i=1;i<arr.size();i++){
        if(arr[i]!=arr[0]*(i+1)) return false;
    }
    return true;
}

void solve() {
    // Write your code here
    int n=1;
    bool increasing = true;
    int a =INT_MIN;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(increasing){
            a=max(a,arr[i]);
            if(a!=arr[i]) increasing = false;
        }
    }
    if(!increasing) reverse(arr.begin(),arr.end());
    int diff = arr[1] - arr[0];
    diff = arr[0] - diff;
    if(diff%(n+1)!=0 || diff<0){
        cout<<"NO"<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        arr[i] -= diff;
    }
    if(isIncreasing(arr)) cout<<"YES"<<endl;
    else{
        cout<<"NO"<<endl;
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