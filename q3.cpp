#include <bits/stdc++.h>
using namespace std;
#define int long long  

void solve() {
    int n;
    cin >> n;
    vector<int> p(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    
    vector<int> d(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    
    vector<int> cycleId(n+1, 0);
    vector<int> cycleLen;
    int id = 0;
    vector<bool> visited(n+1, false);
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            id++;
            int cur = i;
            int len = 0;
            while (!visited[cur]) {
                visited[cur] = true;
                cycleId[cur] = id;
                len++;
                cur = p[cur];
            }
            cycleLen.push_back(len);
        }
    }
    
    int T = n;
    vector<bool> intact(id+1, true);
    
    for (int i = 1; i <= n; i++) {
        int pos = d[i];
        if (p[pos] != 0) {
            int cid = cycleId[pos];
            if (intact[cid]) {
                intact[cid] = false;
                T -= cycleLen[cid-1];
            }
            p[pos] = 0;
        }
        cout << (n - T) << " ";
    }
    cout << "\n";
}

int32_t main() {  
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;  
}
