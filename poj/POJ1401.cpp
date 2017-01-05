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
	int N,n,ret;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d",&n);
		ret = 0 ;
		while((n/=5)>0)
			ret = ret + n;
		printf("%d\n",ret);
	}
	return 0;
}