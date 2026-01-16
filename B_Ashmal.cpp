#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

void solve() {
    int n; cin>>n;
    vector<string>strs(n);
    for(auto &s:strs) cin>>s;
    string res="";
    for(auto s:strs){
        string a = res+s;
        string b = s + res;
        if(a>=b) swap(a,b);
        res = a;
    }
    cout<<res<<endl;
    return;
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}