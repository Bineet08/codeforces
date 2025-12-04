#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &a:arr) cin>>a;
    int x = INT_MAX, y = INT_MAX;
    int ans = 0;
    for(auto &a:arr){
        if(x>y) swap(x,y);
        if(x>=a){
            x = a;
        }
        else if(y>=a){
            y = a;
        }
        else{
            x = a;
            ans++;
        }
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}