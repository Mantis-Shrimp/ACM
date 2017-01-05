//============================================================================
// Name        : UVa_10827. cpp
// Author      :
// Version     :
// Copyright   : 2013-12-23 
// Description : 最大子段和
//============================================================================
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int N = 200 + 10;

int mat[N][N],m,n;

int getMax1D(int mat[])
{
	int sum = 0;
	int ans = INT_MIN;
	for(int i = 0 ; i < n ; i++)
	{
		if(sum >= 0 )
			sum = sum + mat[i];
		else
			sum = mat[i];
		ans = max(ans,sum);
	}

	return ans;
}

int getMax2D(int mat[][N])
{
	int sum[N];
	int ans = INT_MIN;
	for(int i = 0; i < m ; i++)
	{
		for(int j = 0 ; j < n ; j++)
		{
			memset(sum,0,sizeof(sum));
			for(int k = i ; k < i + m ; k++)
			{
				for(int l = j ; l < n +j ; l++)
				{
					sum[l] = sum[l] + mat[k][l];
				}
				ans = max(ans,getMax1D(sum+j));
			}
		}
	}
	return ans;
}


int main(int argc, char const *argv[])
{
	int T;
	scanf("%d\n",&T);
	while(T--)
	{
		scanf("%d\n",&n);
		m = n ;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				scanf("%d",&mat[i][j]);
				mat[m+i][n+j] = mat[i][n+j]= mat[m+i][j] = mat[i][j];
			}
		}
		printf("%d\n",getMax2D(mat));
	}

	return 0;
}