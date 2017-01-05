//============================================================================
// Name        : POJ_1661.cpp
// Author      : 
// Version     :
// Copyright   : 2012-5-2
// Description : http://poj.org/problem?id=1661 Help Jimmy
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <algorithm>
using namespace std;

#define LEN 10000

bool comp(struct element a,struct element b);

struct element
{
	int l;
	int r;
	int h;
};


int t;
int N,X,Y,MAX;
element flat[LEN];
int lDP[LEN],rDP[LEN];
bool L,R;


int main()
{
	int ltemp,rtemp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&N,&X,&Y,&MAX);
		N++;
		flat[1].r=X,flat[1].l=X,flat[1].h=Y;
		for(int ii = 2 ; ii<=N ; ii++) scanf("%d%d%d",&flat[ii].l,&flat[ii].r,&flat[ii].h);

		sort(flat+1,flat+1+N,comp);

		for(int ii=N ; ii >= 1 ; ii--)
		{
			L =false;
			for(int jj=ii+1 ; jj<= N ; jj++)
			{
				if(flat[ii].h-MAX <= flat[jj].h)
				{
					if(flat[ii].l>=flat[jj].l&&flat[ii].l<=flat[jj].r)
					{
						ltemp = lDP[jj]==INT_MAX? INT_MAX: lDP[jj]+flat[ii].h-flat[jj].h + flat[ii].l-flat[jj].l;
					    rtemp = rDP[jj]==INT_MAX? INT_MAX: rDP[jj]+flat[ii].h-flat[jj].h + flat[jj].r-flat[ii].l;
					    lDP[ii] = ltemp < rtemp? ltemp:rtemp;
					    L = true;
					    break;
					}
				}
			}

			if(L==false)
				if(flat[ii].h-MAX<=0) lDP[ii] = flat[ii].h;
				else lDP[ii] = INT_MAX;



			R =false;
			for(int jj=ii+1 ; jj<= N ; jj++)
			{
				if(flat[ii].h-MAX <= flat[jj].h)
				{
					if(flat[ii].r>=flat[jj].l&&flat[ii].r<=flat[jj].r)
					{
						  ltemp = lDP[jj]==INT_MAX? INT_MAX: lDP[jj]+flat[ii].h-flat[jj].h + flat[ii].r-flat[jj].l;
						  rtemp = rDP[jj]==INT_MAX? INT_MAX: rDP[jj]+flat[ii].h-flat[jj].h + flat[jj].r-flat[ii].r;
						  rDP[ii] = ltemp < rtemp? ltemp:rtemp;
						  R = true;
						  break;
					 }
				}
			}
			if(R==false)
			  if(flat[ii].h-MAX<=0) rDP[ii] = flat[ii].h;
			  else rDP[ii] = INT_MAX;
		}
	//for(int ii=1; ii<=N;ii++)
		printf("%d\n",lDP[1]);
	}
	return 0;
}

bool comp(struct element a,struct element b)
{
	return a.h>b.h;
}
