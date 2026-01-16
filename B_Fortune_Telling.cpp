#include <iostream>
#include<bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
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
     int n,x,y;
     cin>>n>>x>>y;
     vector<int>arr(n);
     for(auto &a:arr) cin>>a;
     int oddCount = 0;
     for(auto &a:arr){
        if(a%2==1) oddCount++;
     }
     int alice = x%2;

     int a;
     if(oddCount %2==0){
        a = alice;
     }
     else{
        a = 1 - alice;
     }

     if(y%2==a) cout<<"Alice"<<endl;
     else cout<<"Bob"<<endl;
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