#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

void solve() {
    string str;
    cin>>str;
    int n = str.size();
    for(int i=0;i<n-1;i++){
        if(str[i]==str[i+1]){
            if(i<n-2 && ((str[i+2]-'a')%26)!=((str[i]+1-'a')%26)) str[i+1] = 'a'+ ((str[i+1]-'a'+1)%26);
            else if(i<n-2 && ((str[i+2]-'a')%26)==((str[i]+1-'a')%26)) str[i+1] = 'a'+ ((str[i+1]-'a'+2)%26);
        }
    }
    if(n>1 && str[n-1]==str[n-2]) str[n-1] = 'a'+ ((str[n-1]-'a'+1)%26);
    cout<<str;
}

int main() {
    fastio;
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}