#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int>arr(n);
    priority_queue<int,vector<int>,greater<>>pq;
    for(auto &a:arr){
        cin>>a;
        pq.push(a);
    }
    int top1 = pq.top();
    pq.pop();
    int top2 = pq.top();
    pq.pop();
    cout<<max(top1,top2-top1)<<endl;
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}