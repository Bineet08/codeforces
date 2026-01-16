#include<iostream>
using namespace std;

void solve(){
    int l,r;
    cin>>l>>r;
    for(int g =2;g<=r/2;g++){
        int minsum = ((l+g-1)/g)*g;
        if(minsum>r) continue;
        int total = minsum;
        int a=g, b =total-g;
        if(b>0) cout<<a<<' '<<b<<endl;
        return;
    }
    cout<<-1<<endl;
    return;
}

int main(){
    int t=0;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}