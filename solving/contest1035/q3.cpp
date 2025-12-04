#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define int long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define ff first
#define ss second

const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve() {
    // Write your code here
    int n;
    cin>>n;
    int l,r,k;
    cin>>l>>r>>k;
    if(n==1){
        cout<<l<<endl;
        return;
    }
    else if(n==2){
        cout<<-1<<endl;
        return;
    }
    else if(n%2==1){
        if(k<=n) cout<<l<<endl;
        else cout<<-1<<endl;
        return;
    }
    else{
       ull x = l;
      while(1){
                    bool check=1;
                    for(int i=0;i<64;i++){
                        ull b=1ULL<<i;
                        if((l&b) && (x&b)){
                            x+=b;
                            x&=~(b-1);
                            check=0;
                            break;
                        }
                    }
                    if(check) break;
                }
 
if(x<=r){
    if(k<=n-2) cout<<l<<"\n";
    else cout<<x<<"\n";
}
else cout<<-1<<endl;
    }
    return;
}

int32_t main() {
    fastio;
    int t = 1;
    cin >> t; // For multiple test cases
    while (t--) {
        solve();
    }
    return 0;
}