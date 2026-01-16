#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

void solve() {
    int n;
    cin>>n;
    // for(int i=n/2;i>0;--i){
    //     if((n-i)%i==0){
    //         cout<<i<<" "<<n-i<<endl;
    //         return;
    //     }
    // }
    // return;

    int ans = 1;
    int sq = sqrt(n);
    for(int i=2;i<=sq;i++){
        if(n%i==0){
            ans = n/i;
            break;
        }
    }
    cout<<ans<<" "<<n-ans<<endl; 
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}