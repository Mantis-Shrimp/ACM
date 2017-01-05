#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <functional>

using namespace std;


bool greater_(const char&,const char&);
int pow(int,int);
int DFS(int,int);

int N;
int len ;
char chs[27];
char flag[27];
char r[10];
int fl;



int main()
{
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
scanf("%d%s",&N,chs);
while(N!=0)
{
len = strlen(chs);
fl = 0 ;
sort(chs,chs+len,greater_);
memset(flag,0,27);
DFS(1,0);
if(fl==0) printf("no solution\n");
scanf("%d%s",&N,chs);
}
}

bool greater_(const char &a,const char &b)
{
return a > b;
}

int DFS(int depth,int sum)
{

int _sum = 0 ;
if(fl==1) return 1;

for(int i = 0 ; i < len ; i++)
{

if(flag[i]==1) continue;
_sum = sum;
flag[i]=1;
r[depth]=chs[i];

if(depth%2==1) _sum+=pow(chs[i]-'A' + 1 ,depth);
else _sum-=pow(chs[i]-'A' + 1 ,depth);

//printf("depth=%d sum = %d\n",depth,sum);
//for(int j = 1 ; j <= depth; printf("%c",r[j]),j++ ) ;
//printf("\n");
if(depth==5)
{
//for(int j = 1 ; j <= depth; printf("%c",r[j]),j++ ) ;
    //printf(" sum = %d\n",_sum);
if(_sum==N)
{
fl = 1 ;
for(int j = 1 ; j <= 5; printf("%c",r[j]),j++ ) ;
printf("\n");
return 1;
}
}
else
{
DFS(depth+1,_sum);
}
flag[i]=0;
}

return 1;
}


int pow(int a,int b)
{
int temp = 1 ;
for(int i = 0 ; i < b ; i++) temp=temp*a;
return temp;
}
