#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
#define MAX_N 10001

int N,L,P;
int dis[MAX_N],fuel[MAX_N];
pair<int,int> stops[MAX_N];
bool cmp(pair<int,int> a, pair<int,int> b){
 return a.first<b.first;
} 

void solve(){
 sort(stops,stops+N,cmp);
 int tank=P,ans=0,pos=0;
 priority_queue<int> pque;
 stops[N].first=L;
 stops[N].second=0;
 for(int i=0;i<=N;i++){ 
  int d=stops[i].first-pos; 
  while(tank<d){
  	if(pque.empty()){
  		cout<<-1<<endl;
  		return;
	  }
 	tank+=pque.top();
 	pque.pop();
 	ans++;
  }
  pque.push(stops[i].second);
  pos+=d;
  tank-=d;
 } 
 cout<<ans;
}

int main(){
 cin>>N;
 for(int i=0;i<N;i++){
  cin>>dis[i]>>fuel[i];
 }
 cin>>L>>P;
 for(int i=0;i<N;i++){
  stops[i].first=L-dis[i];
  stops[i].second=fuel[i];
 }
 solve(); 
return 0;
}
