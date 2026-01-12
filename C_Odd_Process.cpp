#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int>arr(n);
    vector<int>odds,evens;
    for(auto &a:arr){
        cin>>a;
        if(a%2) odds.push_back(a);
        else evens.push_back(a);
    }
    sort(odds.rbegin(),odds.rend());
    sort(evens.rbegin(),evens.rend());
    vector<ll>ans(n,0);
    if(odds.size()==0){
        for(auto a:ans) cout<<a<<" ";
        cout<<endl;
        return;
    }
    vector<ll>ps(n+1,0);
    int sze = evens.size();
    int szo = odds.size();
    for(int i=0;i<evens.size();i++) ps[i+1] = ps[i]+evens[i];
    for(int k=1;k<=n;k++){
        int req = 1;
        if(k>sze) req = k - sze;
        if(req%2==0) req++;
        if(req>k || req>szo) ans[k-1]= 0;
        else{
            ans[k-1] = odds[0] + ps[k-req];
        }
    }
    for(auto a:ans)cout<<a<<" ";
    cout<<endl;

}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}