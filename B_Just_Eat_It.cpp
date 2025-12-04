#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}

void solve() {
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &a:arr) cin>>a;
    int maxm = 0;
    int total = 0;
    int curr = 0;
    for(int i=0;i<n-1;i++){
        int a = arr[i];
        curr += a;
        if(curr < 0){
            curr = 0;
        }
        maxm = max(maxm,curr);
        total += a;
    }
    total += arr[n-1];
    curr = 0;
    for(int i=1;i<n;i++){
        curr += arr[i];
        if(curr<0){
            curr = 0;
        }
        maxm = max(maxm,curr);
    }
    if(maxm<total) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int32_t main() {
    fast_io();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}