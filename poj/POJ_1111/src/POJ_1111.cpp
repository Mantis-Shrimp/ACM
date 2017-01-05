#include <stdio.h>
#include <string.h>

#define MMM 100
int W,H;
char farm[MMM][MMM];
char flag[MMM][MMM];
int MAX,NUM;
int M,N;



int DFS(int depth,int i,int j);
int Count(int,int);

int main()
{
	#ifdef DEBUG
	freopen("io.txt","r",stdin);
	#endif
	scanf("%d %d %d %d\n",&N,&M,&W,&H);
	while(M+N+W+H!=0)
	{
	memset(farm,0,MMM*MMM);
	memset(flag,0,MMM*MMM);
	NUM = 1;
	for(int ih =1; ih <=N ; ih++)
	{
		for(int iw = 1 ; iw <=M; iw++)
		{
			farm[ih][iw]=getchar();
		}
		getchar();
	}
	flag[W][H]=1;
	MAX = Count(W,H);
	DFS(0,W,H);
	printf("%d\n",MAX);
	scanf("%d %d %d %d\n",&N,&M,&W,&H);
	}
}


int DFS(int depth,int iw,int ih)
{

	if(iw>=1&&ih-1>=1&&iw<=N&&ih-1<=M)
	{
		if(farm[iw][ih-1]=='X'&&flag[iw][ih-1]==0)
		   {
		      flag[iw][ih-1] = 1 ,NUM++;
		      MAX += Count(iw,ih-1);
		      DFS(depth+1,iw,ih-1);
		   }
	}

	if(iw>=1&&ih+1>=1&&iw<=N&&ih+1<=M)
	{
		if(farm[iw][ih+1]=='X'&&flag[iw][ih+1]==0)
		   {
		      flag[iw][ih+1] = 1 ,NUM++;
		      MAX += Count(iw,ih+1);
		      DFS(depth+1,iw,ih+1);
		   }
	}
	if(iw-1>=1&&ih>=1&&iw-1<=N&&ih<=M)
	{
		if(farm[iw-1][ih]=='X'&&flag[iw-1][ih]==0)
		   {
		      flag[iw-1][ih] = 1 ,NUM++;
		      MAX += Count(iw-1,ih);
		      DFS(depth+1,iw-1,ih);
		   }
	}
	if(iw+1>=1&&ih>=1&&iw+1<=N&&ih<=M)
	{
		if(farm[iw+1][ih]=='X'&&flag[iw+1][ih]==0)
		   {
		      flag[iw+1][ih] = 1 ,NUM++;
		      MAX += Count(iw+1,ih);
		      DFS(depth+1,iw+1,ih);
		   }
	}


	if(iw-1>=1&&ih-1>=1&&iw-1<=N&&ih-1<=M)
	{
		if(farm[iw-1][ih-1]=='X'&&flag[iw-1][ih-1]==0)
		   {
		      flag[iw-1][ih-1] = 1 ,NUM++;
		      MAX += Count(iw-1,ih-1);
		      DFS(depth+1,iw-1,ih-1);
		   }
	}
	if(iw+1>=1&&ih+1>=1&&iw+1<=N&&ih+1<=M)
	{
		if(farm[iw+1][ih+1]=='X'&&flag[iw+1][ih+1]==0)
		   {
		      flag[iw+1][ih+1] = 1 ,NUM++;
		      MAX += Count(iw+1,ih+1);
		      DFS(depth+1,iw+1,ih+1);
		   }
	}

	if(iw-1>=1&&ih+1>=1&&iw-1<=N&&ih+1<=M)
	{
		if(farm[iw-1][ih+1]=='X'&&flag[iw-1][ih+1]==0)
		   {
		      flag[iw-1][ih+1] = 1 ,NUM++;
		      MAX += Count(iw-1,ih+1);
		      DFS(depth+1,iw-1,ih+1);
		   }
	}
	if(iw+1>=1&&ih-1>=1&&iw+1<=N&&ih-1<=M)
	{
		if(farm[iw+1][ih-1]=='X'&&flag[iw+1][ih-1]==0)
		   {
		      flag[iw+1][ih-1] = 1 ,NUM++;
		      MAX += Count(iw+1,ih-1);
		      DFS(depth+1,iw+1,ih-1);
		   }
	}
	return 0 ;
}


int Count(int i,int j)
{
	int Count = 0 ;
	if(i-1<=N&&i-1>=1&&j>=1&&j<=M)
	  if(farm[i-1][j]=='X') Count++;

   if(i+1<=N&&i+1>=1&&j>=1&&j<=M)
	  if(farm[i+1][j]=='X') Count++;

   if(i<=N&&i>=1&&j-1>=1&&j-1<=M)
	  if(farm[i][j-1]=='X') Count++;

   if(i<=N&&i>=1&&j+1>=1&&j+1<=M)
	  if(farm[i][j+1]=='X') Count++;

   return  4 - Count;
}
