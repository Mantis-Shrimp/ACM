//============================================================================
// Name        : POJ_1742.cpp
// Author      : 
// Version     :
// Copyright   : 2012-6-12
// Description : http://poj.org/problem?id=1742 ¶¯Ì¬¹æ»®
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 200000

int N,W;
int n[200], v[200],DP[LEN],num[LEN];
int r;

int main()
{
	scanf("%d%d",&N,&W);
	while((N+W)!=0)
	{
		for(int iN = 1 ;iN<=N ; iN++) scanf("%d",&v[iN]);
		for(int iN = 1 ;iN<=N ; iN++) scanf("%d",&n[iN]);
		memset(DP,0,sizeof(DP)),DP[0]=1,r = 0;
		for(int iN = 1 ; iN <= N ; iN++)
		{
			memset(num,0,sizeof(num));
			for(int iV = v[iN]; iV<= W ; iV++)
				if(DP[iV]==0&&DP[iV-v[iN]]==1&&num[iV-v[iN]]<n[iN])
					num[iV]=num[iV-v[iN]]+1,DP[iV]=1,r++;
		}
		printf("%d\n",r);
		scanf("%d%d",&N,&W);
	}
	return 0;
}
