//============================================================================
// Name        : POJ_2362.cpp
// Author      : 
// Version     :
// Copyright   : 2012-5-2
// Description : http://poj.org/problem?id=2362 Square
//============================================================================

#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

#define LEN 10000

bool DFS(int len,int count,int index,int depth);
bool cmp(int a,int b);

int T;
int M;
int sticks[LEN];
int sum[LEN];
bool used[LEN];


int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&M);
		for(int ii = 1 ; ii<=M ; ii++) scanf("%d",&sticks[ii]);
		sort(sticks+1,sticks+M+1,cmp);
		sum[M+1]=0;
		for(int ii = M;  ii>=1 ; ii--) sum[ii]=sum[ii+1]+sticks[ii],used[ii]=false;
		if(sum[1]%4==0)
		{
			if(DFS(0,1,1,1)==true) printf("yes\n");
			else printf("no\n");
		}
		else
		{
			printf("no\n");
		}
	}
	return 0;
}

bool DFS(int len,int count,int index,int depth)
{
	if(count==4) return true;
	int jj = 0;
	for(int ii =index ; ii<=M ; ii++)
	{
		jj=ii;
		if(used[ii]==false)
		{

			used[ii]=true;
			if(len+sticks[ii]<sum[1]/4 &&sum[ii]+len>=sum[1]/4)
			{
				if(DFS(len+sticks[ii],count,ii+1,depth+1)==true)
				{
					used[ii]=false;return true;
				}
				else
				{
					if(len==0) {used[ii]=false; return false;}
				}
			}

			if(len+sticks[ii]==sum[1]/4)
			{
				if(DFS(0,count+1,1,depth+1)==true){used[ii]=false;return true;}
			}
			used[ii]=false;
			while(sticks[jj]==sticks[ii+1])ii++;
		}
	}
	return false;
}

bool cmp(int a,int b)
{
	return a>b;
}
