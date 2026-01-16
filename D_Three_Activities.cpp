#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

vector<int> topThree(vector<int>&arr){
    vector<int>res(3);
    int n = arr.size();
    vector<pair<int,int>>temp(n);
    for(int i=0;i<n;i++){
        temp[i] = make_pair(arr[i],i);
    }
    sort(temp.rbegin(),temp.rend());
    for(int i=0;i<3;i++)res[i] = temp[i].second;
    return res;
}

void solve() {
    int n;
    cin>>n;
    vector<int>a(n), b(n), c(n);
    for(auto &x:a) cin>>x;
    for(auto &x:b) cin>>x;
    for(auto &x:c) cin>>x;
    vector<int>maxA = topThree(a),maxB = topThree(b), maxC = topThree(c);
    int ans = 0;
    for(auto &x:maxA){
        for(auto &y:maxB){
            for(auto &z:maxC){
                if(x==y || y==z || z==x) continue;
                ans = max(ans,a[x]+b[y]+c[z]);
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