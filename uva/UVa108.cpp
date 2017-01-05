//============================================================================
// Name        : UVa_108. cpp
// Author      :
// Version     :
// Copyright   : 2013-12-21 
// Description : 2D最大子段和
//============================================================================


#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 200;
int ma[N][N],n;

inline int getMax(int a,int b)
{
	if(a > b) return a;
	else return b;
}


int getMax1D(int ma[])
{
	int sum = 0;
	int maxinum = INT_MIN;
	for(int i = 0 ; i < n ; i++)
	{
		if(sum >= 0 )
			sum = sum + ma[i];
		else
			sum = ma[i];
		maxinum = getMax(maxinum,sum);
	}

	return maxinum;
}

int getMax2D(int ma[][N])
{
	int sum[N];
	int maxinum = INT_MIN;
	for(int j = 0; j < n ; j++)
	{
		memset(sum,0,sizeof(sum));
		for(int i = j ; i < n ; i++)
		{
			for(int k = 0 ; k < n ; k++)
				sum[k] = sum[k] + ma[i][k];
			maxinum = getMax(maxinum,getMax1D(sum));
		}
	}
	return maxinum;
}


int main(int argc ,char* argv[])
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < n ; ++j)
				scanf("%d",&ma[i][j]);
		printf("%d\n", getMax2D(ma));
	}
	return 0;
}