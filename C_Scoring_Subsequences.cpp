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
    vector<int>res;
    for(int i=0;i<n;i++){
        int l=1, r = i+1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(arr[i-mid+1]>=mid) l = mid+1;
            else r = mid-1;
        }
        res.push_back(r);
    }
    for(auto a:res) cout<<a<<" ";
    cout<<endl;
    return;
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