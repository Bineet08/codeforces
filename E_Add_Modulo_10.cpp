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
     vector<int> arr(n);
     for(auto &a:arr) cin>>a;
     for(auto &a:arr){
        if(a&1) a += a%10;
     }
     bool ans = true;
     bool zero = (arr[0]%10==0);
     for(int i=1;i<n;i++){
        if(arr[i]!=arr[i-1]){
            ans = false;
            break;
        } 
    }
     if(ans){
        cout<<"Yes"<<endl;
        return;
     }

     for(auto &a:arr) if(a%10==0){
        cout<<"No"<<endl;
        return;
     }
     

     for(auto &a:arr){
        while(a%10!=2) a += a%10;
        a %= 20;
     }
     ans = true;
     for(int i=1;i<n;i++){
        if(arr[i]!=arr[i-1]){
            ans = false;
            break;
        } 
    }
     if(ans){
        cout<<"Yes"<<endl;
        return;
     }
     else cout<<"No"<<endl;
     return;

    

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