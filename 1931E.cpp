#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n,0);
    for(auto &a:arr) cin>>a;
    int digs = 0;
    vector<int>zeros(n,0);
    for(int i=0; i<n;i++){
        while(arr[i]%10==0){
            digs ++;
            arr[i] /= 10;
            zeros[i] ++;
        }
        digs += floor(log10(arr[i])+1);
    }
    sort(zeros.begin(),zeros.end(),greater<int>());
    for(int i=0;i<n;i+=2){
        digs -= zeros[i];
    }
    if(digs>k) cout<<"Sasha"<<endl;
    else cout<<"Anna"<<endl;
    return;

}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}