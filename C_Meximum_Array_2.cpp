#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

void solve() {
    int n,k,q;
    cin>>n>>k>>q;
    vector<int>res(n,0);
    vector<pair<int,int>> one,two;
    while(q--){
        int x;
        cin>>x;
        int a,b;
        cin>>a>>b;
        a-=1;
        b-=1;
        if(x==1){
            one.push_back({a,b});
        }
        else two.push_back({a,b});
    }
    for(auto [x,y]:one){
        for(int i=x;i<=y;i++){
            res[i] = k;
        }
    }
    //sort(two.begin(),two.end());
    for(auto [x,y]:two){
        int j = 0;
        for(int i=x;i<=y;i++){
            if(res[i]==k) res[i]++;
            else{
                res[i] = j;
                if(res[i]==k) res[i]++;
                j++;
            }
        }
    }
    for(auto a:res) cout<<a<<" ";
    cout<<endl;
    
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
