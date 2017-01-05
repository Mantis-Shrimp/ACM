//============================================================================
// Name        : UVa_10755. cpp
// Author      :
// Version     :
// Copyright   : 2013-12-23 
// Description : 3D最大子段和
//============================================================================

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100 + 10;

long long ma[N][N][N],p,m,n;

long long getMax1D(long long ma[])
{
	long long sum = 0;
	long long ans = LLONG_MIN;
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

long long getMax2D(long long ma[][N])
{
	long long sum[N];
	long long ans = LLONG_MIN;
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

long long getMax3D(long long ma[][N][N])
{
	long long sum[N][N];
	long long ans = LLONG_MIN;
	for(int i = 0; i < p ; i++)
	{
		memset(sum,0,sizeof(sum));
		for(int j = i ; j < p ; j++)
		{
			for(int k = 0 ; k < m ; k++)
				for(int l = 0 ; l < n ; l++)
				sum[k][l] = sum[k][l] + ma[j][k][l];
			ans = max(ans,getMax2D(sum));
		}
	}
	return ans;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	cin>>p>>m>>n;
    	for(int i = 0 ; i < p ;i++)
    		for(int j = 0 ; j < m ;j++)
    			for(int k = 0 ; k < n ;k++)
    				cin>>ma[i][j][k];
    	if(T)cout<<endl;
    }
    return 0;
}