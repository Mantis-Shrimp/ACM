//============================================================================
// Name        : POJ_2063.cpp
// Author      : 
// Version     :
// Copyright   : 2012-6-11
// Description : http://poj.org/problem?id=2063 Investment ÍêÈ«±³°ü
//============================================================================

#include <stdio.h>
#include <string.h>

#define LEN 200000
int year,T,V,N,c[200],w[200],dp[LEN];
int DP();
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&T);
	int money = 0;
	while(T--)
	{
		scanf("%d%d%d",&money,&year,&N);
		for(int iN = 1 ; iN <= N ; iN++) scanf("%d %d",w+iN,c+iN),w[iN]/=1000;
		while(year--)
		{
			V = money/1000;
			money+=DP();
		}
		printf("%d\n",money);
	}
	return 0;
}

int DP()
{
	for(int iN = 0 ; iN <=V ; dp[iN++]=0);
	//memset(dp,0,sizeof(dp));
	for(int iN = 1 ; iN<=N ; iN++)
		for(int iV = w[iN] ; iV<=V ; iV++)
			if(dp[iV-w[iN]]+c[iN]>dp[iV]) dp[iV] = dp[iV-w[iN]]+c[iN];
	return dp[V];
}
