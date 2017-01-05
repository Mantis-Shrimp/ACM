//============================================================================
// Name        : POJ_1611. cpp
// Author      : 
// Version     :
// Copyright   : 2012-7-18
// Description : ²¢²é¼¯
//============================================================================
#include <cstdio>
#include <cstring>
//#define DEBUG
#define N_MAX 30005

int findroot(int index);
int n,m,numpergroup,root,flag[N_MAX],temp,sum;
int aroot,broot;

int main()
{
	while(scanf("%d%d",&n,&m)&&n+m!=0)
	{

#ifdef DEBUG
		printf(" n = %d m = %d ",n,m);
		printf("\n");
#endif
		sum = 0;
		for(int i = 0 ; i < N_MAX ; i++) flag[i] = i ;		
		
		for(int im = 1 ; im <= m ; im++)
		{
			scanf("%d%d",&numpergroup,&root);
			aroot = findroot(root);
			for(int inum = 2 ; inum <= numpergroup ; inum++)
			{
				scanf("%d",&temp);
				broot = findroot(temp);
				if(aroot!=broot) flag[broot] = aroot;
			}
		}

		aroot = findroot(0);
		for(int in = 0 ; in < n ; in++)
		{
			if(findroot(in)==aroot) sum++;
		}
#ifdef DEBUG
		for(int i = 0 ; i <= 10 ; i++)
			printf("%d ",flag[i]);
		printf("\n");
#endif
		printf("%d\n",sum);
	}
}

int findroot(int index)
{
	int root = -1;
	if(flag[index]==index)
	{
		root = index;
	}
	else
	{
		root = findroot(flag[index]);
		flag[index]=root;
	}
	return root;
}
