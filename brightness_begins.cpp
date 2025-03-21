#include<iostream>
using namespace std;
typedef long long ll;


void brightness(){
    auto sqrt =[&](ll x){
    ll l=0, r=2e9;
    while(l<r){
        ll mid = (l+r+1)/2;
        if(mid*mid <= x) l=mid ;
        else r = mid - 1;
    }
    return l;
    };
ll k;
cin>>k;
ll low= 1, high= 2e18;
while(low<high){
    ll mid = (low+high)/2;
    if(mid - sqrt(mid)< k) low=mid+1;
    else high =mid;
}
cout<<low<<endl;
}

int main(){
int t;
cin>>t;
while(t--){
    brightness();
}
}
