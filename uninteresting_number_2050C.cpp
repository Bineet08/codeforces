#include <bits/stdc++.h>
#define int long long
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define int long long

bool solve(string num) {
   int sum = 0;
   int count2=0,count3 = 0;
   for(auto &a:num){
    sum+=(a-'0');
    if(a=='2') count2+=1;
    else if(a=='3') count3+=1;
    sum%=9;
   }
   for(int i=0;i<=count3;i++){
    for(int j=0;j<=count2;j++){
        int tsum = sum;
        tsum += j*2 + i*6;
        if(tsum%9==0)return true;
    }
   }
   return false;
}

int32_t main() {
    fastio;
    int t;
    cin >> t;
    while (t--){
        string n;
        cin>>n;
     if(solve(n)) cout<<"YES"<<endl;
     else cout<<"NO"<<endl;
    }
    return 0;
}