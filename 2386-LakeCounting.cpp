#include<iostream>
#include<cstdio>
using namespace std;
#define MAX_N 10000
#define MAX_M 10000

int N=0,M=0;
char field[MAX_N][MAX_M];

void dfs(int x,int y){
  field[x][y]='.';
  for(int dx=-1;dx<=1;dx++)
   for(int dy=-1;dy<=1;dy++){
    int nx=x+dx,ny=y+dy;
    if(nx>=0&&nx<N&&ny>=0&&ny<M&&field[nx][ny]=='W')dfs(nx,ny);   
   }
   return;
}

void solve()
{
 int pond_num=0;
 for(int i=0;i<N;i++)
  for(int j=0;j<M;j++)
  {
    if(field[i][j]=='W'){
      dfs(i,j);
      pond_num++;
    }
  }
 printf("%d",pond_num);
}

int main()
{
  cin>>N>>M;
  for(int i=0;i<N;i++)
   for(int j=0;j<M;j++)
   {
     cin>>field[i][j];
   }
  solve();
return 0;
}
