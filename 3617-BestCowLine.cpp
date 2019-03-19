#include<iostream>
#include<cstdio>
using namespace std;

#define MAX_N 10000
char S[MAX_N+1];
int N;

void solve(){
 int a=0,b=N-1,num=0;
 while(a<=b){
  bool left=false;
  for(int i=0;a+i<=b;i++){
   if(S[a+i]<S[b-i]){
     left=true;
     break;
   }
   else if(S[a+i]>S[b-i]){
    left=false;
    break;
   } 
  }
  if(left){
    putchar(S[a++]);
    num++;
    //putchar('\n');
  }
  else{
   putchar(S[b--]);
   num++;
   //putchar('\n');
  }
   if(num%80==0)
   putchar('\n');
 }

}

int main(){
 cin>>N;
 for(int i=0;i<N;i++)cin>>S[i];
 solve();
return 0;
}
