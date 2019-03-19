#include<iostream>
#include<cstdio>
using namespace std;
#define MAX_N 150000

int par[MAX_N];
int rank[MAX_N];

void init(int n){
 for (int i=0;i<n;i++){
  par[i]=i;
  rank[i]=0;
 }
}
int find(int x){
 if(par[x]==x){
  return x;
 }
 else{
  return par[x]=find(par[x]);
 }
}
void unite(int x, int y){
 x=find(x);
 y=find(y);
 if(x==y)return;
 if(rank[x]<rank[y])par[x]=y;
 else{
  par[y]=x;
  if(rank[x]==rank[y])rank[x]++;
 }
}
bool same(int x, int y){
 return find(x)==find(y);
}

int N,K;
int T[MAX_N],X[MAX_N],Y[MAX_N];

void solve(){
 init(N*3);
 int ans=0;
 for(int i=0;i<K;i++){
  int t=T[i];
  int x=X[i]-1,y=Y[i]-1;
  if(x<0||x>=N||y<0||y>=N){
   ans++;
   //cout<<"1:"<<x<<" "<<y<<" "<<N <<endl; 
   continue;
  }
  if(1==t){
   if(same(x,y+N)||same(x,y+N*2)){
   	ans++;
   	//cout<<"2:"<<x<<" "<<y<<endl; 
   }
   else{
    unite(x,y);
    unite(x+N,y+N);
    unite(x+2*N,y+N*2);
   }
  }
  else{
   if(same(x,y)||same(x,y+N*2)){
   	ans++;
   	//cout<<"3:"<<x<<" "<<y<<endl;
   }
   else{
    unite(x,y+N);
    unite(x+N,y+N*2);
    unite(x+N*2,y);
   }
  }
 }
 cout<<ans<<endl;
}

int main(){
 cin>>N>>K;
 for(int i=0;i<K;i++){
  scanf("%d%d%d",&T[i],&X[i],&Y[i]);
 }
 solve();
return 0;
}
