#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

int solving(int n,int a,int b){
    int g = gcd(n, b);
    return a + ((n - 1 - a) / g) * g;
}

void solve() {
    int l,a,b;
    cin>>l>>a>>b;
    cout<<solving(l,a,b)<<endl;
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}