#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int>inf(k),dist(k);
    for(auto &a:inf) cin>>a;
    sort(inf.begin(),inf.end());
    for(int i=0;i<k-1;i++){
        dist[i] =abs(inf[i+1] - inf[i]-1);
    }
    dist[k-1] = n - abs(inf[0] - inf[k-1])-1;
    sort(dist.rbegin(),dist.rend());
    int ans = 0;
    int days = 0;
    for(auto gap:dist){
        int curr = gap - 2*days;
        if(curr>0){
            ans++;
            curr -= 2;
            if(curr>0) ans+= curr;
            days+=2;
        }
    }
    cout<<n-ans<<endl;
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}