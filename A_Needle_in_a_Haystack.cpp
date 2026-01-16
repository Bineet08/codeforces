#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

void solve() {
    string s,t;
    cin>>s>>t;
    vector<int>freqS(26,0);
    vector<int>freqT(26,0);
    for(auto a:s) freqS[a-'a']++;
    for(auto a:t) freqT[a-'a']++;
    for(int i=0;i<26;i++){
        freqT[i] -= freqS[i];
        if(freqT[i]<0){
            cout<<"Impossible"<<endl;
            return;
        }
    }
    int x = s.size();
    string ans="";
    int j = 0;
    for(int i=0;i<26;i++){
        if(j==x){
            while(freqT[i]>0){
                ans.push_back('a'+i);
                freqT[i]--;
            }
            continue;
        }

        while(j<x && s[j]<=('a'+i)){
            ans.push_back(s[j]);
            j++;
        }
        while(freqT[i]>0){
            ans.push_back('a'+i);
            freqT[i]--;
        }

    }
    cout<<ans<<endl;
    return;
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}