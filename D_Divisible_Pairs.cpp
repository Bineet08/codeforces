#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

void solve() {
    int n,x,y;
    cin>>n>>x>>y;
    vector<int>arr(n,0);
    for(auto &a:arr) cin>>a;
    map<int,vector<int>>mpy;
    for(int i=0;i<n;i++){
       mpy[arr[i]%y].push_back(arr[i]); 
    }
    int ans = 0;
    for(auto &it:mpy){
        vector<int> curr = it.second;
        map<int,int>mpx;
        for(auto &a:curr) mpx[a%x]++;
        for(auto it:mpx){
            if(it.first==0 || (it.first==x/2 && x%2==0)){
                int cnt = it.second;
                ans += (cnt*(cnt-1))/2;
                it.second = 0;
            }
            else{
                int cnt1 = it.second;
                int cnt2 = mpx[x-it.first];
                ans += cnt1*cnt2;
                mpx[x-it.first]=0;
            }
        }
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