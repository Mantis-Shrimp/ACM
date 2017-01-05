//============================================================================
// Name        : POJ_1276.cpp
// Author      : 
// Version     :
// Copyright   : 2012-6-12
// Description : Hhttp://poj.org/problem?id=1276 动态规划 多重背包
//============================================================================

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 1000000

int W,N;
int dp[LEN],count[LEN];
int v,num;
int r;

int main()
{
	while(scanf("%d%d",&W,&N)!=EOF)
	{
		memset(dp,0,sizeof(dp)),dp[0]=1,r = 0;
		for(int iN = 1 ; iN<=N ; iN++)
		{
			memset(count,0,sizeof(count)),scanf("%d%d",&num,&v);
			for(int iW = v ; iW <=W ; iW++)
				if(dp[iW]==0&&dp[iW-v]==1&&count[iW-v]<num)
					dp[iW]=1,count[iW]=count[iW-v]+1;
		}
		r = W;
		while(dp[r]==0) r--;
		printf("%d\n",r);
	}
	return 0;
}
