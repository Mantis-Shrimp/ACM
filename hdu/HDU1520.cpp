//============================================================================
// Name        : HDU1520. cpp
// Author      :
// Version     :
// Copyright   : 2013-3-23
// Description : 简单树形动态规划
//============================================================================
#include <cstdio>
#include <cstring>
#include <vector>

#define N (6000 + 10)

using namespace std;

struct  edge
{
	int from,to,v;
};

struct edge edges[N];
int indegree[N];
int num;
vector<int> tree[N];
int val[N];
int l,k;
int n;
int dp[N][2];
int vis[N];

int addedge(int from,int to)
{
	++num;
	edges[num].from = from;
	edges[num].to = to;
	tree[from].push_back(num);
	indegree[to]++;
	return 0;
}


int dfs(int root)
{
	edge e;
	int a = 0;
	int b = 0;
	for (int i = 0; i < tree[root].size(); ++i)
	{
		e = edges[tree[root][i]];
		
		if(vis[e.to]==0) 
		{
			dfs(e.to);
			vis[e.to] = 1;
		}

		a += dp[e.to][0];
		b += dp[e.to][1] > dp[e.to][0] ? dp[e.to][1] : dp[e.to][0];
	}
	dp[root][0] = b;
	dp[root][1] = a + val[root];
	return dp[root][0] > dp[root][1] ? dp[root][0] : dp[root][1];
}

int main()
{
	int root = 0;
	num = 0;
	memset(dp,0,sizeof(dp));
	memset(vis,0,sizeof(vis));
	memset(indegree,0,sizeof(indegree));

	while(scanf("%d",&n)!=EOF)
	{

		memset(dp,0,sizeof(dp));
		memset(vis,0,sizeof(vis));
		memset(indegree,0,sizeof(indegree));

		root = num = 0;
		for(int i = 1 ; i <=n ; i++) tree[i].clear();
		
		for(int i = 1 ; i <=n ; i++) scanf("%d",&val[i]);
		scanf("%d%d",&l,&k);
		while(l+k!=0)
		{
			addedge(k,l);
			scanf("%d%d",&l,&k);
		}

		for (int i = 1; i <= n; ++i)
		{
			if (indegree[i]==0)
			{
				root = i;
				break;
			}
		}

		printf("%d\n", dfs(root));
	}
	return 0;
}