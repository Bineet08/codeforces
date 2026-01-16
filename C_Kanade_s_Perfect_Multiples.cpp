#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(auto &a:arr) cin>>a;
    sort(arr.begin(),arr.end());
    vector<int>ans;
    set<int>st(arr.begin(),arr.end());
    vector<bool> visited(k+1,false);
    for(int i=k-1;i>0;i--){
        if(st.count(i) && !visited[i]){
            res.push_back(i);
            for(int j=i;j<=k;j+=i) visited[j]=true;
        }
    }
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}