#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

#define MAX_N 100050
#define MAX_E 1000050
#define MAX_R 1000050

/***find union set****/
int par[MAX_N];
int rank[MAX_N];

void init(int n){
	for(int i=0;i<n;i++){
		par[i]=i;
		rank[i]=0;
	}
}
//find root
int find(int x){
	if(par[x]==x)return x;
	else return par[x]=find(par[x]);
}

void unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y)return;
	if(rank[x]<rank[y]){
		par[x]=y;
	}
	else{
		par[y]=x;
		if(rank[x]==rank[y])rank[x]++;
	}
}
bool same(int x,int y){
	return find(x)==find(y);
}

struct edge{int u,v,cost;};
bool comp(const edge& e1,const edge& e2){
	return e1.cost<e2.cost;
}

/***kruskal*****/
edge es[MAX_E];
int V,E;

int kruskal(){
	sort(es,es+E,comp);
	init(V);
	int res=0;
	for(int i=0;i<E;i++){
		edge e=es[i];
		if(!same(e.u,e.v)){
			unite(e.u,e.v);
			res+=e.cost;
		}
	}
	return res;
}

/*****solve problem*******/
int N,M,R;
int x[MAX_R],y[MAX_R],d[MAX_R];

void solve(){
	V=N+M;
	E=R;
	for(int i=0;i<R;i++){
		es[i]=(edge){x[i],N+y[i],-d[i]};
	}
	cout<<10000*(N+M)+kruskal()<<endl;
}
int main(){
	int T;
	cin>>T;
	while(0!=T--){
		scanf("%d%d%d",&N,&M,&R);
		//cin>>N>>M>>R;
		for(int i=0;i<R;i++){
			//cin>>x[i]>>y[i]>>d[i];
			scanf("%d%d%d",&x[i],&y[i],&d[i]);
		}
		solve();
	}
	return 0;
} 
