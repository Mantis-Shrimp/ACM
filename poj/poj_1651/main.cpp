//============================================================================
// Name        : POJ1651. cpp
// Author      :
// Version     :
// Copyright   : 2012-7-30
// Description : DP 区间动态规划
//============================================================================
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#define MAX 200

int dpf(int,int);

int num,dp[MAX][MAX],cards[MAX];

int main(int argc, char **argv)
{
	scanf("%d",&num);
	memset(dp,-1,sizeof(dp));
	for(int i = 1 ; i <= num ; i++) scanf("%d",&cards[i]);
	printf("%d\n",dpf(1,num));
	system("pause");
	return 0;
}

int dpf(int i,int j)
{
	int temp = INT_MAX , r = INT_MAX;

	if(i+1==j) return 0;
	if(dp[i][j]!=-1) return dp[i][j];

	for(int k = i+1 ; k < j ; k++)
	{
		temp = dpf(i,k)+dpf(k,j)+cards[i]*cards[k]*cards[j];
		if( temp < r ) r = temp;
	}
	dp[i][j] = r;
	return dp[i][j];
}
