//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-5-22
// Description : 裸背包
//============================================================================

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>

#define LEN (10000+10)
#define N (100+10)

using namespace std;

int dp[LEN];
int t,m;
int t0,v0;

int main()
{
	memset(dp,0,sizeof(dp));
	cin>>t>>m;
	for(int i = 1 ; i <= m ; ++i)
	{
		cin>>t0>>v0;
		for(int j = 10000 ; j >= t0 ; --j)
		{
			if(dp[j]<dp[j-t0]+v0)
				dp[j] = dp[j-t0]+v0;
		}
	}
	cout<<dp[t]<<endl;
}