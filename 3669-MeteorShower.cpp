#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
#define MAX_N 400
#define INF 2000
typedef pair<int, int> P;

int maze[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];
int dir[4][2]={
	{0,-1},
	{0,1},
	{-1,0},
	{1,0}
};

int bfs(){
	if(maze[0][0]==0)return -1;
	queue<P> que;
	que.push(P(0,0));
	dist[0][0]=0;
	while(!que.empty()){
		P p=que.front();
		que.pop();
		int x=p.first,y=p.second;
		if(maze[x][y]==INF){
			return dist[x][y];
		}
		for(int i=0;i<4;i++){
			int nx=x+dir[i][0],ny=y+dir[i][1];
			if(nx>=0&&ny>=0&&dist[nx][ny]==INF&&dist[x][y]+1<maze[nx][ny]){
				que.push(P(nx,ny));
				dist[nx][ny]=dist[x][y]+1;
			}
		}
	}
	return -1;
}
void solve(){
	for(int i = 0; i < MAX_N; i ++){
        fill(dist[i], dist[i] + MAX_N, INF);
	}
	int min_t=INF;
	min_t=bfs();
	printf("%d\n",min_t);
}

int main(){
	for(int i = 0; i < MAX_N; i ++){
		fill(maze[i], maze[i] + MAX_N, INF);
	}
	int T,x,y,t;
	scanf("%d", &T);
	for(int n=0;n<T;n++){
		scanf("%d%d%d",&x,&y,&t);
		maze[x][y]=min(maze[x][y],t);
		for(int d=0;d<4;d++){
			int nx=x+dir[d][0],ny=y+dir[d][1];
			if(nx>=0&&ny>=0){
				maze[nx][ny]=min(maze[nx][ny],t);	
			}
		}
	}
	solve();
	return 0;
}
