//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-4-22
// Description : 区间动态规划
//============================================================================

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>

#define N 500

using namespace std;

int n;
int num[N];
int dp[N][N];


int Getdp()
{
	for(int k = 1 ; k <= n -1 ; ++k)
		for(int s = 1 ; s+k <= n+n -1 ; ++s)
			for(int i = 1 ; i <= k ; ++i)
				if(dp[s][s+i-1]+dp[s+i][s+k]+num[s]*num[s+i]*num[s+k+1] > dp[s][s+k])
				dp[s][s+k]= dp[s][s+i-1]+dp[s+i][s+k]+num[s]*num[s+i]*num[s+k+1];
	return 0;
}

int main(int arg,char* argv[])
{
	int ret = INT_MIN;
	cin>>n;
	for(int i = 1 ; i <= n ; ++i) cin >> num[i];
	for(int i = 1 ; i <= n ; ++i) num[i+n] = num[i];
	memset(dp,0,sizeof(dp));
	Getdp();
	for(int i = 1 ; i <= n ; ++i)
		if(dp[i][i+n-1] > ret) ret = dp[i][i+n-1];
	cout<<ret<<endl;
	return 0;
}