//============================================================================
// Name        : POJ_1995. cpp
// Author      :
// Version     :
// Copyright   : 2012-7-28
// Description : ¿ìËÙÃÝ
//============================================================================

#include <stdio.h>
#define DEBUG
int fastpow(int a,int b,int mod);
int Z,M,H,sum;
int a,b;

int main(int argc,char* argv[])
{
	scanf("%d",&Z);
	while(Z--)
	{
		scanf("%d%d",&M,&H);
		sum = 0 ;
		while(H--)
		{
			scanf("%d%d",&a,&b);
			sum = ( sum + fastpow(a,b,M) ) % M;
		}
		printf("%d\n",sum);
	}
	return 0;
}


int fastpow(int a,int b,int mod)
{
	int r = 1 ,p = b;
	a = a % mod;
	while(p>0)
	{
		if(p&1==1) r = ( r * a ) % mod;
		p>>=1;
		a = (a * a) % mod;
	}
	return r ;
}
