//============================================================================
// Name        : POJ_1952.cpp
// Author      : 
// Version     :
// Copyright   : 2012-6-12
// Description : BUY LOW, BUY LOWER  ¶¯Ì¬¹æ»®  http://poj.org/problem?id=1952
//============================================================================

#include <stdio.h>
#include <limits.h>
#define LEN 5005
int N,stocks[LEN],times[LEN],dp[LEN],same,max,pos;

int main()
{
	scanf("%d\n",&N),max=-1,stocks[N+1]=INT_MIN;
	for(int i = 1 ; i<=N ; i++) scanf("%d",stocks+i);
	for(int i=1;i<=N+1;i++)
	{
		dp[i] = 1,times[i]=0,same = stocks[i];
		for(int j=i-1;j>=1;j--)
			if(stocks[j]>stocks[i]&&dp[j]+1>=dp[i]) dp[i]=dp[j]+1;
		for(int j=i-1;j>=1;j--)
			if(stocks[j]>stocks[i]&&dp[j]+1==dp[i]&&same!=stocks[j])
				times[i]+=times[j],same=stocks[j];
		if(dp[i]==1) times[i]=1;
	}
	for(int i = 1 ; i <=N ; i++)
		if(dp[i]>max) max = dp[i],pos = i;
	printf("%d %d\n",dp[pos],times[N+1]);
	return 0;
}
