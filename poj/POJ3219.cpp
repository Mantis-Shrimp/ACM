//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2014-1-22
// Description : 数论
//============================================================================

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>

int main(int argc, char const *argv[])
{
	int k,n,m,ret0,ret1,ret2;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		m = n - k;
		ret0=ret1=ret2=0;
		while((n/=2)>0) ret0+=n;
		while((k/=2)>0) ret1+=k;
		while((m/=2)>0) ret2+=m;

		if((ret0-ret1-ret2)>0)
			printf("0\n");
		else
			printf("1\n");
		//if((ret0-ret1-ret2)==0)
		//	printf("1\n");
	}
	return 0;
}