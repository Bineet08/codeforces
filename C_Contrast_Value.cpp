#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &a:arr) cin>>a;
    if(n==1) {
        cout<<1<<endl;
        return;
    }
    vector<int>b;
    b.push_back(arr[0]);
    b.push_back(arr[1]);
    for(int i=2;i<n;i++){
        int sz = b.size();
        if(arr[i]==b[sz-1]) continue;
        if(b[sz-1]>b[sz-2]){
            if(arr[i]>b[sz-1]) b[sz-1] = arr[i];
            else b.push_back(arr[i]);
        }
        else{
            if(arr[i]<b[sz-1]) b[sz-1] = arr[i];
            else b.push_back(arr[i]);
        }
    }
    int ans = b.size();
    if(b[0]==b[1]) ans--;
    cout<<ans<<endl;
    return;
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}