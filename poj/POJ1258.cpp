//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-4-14
// Description : 最小生成树 prime sum是最小生成树的权
//============================================================================


#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>

#define LEN 550

int prime();

int adj[LEN][LEN];
int flag[LEN];
int t,sum,n;
int lesscost[LEN];

int main()
{
	while(scanf("%d\n",&n)!=EOF&&n!=0)
	{
		for(int j = 1; j <= n ; ++j)
			for(int i = 1 ; i <= n ; ++i)
				scanf("%d",&adj[j][i]);
		prime();
		printf("%d\n",sum);
	}
}


int prime()
{
	int min ,min_i;

	memset(flag,0,sizeof(flag));
	sum = 0;
	flag[1] = 1;
	
	for (int i = 1; i <= n; ++i)
		lesscost[i] = adj[1][i];

	for(int j = 1 ; j <= n-1 ; ++j)
	{
		min = INT_MAX;

		for (int i = 1; i <= n; ++i)
		{
			if(flag[i]==0&&lesscost[i]<min)
			{
				min = lesscost[i];
				min_i = i;
			}
		}

		flag[min_i] = 1;
		sum += min;

		for (int i = 1; i <= n; ++i)
		{
			if(flag[i]==0&&adj[min_i][i]<lesscost[i])
				lesscost[i] = adj[min_i][i];
		}
	}
	return 0;
}