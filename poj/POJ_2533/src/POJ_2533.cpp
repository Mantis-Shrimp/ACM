//============================================================================
// Name        : POJ_2533.cpp
// Author      : 
// Version     :
// Copyright   : 2012-5-2
// Description : Longest Ordered Subsequence ¶¯Ì¬¹æ»®
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define LEN 2000

int seq[LEN],dp[LEN],max,N;
int main()
{
	scanf("%d",&N);
	max = INT_MIN;
	for(int iseq = 1 ; iseq<=N ; iseq++) scanf("%d",seq+iseq),dp[iseq]=1;

	for(int iseq = 1 ; iseq<=N ; iseq++)
	{
		for(int idp = iseq -1 ; idp >=1 ; idp--)
			if(seq[iseq]>seq[idp]&&dp[iseq]<dp[idp]+1) dp[iseq] =dp[idp] + 1;
		if(max < dp[iseq]) max = dp[iseq];
	}
	printf("%d\n",max);
	return 0;
}
