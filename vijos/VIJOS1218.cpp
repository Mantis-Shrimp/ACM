//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-4-24
// Description : 区间动态规划
//============================================================================
#include <iostream>
#include <cstring>
#include <climits>

#define N 200
#define M 15

using namespace std;

long long in[N];
long long temp[N];
long long num[N];
long long _min[M][N];
long long _max[M][N];
long long sum[N][N];
long long min_ret,max_ret;
long long m,n;

int dp()
{
	long long temp_min,temp_max;
	memset(sum,0,sizeof(long long));
	

	for(int i = 1 ; i <= n ; ++i)
		for(int j = i ; j <= n; ++j)
			sum[i][j] = (sum[i][j-1] + num[j]%10 + 10)%10;

	for(int i = 1 ; i <= n ; ++i)
	{
		_min[1][i] = sum[1][i];
		_max[1][i] = sum[1][i];
	}

	for(int i = 2 ; i <= m ; ++i)
	{
		for(int j = i ; j <= n; ++j)
		{
			temp_max = LLONG_MIN;
			temp_min = LLONG_MAX;
			
			for(int k = i-1 ; k <= j-1 ; ++k)
			{
				if(temp_max < _max[i-1][k] * sum[k+1][j] )
					temp_max = _max[i-1][k] * sum[k+1][j];

				if(temp_min > _min[i-1][k] * sum[k+1][j] )
					temp_min = _min[i-1][k] * sum[k+1][j];
			}

			_min[i][j] = temp_min;
			_max[i][j] = temp_max; 
		}
	}

	
	return 0;
}

int main(int arg,char* argv[])
{
	min_ret = LLONG_MAX;
	max_ret = LLONG_MIN;
	
	cin>>n>>m;

	for(int i = 1 ; i <= n; ++i) cin>>in[i];
	
	for(int i = 1 ; i <= n ; ++i) temp[i] = in[i];
	for(int i = n+1 ; i <= n+n ;++i) temp[i] = in[i-n];

	for(int i = 0 ; i < n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			num[j] = temp[j+i];
		}
		dp();

		if(max_ret < _max[m][n]) max_ret = _max[m][n];
		if(min_ret > _min[m][n]) min_ret = _min[m][n];
	}
	cout<<min_ret<<endl<<max_ret<<endl;
	return 0;
}