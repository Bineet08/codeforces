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


vector<int> fab(11);

void solve() {
    // Write your code here
    int n,m;
    cin>>n>>m;
    vector<int>minL(m,0);
    vector<int> maxL(m,0);
    vector<vector<int>> box(m,vector<int>(3));
    for(int i=0;i<m;i++){
        cin>>box[i][0]>>box[i][1]>>box[i][2];
        minL[i] = min(box[i][0],min(box[i][1],box[i][2]));
        maxL[i] = max(box[i][0],max(box[i][1],box[i][2]));
    }
    string res="";
    int cubeL = fab[n-1];
    int cubew = fab[n-1]+ fab[n-2];
    for(int i=0;i<m;i++){
        if(minL[i]>=cubeL && maxL[i] >=cubew) res.push_back('1');
        else{
            res.push_back('0');
        }
    }
    cout<<res<<endl;
}

int32_t main() {
    fastio;
    int t = 1;
    cin >> t; // For multiple test cases
    fab[0] = 1;
    fab[1] = 2;
    for(int i=2;i<11;i++){
        fab[i] = fab[i-1] + fab[i-2];
    }
   while (t--) {
        solve();
    }
    return 0;
}