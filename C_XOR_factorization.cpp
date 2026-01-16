#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;

vector<int> solving(int n) {
    if (n & 1) {
        // n is odd
        return {n - 1, 1};
    } else {
        // n is even
        int msb = 1 << (31 - __builtin_clz(n));
        int a = msb - 1;
        int b = n ^ a;
        return {a, b};
    }
}


void solve() {
    int n,k;
    cin>>n>>k;
    if(k==1){
        cout<<n<<endl;
        return;
    }
    else if(k==2){
        cout<<0<<" "<<n<<endl;
        return;
    }
    if(k%2==0){
        vector<int>res = solving(n);
        cout<<res[0]<<" "<<res[1]<<" ";
        for(int i=0;i<k-2;i++){
            cout<<n<<" ";
        }
        cout<<endl;
        return;
    }
    else{
        for(int i=0;i<k;i++){
            cout<<n<<" ";
        }
        cout<<endl;
    }
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}