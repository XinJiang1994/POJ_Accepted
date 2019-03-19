#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

#define MAX_N 10001

int R,n;
int troops[MAX_N];

void solve(){
 sort(troops,troops+n);
 int ans=0;
 int i=0;
 while(i<n){
  int s=i;
  while(i<n&&(troops[i]-troops[s]<=R))i++;
  ans++;
  s=i-1;
  while(i<n&&(troops[i]-troops[s]<=R))i++;
 }
 cout<<ans<<endl;
}

int main(){
 while(1){
  cin>>R>>n;
  if(R==-1&&n==-1)break;
  for(int i=0;i<n;i++)cin>>troops[i];
  solve();
 }
 return 0;
}
