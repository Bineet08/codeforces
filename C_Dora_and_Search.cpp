#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    int i=0, j= n-1;
    int currMin = 1, currMax = n;
    while(i<j){
        if(arr[i]==currMin){
            i++;
            currMin++;
        }
        else if(arr[i]==currMax){
            i++;
            currMax--;
        }
        else if(arr[j]==currMin){
            j--;
            currMin++;
        }
        else if(arr[j]==currMax){
            j--;
            currMax--;
        }
        else{
            cout<<i+1<<" "<<j+1<<endl;
            return;
        }
        }
    cout<<-1<<endl;
    return;
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}