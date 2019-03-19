#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N 65534
#define MAX_M 65534

int n,m;
int heads[MAX_N],knights[MAX_M];

void solve(){
 sort(heads,heads+n,greater<int>());
 sort(knights,knights+m,greater<int>());
 int ans=0;
 int i=n-1;
 for(;i>=0;i--){
  while(m>=0){
   if(heads[i]>knights[m-1]){
    m--;continue;
   }
   else{
    ans+=knights[m-1];
    m--;
    break;
   }
  }//while
  if(m<0)break;
 }
 if(m>=0)cout<<ans<<endl;
 else cout<<"Loowater is doomed!"<<endl;
}

int main(){
 
 while(1){
  cin>>n>>m;
  if(n==0&&m==0)break;
  for(int i=0;i<n;i++){
   cin>>heads[i];
  }
  for(int i=0;i<m;i++){
   cin>>knights[i];
  }
  solve();
 }

return 0;
}
