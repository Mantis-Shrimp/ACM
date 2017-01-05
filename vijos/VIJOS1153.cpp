//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-5-22
// Description : 裸判定性背包
//============================================================================

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <climits>

#define LEN (9000+10)
#define N (200+5)

using namespace std;

int dp[N][LEN];
int n,v,sum;
int ret,temp;

int main()
{
	memset(dp,0,sizeof(dp));
	dp[0][0] = 1;
	cin>>n;
	sum = 0;
	temp = INT_MAX;
	for(int i = 1 ; i <= n ; ++i)
	{
		cin>>v;
		sum = sum + v;
		for(int j = 200 ; j >= 1 ; --j)
			for(int k = 9000 ; k >= v; --k )
				if(dp[j-1][k-v]==1) dp[j][k] = 1;
	}


	

	for(int i = 0 ; i <= 9000 ; ++i)
	{
		if(dp[n/2][i] == 1)
			if(abs(sum-i-i)<temp)
			{
				ret = i;
				temp = abs(sum -i -i);
			}
	}

	if(n%2==0)
	{
		if(ret>sum-ret) cout<<sum-ret<<" "<<ret<<endl;
		else cout<<ret<<" "<<sum-ret<<endl;
		return 0;
	}

	for(int i = 0 ; i <= 9000 ; ++i)
	{
		if(dp[n/2+1][i] == 1)
			if(abs(sum-i-i)<temp)
			{
				ret = i;
				temp = abs(i-sum);
			}
	}
	
	if(ret>sum-ret) cout<<sum-ret<<" "<<ret<<endl;
	else cout<<ret<<" "<<sum-ret<<endl;
	return 0;
}