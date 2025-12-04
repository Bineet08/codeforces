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
    int n,k;
    cin>>n>>k;
    int week = n-k+1;
    vector<int>arr(n);
    int sum = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<k;i++) sum += arr[i];
    int l=0, r = k;
    int curr=  sum;
    while(r<n){
        curr += arr[r];
        curr -= arr[l];
        l++;
        r++;
        sum += curr;
    }

    double ans = (double)sum/week;
    cout<<fixed<<setprecision(10)<<ans;
}

int32_t main() {
    fast_io();
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}