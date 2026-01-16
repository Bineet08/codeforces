#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

void solve() {
    int n;
    cin>>n;
    string str;
    cin>>str;
    vector<bool>visited(n+1,false);
    long long ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j*i<=n;j++){
            if(str[i*j-1]=='1') break;
            else{
                if(visited[i*j-1]) continue;
                visited[i*j-1] = true;
                ans += i;
            }
        }
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