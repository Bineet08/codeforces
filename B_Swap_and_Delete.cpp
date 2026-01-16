#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second

const ll INF = 1e18;
const int MOD = 1e9 + 7;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << '\n';
#else
#define debug(x)
#endif

void solve() {

    string str;
    cin>>str;
    int n = str.size();
    int cnt0 = 0, cnt1 = 0;
    for(auto a:str){
        if(a=='0') cnt0++;
        else cnt1++;
    }
    int t = 0;
    for(auto a:str){
        if(a=='0' && cnt1>0){
            cnt1--;
            t++;
        }
        else if(a=='1' && cnt0>0){
            cnt0--;
            t++;
        }
        else break;
    }
    cout<<n-t<<endl;
    return;

}

int main() {
    fastio;

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}