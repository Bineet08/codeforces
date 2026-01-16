#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);

int T;
cin>>T;
while(T--){
int n,k;
cin>>n>>k;
vector<ll>p(n);
for(int i=0;i<n;i++)cin>>p[i];
vector<int>d(n);
for(int i=0;i<n;i++)cin>>d[i];

int S=n*2*k;
vector<int>out_dest(S,-1);
vector<vector<int>>rev(S);

auto state_id = [&](int idx,int dir_idx,int r){
return (idx*2+dir_idx)*k+r;
};

for(int i=0;i<n;i++){
for(int dir_idx=0;dir_idx<2;dir_idx++){
int dir=dir_idx==0?+1:-1;
for(int r=0;r<k;r++){
int sid=state_id(i,dir_idx,r);
int nd=(r==d[i]?-dir:dir);
int ndir_idx=(nd==+1?0:1);
int j=i+nd;
if(j<0||j>=n){
out_dest[sid]=-1;
}else{
ll dist=llabs(p[j]-p[i]);
int r2=int((r+(dist%k))%k);
int nid=state_id(j,ndir_idx,r2);
out_dest[sid]=nid;
rev[nid].push_back(sid);
}
}
}
}

vector<char>good(S,0);
queue<int>bfs;
for(int sid=0;sid<S;sid++){
if(out_dest[sid]<0){
good[sid]=1;
bfs.push(sid);
}
}
while(!bfs.empty()){
int u=bfs.front();bfs.pop();
for(int v:rev[u]){
if(!good[v]){
good[v]=1;
bfs.push(v);
}
}
}

int Q;
cin>>Q;
while(Q--){
ll x;
cin>>x;
auto it=lower_bound(p.begin(),p.end(),x);
if(it==p.end()){
cout<<"YES\n";
}else{
int idx=int(it-p.begin());
ll dist=llabs(p[idx]-x);
int r0=int(dist%k);
int sid=state_id(idx,0,r0);
cout<<(good[sid]?"YES\n":"NO\n");
}
}
}
return 0;
}