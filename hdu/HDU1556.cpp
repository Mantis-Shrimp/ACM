//============================================================================
// Name        : HDU_1556. cpp
// Author      :
// Version     :
// Copyright   : 2012-7-21
// Description : Ê÷×´Êý×é
//============================================================================
#include <cstdio>
#include <cstring>
#define N 100005
int c[N],a,b,n,icase;
int add(int i,int val,int n);
int sum(int i);
int main()
{
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		icase = n ;
		memset(c,0,sizeof(c)) ;
		while(icase--)
		{
			scanf("%d%d",&a,&b);
			add(a,1,n);
			add(b+1,-1,n);
		}
		printf("%d",sum(1));
		for(int i = 2 ; i<=n ; i++) printf(" %d",sum(i));
		printf("\n");
	}
}

int add(int i,int val,int n)
{
	int pos = i;
	while(pos <= n)
	{
		c[pos] += val;
		pos += pos&(-pos);
	}
	return 0;
}

int sum(int i)
{
	int sum = 0,pos = i;
	while(pos>0)
	{
		sum += c[pos];
		pos -= pos&(-pos);
	}
	return sum;
}
