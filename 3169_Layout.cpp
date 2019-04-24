#include<iostream>
using namespace std;
#define INF 0x7ffffff
#define MAX_N 1001
#define MAX_ML 1000001
#define MAX_MD 1000001
struct edge{
	int from,to,cost;
}; 
int N,ML,MD;
int AL[MAX_ML],BL[MAX_ML],DL[MAX_ML];
int AD[MAX_MD],BD[MAX_MD],DD[MAX_MD];
int d[MAX_N];
bool updated;
void update(int& x,int y){
	if(x>y){
		x=y;
		updated=true;
	}
}

//belman-ford
void bellmanford(){
	for(int k=0;k<=N;k++){
		updated=false;
		for(int i=0;i+1<N;i++){
			if(d[i+1]<INF)update(d[i],d[i+1]);
		}
		for(int i=0;i<ML;i++){
			if(d[AL[i]-1]<INF)update(d[BL[i]-1],d[AL[i]-1]+DL[i]);
		}
		for(int i=0;i<MD;i++){
			if(d[BD[i]-1]<INF)update(d[AD[i]-1],d[BD[i]-1]-DD[i]);
		}
	}
}

void solve(){
	fill(d,d+N,0);
	bellmanford();
	if(updated){
		cout<<-1<<endl;
		return;
	}
	fill(d,d+N,INF);
	d[0]=0;
	bellmanford();
	if(INF==d[N-1])cout<<-2<<endl;
	else cout<<d[N-1];
}
 
int main(){
	cin>>N>>ML>>MD;
	for(int i=0;i<ML;i++){
		cin>>AL[i]>>BL[i]>>DL[i];
	}
	for(int i=0;i<MD;i++){
		cin>>AD[i]>>BD[i]>>DD[i];
	}
	solve();
	return 0;
}
