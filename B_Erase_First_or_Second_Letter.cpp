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
    int n;
    cin >> n;

    string str;
    cin>>str;

    vector<int>freq(26,0), pos(n,0);
    int cnt = 0;
    int i=0;
    for(auto a:str){
        freq[a-'a']++;
        if(freq[a-'a']==1) cnt ++;
        pos[i] = cnt;
        i++;
    }

    int res = accumulate(pos.begin(),pos.end(),0);
    cout<<res<<endl;

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