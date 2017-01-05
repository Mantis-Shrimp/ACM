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

#define LEN (20000+10)

using namespace std;

int dp[LEN];
int n,v;
int v0;

int main()
{
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	cin>>v>>n;
	for(int i = 1 ; i <= n ; ++i)
	{
		cin>>v0;
		for(int j = 20000 ; j >= v0 ; --j)
			if(dp[j-v0]==1) dp[j] = 1;
	}
	for(int i = v ; i >= 0 ; --i)
		if(dp[i]==1)
		{	
			cout<<v-i<<endl;
			return 0;
		}
}