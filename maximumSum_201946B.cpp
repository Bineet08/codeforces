#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mod = 1000000007;
void solve(){
    int n,k;
    cin>>n>>k;
    bool allPos=true;
    bool allNeg = true;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]<0) allPos = false;
        if(arr[i]>0) allNeg = false;
    }
    if(allPos){
        int sum=0;
        int m=1;
        int s=1;
        while(k--){
            s+=m;
            m*=2%Mod;
            s = s%Mod;
        }
        for(auto x:arr) sum = (sum+x)%Mod;
        cout<<(m*sum)%Mod<<endl;
        return ;
    }
    else if(allNeg){
        int sum = 0;
        for(auto x:arr) sum= (sum+x)%Mod;
        while(sum<0) sum+=Mod;
        cout<< (sum)%Mod <<endl;
        return;
    }
    else{
        int maxPos = 0;
        int pos = 0;
        int sum =0;
        for(auto x:arr){
            pos+=x;
            maxPos=max(pos,maxPos);
            if(pos<0) pos=0;
            sum+=x;
        }
        int i=1;
        while(k--){
            sum += ((maxPos+pos)*i);
            i*=2;
        }
        cout<<(sum+Mod)%Mod<<endl;
        return;
    }
}

int32_t main(){
   int t;
   cin>>t;
   while(t--) solve();
    return 0;
 }