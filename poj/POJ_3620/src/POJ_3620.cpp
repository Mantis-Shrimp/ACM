#include<stdio.h>
#include<string.h>

int N,M,K;
int R,C;
char farm[150][150];
char flag[150][150];
int NUM;
int MAX;


int DFS(int,int,int);
int main()
{
	//freopen("io.txt","r",stdin);
	memset(farm,0,150*150);
	memset(flag,0,150*150);
	MAX = 0 ;
	scanf("%d%d%d",&N,&M,&K);
	for(int i = 1 ; i<=K ;i++ ){scanf("%d%d",&R,&C);farm[R][C]=1;}
	for(int i = 1 ; i <= N ; i++)
	{
	   for(int j = 1 ; j<=M ; j++)
	   {
	   	  if(farm[i][j]==1&&flag[i][j]==0)
	   	  {
			 flag[i][j]=1;
			 NUM = 1;
			 DFS(0,i,j);
			 MAX=NUM>MAX?NUM:MAX;
          }
	   }
	}
	printf("%d\n",MAX);
}


int DFS(int depth,int iw,int ih)
{
	if(iw>=1&&ih-1>=1&&iw<=N&&ih-1<=M)
	{
		if(farm[iw][ih-1]==1&&flag[iw][ih-1]==0)
		   {
		      flag[iw][ih-1] = 1 ,NUM++;
		      DFS(depth+1,iw,ih-1);
		   }
	}
	if(iw>=1&&ih+1>=1&&iw<=N&&ih+1<=M)
	{
		if(farm[iw][ih+1]==1&&flag[iw][ih+1]==0)
		   {
		      flag[iw][ih+1] = 1 ,NUM++;
		      DFS(depth+1,iw,ih+1);
		   }
	}
	if(iw-1>=1&&ih>=1&&iw-1<=N&&ih<=M)
	{
		if(farm[iw-1][ih]==1&&flag[iw-1][ih]==0)
		   {
		      flag[iw-1][ih] = 1 ,NUM++;
		      DFS(depth+1,iw-1,ih);
		   }
	}
	if(iw+1>=1&&ih>=1&&iw+1<=N&&ih<=M)
	{
		if(farm[iw+1][ih]==1&&flag[iw+1][ih]==0)
		   {
		      flag[iw+1][ih] = 1 ,NUM++;
		      DFS(depth+1,iw+1,ih);
		   }
	}
	return 0 ;
}
