#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
int t;
cin>>t;
while(t--){
    int n,m;
    cin>>n>>m;
    int res=0;
    vector<string>str(n);
    for(int i=0;i<n;i++){
        cin>>str[i];
        if(m>0){
                m=m-str[i].size();
          if(m>=0)  res = i+1;
    }
}
cout<<res<<endl;
}
return 0;
}
