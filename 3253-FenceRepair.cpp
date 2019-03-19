#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX_N 65534

typedef long long ll;

int n;
int L[MAX_N];

void solve(){
 ll ans=0;
 while(n>1){
  int mii1=0,mii2=1;
  if(L[mii1]>L[mii2])swap(mii1,mii2);
  for(int i=2;i<n;i++){
   if(L[mii1]>L[i]){
     mii2=mii1;
     mii1=i;
     }
   else if(L[mii2]>L[i])mii2=i;
  }
  int t=L[mii1]+L[mii2];
  ans+=t;
  if(mii1==n-1)swap(mii1,mii2);
  L[mii1]=t;
  L[mii2]=L[n-1];
  n--;
 }
 printf("%lld\n",ans);
}

int main(){
cin>>n;
for(int i=0;i<n;i++){
 cin>>L[i];
}
solve();
return 0;
}
