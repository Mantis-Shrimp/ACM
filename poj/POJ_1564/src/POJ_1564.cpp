//============================================================================
// Name        : POJ_2245.cpp
// Author      : 
// Version     :
// Copyright   : 2012-7-11
// Description : Sum It Up DFS
//============================================================================

#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAX 20
using namespace std;

int dfs(int,int,int);
bool IsGreater (int a,int b);
int flag[MAX],S[MAX],SUM,NUM;
bool is;

int main()
{
	while(scanf("%d%d",&SUM,&NUM)&&(SUM+NUM)!=0)
	{
		for(int i = 1 ; i<=NUM ; i++) scanf("%d",&S[i]);
		is = false,memset(flag,0,sizeof(flag));
		printf("Sums of %d:\n",SUM);
		sort(S+1,S+NUM+1,IsGreater);
		dfs(1,0,1);
		if(is==false) printf("NONE\n");
	}
	return 0;
}

int dfs(int depth,int sum,int index)
{
	bool _flag=false;
	int j = 0;
	if(SUM==sum)
	{
		is = true;
		for(int i = 1 ; i<=depth-1; i++)
				if(_flag==false)
				  printf("%d",S[flag[i]]),_flag=true;
				else
					printf("+%d",S[flag[i]]);
		printf("\n");
		return 0;
	}

	if(depth==NUM+1) return 0;

	for(int i = index ; i<=NUM ; i++)
	{
		if(sum+S[i]<=SUM)
		{
			j = i;
			flag[depth] = i;
			dfs(depth+1,sum+S[i],i+1);
			while(S[j]==S[i+1])i++;
		}
	}
	return 0;
}

bool IsGreater (int a,int b)
{
	return a>=b;
}
