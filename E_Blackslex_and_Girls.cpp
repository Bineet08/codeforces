#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

void solve() {
    int n,x,y;
    cin>>n>>x>>y;
    string str;
    cin>>str;
    vector<int>arr(n);
    for(auto &a:arr){
        cin>>a;
    }
    int zeros = 0, ones = 0;
    for(auto c:str){
        if(c=='0') zeros++;
        else ones++;
    }
    ll sum = accumulate(arr.begin(),arr.end(),0LL);
    if(sum>1LL*(x+y)){
        cout<<"NO"<<endl;
        return;
    }
    int cnt= 0;
    ll m = 0;
    if(zeros==0){
        for(auto a:arr){
            m += (a-1)/2;
            if(a%2==0)cnt++;
        }
        int a = x+y-sum;
        int b = min(cnt,a);
        if(b%2 != a%2) b--;
        int c = (a+b)/2;
        if(x<=(m + c)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return;
    }
    else if(ones==0){
        for(auto a:arr){
            m += a/2 +1;
            if(a%2==0)cnt++;
        }
        int a = x+y - sum;
        int b = a - cnt;
        int z = 0;
        if(a-cnt>0) z = (a-cnt+1)/2;
        if(x>= (m+z)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return;
    }
    else{
        int a=0,b = 0;
        for(int i=0;i<n;i++){
            int d = arr[i]/2 +1;
            if(str[i]=='0') a+=d;
            else b+=d;

        }
        int c = x+y-b;
        if(x<=c && x>= a) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return;
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}