#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &a:arr) cin>>a;
    int ans = 0;
    int largest = 0;
    for(auto a:arr){
        if(a<largest){
            ans++;
        }
        else largest = a;
    }
    cout<<ans<<endl;
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}