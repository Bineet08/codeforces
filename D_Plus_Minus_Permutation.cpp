#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

int hcf(int x,int y){
    if(x>y) return hcf(y,x);
    if(y%x==0) return x;
    return hcf(y%x,x);
}

long long sum(long long a,long long b){
    return (1LL*(a+b)*(-a+b+1))/2;
}

void solve() {
    int n,x,y;
    cin>>n>>x>>y;
    int a = n/x;
    int b = n/y;
    long long l = 1LL*x*y/hcf(x,y);
    long long ans = 0;
    ans = sum(n-a+n/l+1,n) - sum(1LL,b-n/l);
    cout<< ans<<endl;

}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}