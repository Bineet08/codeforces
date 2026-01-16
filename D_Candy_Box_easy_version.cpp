#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}

void solve() {
     // Cursor position after snippet insertion
     int n;
     cin>>n;
     vector<int> arr(n,0);
     for(auto &a:arr) cin>>a;
     sort(arr.begin(),arr.end());
     vector<int> freq;
     vector<bool>pres(n+1,false);
     int count = 0;
     int prev = arr[0];
     for(int i=0;i<n;i++){
        if(prev == arr[i]) count++;
        else{
            freq.push_back(count);
            prev = arr[i];
            count = 1;
        }
     }
     freq.push_back(count);
     sort(freq.rbegin(),freq.rend());
     int s = freq.size();
     int i=0;
     while(i<s){
        if(pres[freq[i]]==false) pres[freq[i]] = true;
        else{
            int j = freq[i];
            while(j>0){
                if(pres[j]) j--;
                else {
                    pres[j] = true;
                    break;
                }
            }
            
        }
        i++;
     }
     int res = 0;
     for(int i=0;i<=n;i++){
        if(pres[i]) res += i;
     }
     cout<<res<<endl;
     
}

int32_t main() {
    fast_io();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}