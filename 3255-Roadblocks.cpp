#include<iostream>
#include<queue>
using namespace std;
#define MAX_N 100005
const int INF = 0x3f3f3f3f;
typedef pair<int,int> P;

struct edge{
int to;
int cost;
};

int N,R;
vector<edge> G[MAX_N];
int dist1[MAX_N];
int dist2[MAX_N];

void solve(){
 priority_queue <P,vector<P>,greater<P> >que;
 fill(dist1,dist1+N,INF);
 fill(dist2,dist2+N,INF);
 dist1[0]=0;
 que.push(P(0,0));
 while(!que.empty()){
 	P p=que.top();que.pop();
 	int v=p.second,d=p.first;
 	if(d>dist2[v])continue;
 	for(int i=0;i<G[v].size();i++){
 		edge &e=G[v][i];
 		int d2=d+e.cost;
 		if(d2>dist2[e.to])continue;
 		if(dist1[e.to]>d2){
 			swap(dist1[e.to],d2);
 			que.push(P(dist1[e.to],e.to));
		 }
		if(dist2[e.to]>d2 && dist1[e.to]<d2){
			dist2[e.to]=d2;
			que.push(P(dist2[e.to],e.to));
		}
	 }
 }
 cout<<dist2[N-1]<<endl;
}

int main(){
 cin>>N>>R;
 for(int i=0;i<R;i++){
  int from,to,cost;
  cin>>from>>to>>cost;
  from--;to--;
  edge e;
  e.to=to;
  e.cost=cost;
  G[from].push_back(e);
  e.to=from;
  G[to].push_back(e); 
 }
 //cout<<G[0].size(); 
 solve();
 return 0;
} 
