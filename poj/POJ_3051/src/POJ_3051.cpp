#include <stdio.h>
#include <string.h>

int W,H;
char farm[1500][1500];
char flag[1500][1500];
int MAX,NUM;
int M,N;



int DFS(int depth,int i,int j);
int main()
{
	#ifdef DEBUG
	freopen("io.txt","r",stdin);
	#endif
	scanf("%d %d\n",&W,&H);
	M = W,N=H;
	for(int ih =1; ih <=H ; ih++)
	{
		for(int iw = 1 ; iw <=W; iw++)
		{
			farm[ih][iw]=getchar();
		}
		getchar();
	}


	for(int i = 1 ; i <= H ; i++)
	{
	   for(int j = 1 ; j<=W ; j++)
	   {
	   	  if(farm[i][j]=='*'&&flag[i][j]==0)
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
		if(farm[iw][ih-1]=='*'&&flag[iw][ih-1]==0)
		   {
		      flag[iw][ih-1] = 1 ,NUM++;
		      DFS(depth+1,iw,ih-1);
		   }
	}
	if(iw>=1&&ih+1>=1&&iw<=N&&ih+1<=M)
	{
		if(farm[iw][ih+1]=='*'&&flag[iw][ih+1]==0)
		   {
		      flag[iw][ih+1] = 1 ,NUM++;
		      DFS(depth+1,iw,ih+1);
		   }
	}
	if(iw-1>=1&&ih>=1&&iw-1<=N&&ih<=M)
	{
		if(farm[iw-1][ih]=='*'&&flag[iw-1][ih]==0)
		   {
		      flag[iw-1][ih] = 1 ,NUM++;
		      DFS(depth+1,iw-1,ih);
		   }
	}
	if(iw+1>=1&&ih>=1&&iw+1<=N&&ih<=M)
	{
		if(farm[iw+1][ih]=='*'&&flag[iw+1][ih]==0)
		   {
		      flag[iw+1][ih] = 1 ,NUM++;
		      DFS(depth+1,iw+1,ih);
		   }
	}
	return 0 ;
}


