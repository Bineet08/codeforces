#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

void solve() {
    string str;
    int n;
    cin>>n;
    cin>>str;
    vector<int>ps(n+1,0),ss(n+1,0);
    unordered_set<char>s1,s2;
    for(int i=0;i<n;i++){
        s1.insert(str[i]);
        s2.insert(str[n-i-1]);
        ps[i+1] = s1.size();
        ss[n-i] = s2.size();
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans=max(ans,ps[i]+ss[i+1]);
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