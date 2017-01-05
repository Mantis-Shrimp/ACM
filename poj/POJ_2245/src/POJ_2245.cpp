//============================================================================
// Name        : POJ_2245.cpp
// Author      : 
// Version     :
// Copyright   : 2012-7-11
// Description : Lotto DFS
//============================================================================

#include <cstring>
#include <cstdio>
#define MAX 20
using namespace std;

int dfs(int depth,int num);
int flag[MAX],s[MAX],k;

int main()
{
	while(scanf("%d",&k)&&k!=0)
	{
		for(int i = 1 ; i<=k ; i++) scanf("%d",&s[i]);
		memset(flag,0,sizeof(flag));
		dfs(1,0);
		printf("\n");
	}
	return 0;
}

int dfs(int depth,int num)
{
	if(num==6)
	{
		for(int i = 1 ; i<=k; i++)
			if(flag[i]==1) printf("%d ",s[i]);
		printf("\n");
		return 0;
	}
	if(depth==k+1) return 0;
	for(int i = 1 ; i>=0 ; i--)
		if(i==0)
		{
			flag[depth]=i;
			dfs(depth+1,num);
		}
		else
		{
			flag[depth]=i;
			dfs(depth+1,num+1);
		}
	return 0;
}
