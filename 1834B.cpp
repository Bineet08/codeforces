#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s,t;
    cin>>s>>t;
    string res;
    int m=s.size();
    int n=t.size();
    if(m>n){
        if(t[0]!='9')cout<<9*(m-1) + (s[0]-'0')<<endl;
        else cout<<9*(m-1) + (s[0]-'0') - 1<<endl;
        return;
    }
    else if(m<n){
        if(s[0]!='9') cout<<9*(n-1) + (t[0]-'0')<<endl;
        else cout<<9*(n-1) + (t[0]-'0') - 1 <<endl;
        return;
    }
    else{
        int i=0;
        while(i<m && s[i] == t[i]) i+=1;
        if(i==m) cout<<0<<endl;
        else{
            cout<<9*(m-1-i) + abs(s[i]-t[i])<<endl;
        }
        return;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}