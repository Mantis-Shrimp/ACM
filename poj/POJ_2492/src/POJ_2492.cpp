//============================================================================
// Name        : POJ_2492.cpp
// Author      : 
// Version     :
// Copyright   : 2012-11-4
// Description : ²¢²é¼¯
//============================================================================

#include <cstdio>
#include <cstring>

#define LEN (2000+50)
#define N  2

int num_bug,num_inter,count,C;
int fa[LEN],val[LEN],x,y,fx,fy;
int flag;


int findroot(int x)
{
	int fx = fa[x];
	if(fx ==x)
	{
		return x;
	}
	else
	{
		fa[x]=findroot(fa[x]);
		val[x]=(val[fx]+val[x])%N;
		return fa[x];
	}
}

int Union_set(int x,int y,int c)
{
	int fx = findroot(x);
	int fy = findroot(y);
	if(fx!=fy)
	{
		fa[fy] = fx;
		val[fy] = (c + val[x] - val[y] + N) % N;
		return 1;
	}
	else
	{
		return 0;
	}
}


int main()
{
  scanf("%d\n",&count);
  C = count;
  while(count--)
  {
	  scanf("%d%d",&num_bug,&num_inter);
	  flag = 0;
	  memset(val,0,sizeof(val));
	  for(int i = 1 ; i <= num_bug ; i++) fa[i] = i;
	  while(num_inter--)
	  {
		  scanf("%d%d",&x,&y);
		  if(flag==0)
		  {
			  fx = findroot(x);
			  fy = findroot(y);
			  if(fx==fy)
			  {
				  if(val[x]==val[y]) flag = 1;
			  }
			  else
			  {
				  Union_set(x,y,1);
			  }
		  }
	  }
	  if(flag==1)
		  printf("Scenario #%d:\nSuspicious bugs found!\n\n",C-count);
	  else
		  printf("Scenario #%d:\nNo suspicious bugs found!\n\n",C-count);
  }
  return 0;
}
