#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

void solve() {
    int n,q;
    cin>>n>>q;
    vector<ll>arr(n),queries(q);
    for(auto &a:arr) cin>>a;
    for(auto &a:queries) cin>>a;
    vector<ll>ps(n+1);
    ps[0] = 0;
    for(int i=0;i<n;i++){
        ps[i+1] = ps[i] + arr[i];
    }
    vector<ll>ans(q);
    vector<pair<ll,int>>p(q);
    for(int i=0;i<q;i++){
        p[i] = make_pair(queries[i],i);
    }
    sort(p.begin(),p.end());
    int i=0,j=0;
    while(i<q){
        while(j<n && p[i].first>=arr[j]) j++;
        int idx = p[i].second;
        ans[idx] = ps[j];
        i++;
    }
    for(auto a:ans) cout<<a<<" ";
    cout<<endl;
    
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}