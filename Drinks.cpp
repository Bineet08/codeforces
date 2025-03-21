#include<iostream>
#include <iomanip>
using namespace std;

int main(){
int n;
cin>>n;
int drink[n];
int res = 0;
for(int i=0;i<n;i++){
cin>>drink[i];
res+=drink[i];
}
float x = res/n;
cout<<setprecision(5)<<x;
}
