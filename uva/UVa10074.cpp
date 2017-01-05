//============================================================================
// Name        : UVa_1015. cpp
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

const int N = 100 + 10;

int ma[N][N],m,n;

int getMax1D(int ma[])
{
	int sum = INT_MIN;
	int ans = INT_MIN;
	for(int i = 0 ; i < n ; i++)
	{
		if(sum >= 0 )
			sum = sum + ma[i];
		else
			sum = ma[i];
		ans = max(ans,sum);
	}

	return ans;
}

int getMax2D(int ma[][N])
{
	int sum[N];
	int ans = INT_MIN;
	for(int i = 0; i < m ; i++)
	{
		memset(sum,0,sizeof(sum));
		for(int j = i ; j < m ; j++)
		{
			for(int k = 0 ; k < n ; k++)
				sum[k] = sum[k] + ma[j][k];
			ans = max(ans,getMax1D(sum));
		}
	}
	return ans;
}


int main(int argc ,char* argv[])
{
	while(scanf("%d%d\n",&m,&n)==2)
	{
		if(m==0&&n==0) break;
		for(int i = 0 ; i < m ; i++)
		{
			for(int j = 0 ; j < n ;j++)
			{
				scanf("%d",&ma[i][j]);
				if(ma[i][j]==1) ma[i][j]=-10000;
				else ma[i][j] = 1;
			}
		}

        int ans = getMax2D(ma);
        if(ans < 0) ans = 0;
        printf("%d\n", ans);
	}
	return 0;
}