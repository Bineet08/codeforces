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
    int n;
    cin>>n;
    vector<int>a(n), b(n);
    for(auto &x:a) cin>>x;
    int count =0;
    for(int i=0;i<n;i++){
        cin>>b[i];
        if(a[i]==b[i]) {
            count++;
        }
    }
    if(count>1){
        cout<<-1<<endl;
        return;
    }
    vector<pair<int,int>>ans;
    for(int i=0;i<n/2;++i){
        int j = n-i-1;
        if(a[i]==b[j] && b[i]==a[j]) continue;
        bool p =false;
        for(int k=i+1;k<n;++k){
            
            if(a[k]==b[j] && b[k]==a[j]){
                ans.push_back({i+1,k+1});
                swap(a[i],a[k]);
                swap(b[i],b[k]);
                p = true;
                break;
            }
        }
        if(!p){
            cout<<-1<<endl;
            break;
        }
    }
    cout<<ans.size()<<endl;
    for(auto it:ans) cout<<it.first<<" "<<it.second<<endl;
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
