#include <bits/stdc++.h>
using namespace std;

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
    int n=1;
    cin>>n;
    vector<int>d(n);
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    vector<int>l(n),r(n);
    for(int i=0;i<n;i++){
        cin>>l[i]>>r[i];
    }
    int h=0;
    stack<int>st;
    for(int i=0;i<n;i++){
        if(d[i]==1)h+=1;
        else if(d[i]==-1) st.push(i);
        while(!st.empty() && h<l[i]){
            d[st.top()]=1;
            st.pop();
            h+=1;
        }
        if(h<l[i] || h>r[i]) {
            cout<<-1<<endl;
        return;
        }

    }
    while(!st.empty()){
        d[st.top()]=0;
        st.pop();
    }
    h=0;
    for(int i=0;i<n;i++){
        if(d[i]==1)h+=1;
        if(h<l[i] || h>r[i]){
            cout<<-1<<endl;
            return;
        }
    }
    for(int i=0;i<n;i++){
        cout<<d[i]<<" ";
    }
    cout<<endl;
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