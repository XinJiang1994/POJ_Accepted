#include<iostream>
#include<cstdio>
using namespace std;
#define MAX_N 100000

int sam_num=0,l=0,n=0;
int ants[MAX_N];

void solve();

int main()
{
  cin>>sam_num;
  for(int i=0;i<sam_num;i++)
  {
     cin>>l>>n;
     for(int j=0;j<n;j++)
     {
       cin>>ants[j]; 
     }
     solve();
  }
  return 0;  
}

void solve()
{
  int minT=0;
  int maxT=0;
  for(int i=0;i<n;i++)
  {
    minT=max(minT,min(ants[i],l-ants[i]));
  }
  for(int i=0;i<n;i++)
  {
    maxT=max(maxT,max(ants[i],l-ants[i]));
  }
  printf("%d %d\n",minT,maxT);
}
