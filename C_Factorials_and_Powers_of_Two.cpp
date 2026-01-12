#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

void solve() {
    ll n;
    cin>>n;
    vector<ll> facts;
    facts.push_back(1);
    for(int i=2;i<15;i++){
        facts.push_back(1LL*facts[i-2]*i);
    }
    cout<<facts[14];
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}