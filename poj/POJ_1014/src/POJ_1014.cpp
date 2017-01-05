//============================================================================
// Name        : POJ_1014.cpp
// Author      : 
// Version     :
// Copyright   : 2012-5-2
// Description : http://poj.org/problem?id=1014 背包问题   动态规划
//============================================================================

#include <cstdio>
#include <cstdlib>
#include <cstring>

#define LEN 100000
int mar[10];
char DP[7][LEN];
int NUM[LEN];
int sum;
int v;
int num = 1;

int dp();
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	sum = 0;
	for(int i = 1 ; i<=6 ; i++) scanf("%d",mar+i),sum+=(*(mar+i)*i);
	while(sum!=0)
	{
		if(sum%2==1)
		{
			printf("Collection #%d:\nCan't be divided.\n\n",num);
		}
		else
		{
		v = sum/2;
		if(dp()==1) printf("Collection #%d:\nCan be divided.\n\n",num);
		else printf("Collection #%d:\nCan't be divided.\n\n",num);
		}
		sum = 0,num++;
		for(int i = 1 ; i<=6 ; i++) scanf("%d",mar+i),sum+=(*(mar+i)*i);
	}
	return 0;
}

int dp()
{
	memset(DP[0],0,LEN*sizeof(char)),DP[0][0]=1;
	memset(DP[0],0,LEN*sizeof(char)),DP[1][0]=1;
	memset(DP[0],0,LEN*sizeof(char)),DP[2][0]=1;
	memset(DP[0],0,LEN*sizeof(char)),DP[3][0]=1;
	memset(DP[0],0,LEN*sizeof(char)),DP[4][0]=1;
	memset(DP[0],0,LEN*sizeof(char)),DP[5][0]=1;
	memset(DP[0],0,LEN*sizeof(char)),DP[6][0]=1;
	for(int i = 1 ; i<=6 ; i++)
	{
		//memset(NUM,0,LEN*sizeof(int));
		for(int k = 0; k<LEN;k++) NUM[k]=0;
		for(int j = 1; j<=v;j++)
		{
			if(DP[i-1][j]==1)
			{
				DP[i][j] = DP[i-1][j];
			}
			else
			{
			if(DP[i-1][j-i]==1&&NUM[j-i]+1<=mar[i]&&j>=i)
			{
				DP[i][j]=1;
				NUM[j]=1;
			}
			else
			{
				if(DP[i][j-i]==1&&NUM[j-i]+1<=mar[i]&&j>=i)
				{
					DP[i][j]=1;
					NUM[j]=NUM[j-i]+1;
				}
				else
				{
			     DP[i][j]=DP[i-1][j];
				}
			}
			}
			//	DP[j]=1,NUM[j]=NUM[j-i]+1;
			//printf("%d ",DP[j]);
		}

		//for(int j = 1; j<=v;j++)
		//		{
		//			printf("%d ",DP[i][j]);
		//		}
		//		printf("\n");
	}
	return DP[6][v];
}
