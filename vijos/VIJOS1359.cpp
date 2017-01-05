//============================================================================
// Name        : UVa_1359. cpp
// Author      :
// Version     :
// Copyright   : 2013-12-21 
// Description : 数论
//============================================================================

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int a[]={2,3,5,7};
int b[]={1,3,7,9};
int n;

int IsPrime(int m)
{
	for(int i = 2 ; i * i <= m ; i++)
		if(m%i==0) return 0;
	return 1;
}

int DFS(int d,int idx,int num)
{
	int tmp;
	// printf("%d\n",num);

	if(d==n+1)
	{
		printf("%d\n",num);
		return 0;
	}

	for(int i = 0 ; i <= 3 ; i++)
	{
		if(d==1)
			tmp = num *10 + a[i];
		else
			tmp = num * 10 + b[i];

		if(IsPrime(tmp)==1) 
			DFS(d+1,i,tmp);
	}
	return 0;
}


int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	DFS(1,0,0);
	return 0;
}