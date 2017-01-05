//============================================================================
// Name        : POJ_3628.cpp
// Author      : 
// Version     :
// Copyright   : 2012-6-11
// Description : http://poj.org/problem?id=3628 01背包问题 动态规划
//============================================================================

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 10000000

int V,B,N,c[30],w[30],dp[LEN];
int index;
int main()
{
	while(scanf("%d%d",&N,&B)!=EOF)
	{
	memset(dp,0,sizeof(dp)),V=0;
	for(int iN = 1 ; iN <=N ;iN++) scanf("%d",&c[iN]),w[iN]=c[iN],V+=c[iN];
	for(int iN = 1 ; iN <=N ; iN++)
	    for(int iV = V ; iV>=w[iN] ; iV--)
	    	if( dp[iV-w[iN]] + c[iN] > dp[iV]) dp[iV] =dp[iV-w[iN]] + c[iN];
	index = 1;
	while(dp[index]<B) index++;
	printf("%d\n",dp[index]-B);
	}
	return 0;
}
