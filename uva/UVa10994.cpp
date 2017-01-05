//============================================================================
// Name        : UVa_10324. cpp
// Author      :
// Version     :
// Copyright   : 2013-12-24 
// Description : 組合數學
//============================================================================

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

long long Sum(long long a)
{
	long long s = 0;
	int l = 0;
	while(a > 0)
	{
		l = a % 10;
		a = a / 10;
		s = s + l * (l + 1) / 2 + a * 45 ;
	}

	return s;
}

int main(int argc, char const *argv[])
{
	long long a,b;
	while(scanf("%lld%lld",&a,&b)!=EOF&&!(a<0&&b<0))
	{
		printf("%lld\n",Sum(max(a,b))-Sum(min(a,b)-1));
	}
	return 0;
}