#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    long long ans = 0;
    vector<long> v;
    for(long p = 0; p < s.size(); p++){
        if(s[p] == '('){v.push_back(p);}
        else if(s[p] == ')'){ans += p - v.back(); v.pop_back();}
        else if(v.empty()){v.push_back(p);}
        else{ans += p - v.back(); v.pop_back();}
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}