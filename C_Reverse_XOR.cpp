#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}
string toBinary(int n){
    string str="";
    while(n>0){
        str += ((n%2)+'0');
        n /= 2;
    }
    reverse(str.begin(),str.end());
    return str;
}

bool isPal(string str, int j){
    int i=0;
    while(i<j){
        if(str[i]!=str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
void solve() {
     // Cursor position after snippet insertion
    int n;
    cin>>n;
    int count = 0;
    string str = toBinary(n);
    int i=0, j = str.size()-1;
    int countOne= 0;
    for(auto a:str) if(a=='1') countOne++;
    while(j>0 && str[j]=='0') j-=1;
    if(isPal(str,j) && countOne%2==0)
    cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return ;
}

int32_t main() {
    fast_io();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}