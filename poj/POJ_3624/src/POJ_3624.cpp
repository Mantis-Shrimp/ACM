//============================================================================
// Name        : POJ_3624.cpp
// Author      : 
// Version     :
// Copyright   : 2012-5-2
// Description : http://poj.org/problem?id=3624  01背包问题    动态规划
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 100000

int N,M,W,D,DP[LEN];

int main()
{
	for(int i = 0 ; i<LEN ; DP[i++]=0);
	scanf("%d %d",&N,&M);
	for(int i = 1 ; i<=N ;i++)
	{
		scanf("%d %d",&W,&D);
		for(int j = M ; j>=W ; j--)
			if(DP[j-W]+D>=DP[j]) DP[j] = DP[j-W]+D;
	}
	printf("%d\n",DP[M]);
	return 0;
}
