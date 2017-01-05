//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-5-17
// Description : 动态规划 背包问题变形
//============================================================================

#include <cstdio>
#include <cstring>
#include <iostream>

#define N 150
#define MAX 2005

using namespace std;

int dp[N][MAX];
int n,h;
int a,b;
int tempa,tempb;

int swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
	return 0;
}


int main()
{
//	freopen("in.txt","r",stdin);
	memset(dp,-1,sizeof(dp));
	dp[0][0] = 0;
	cin>>n;
	
	for(int j = 0 ; j < n ; ++j)
	{
		scanf("%d",&h);
		for(int i = 0 ; i < MAX ; ++i)
		{
			if(dp[j][i]==-1) continue;
			
			//////////////////////////
			a = dp[j][i];
			b = dp[j][i] - i;


			a = a + h;
			b = b;

			if(dp[j+1][a-b] < a)
				dp[j+1][a-b] = a;

			/////////////////////////
			a = dp[j][i];
			b = dp[j][i] - i;

			a = a;
			b = b + h;

			if(a<b) swap(a,b);
			if(dp[j+1][a-b] < a)
				dp[j+1][a-b] = a;

			/////////////////////////
			if(dp[j+1][i] < dp[j][i])
				dp[j+1][i] = dp[j][i];
		}
	}

	// for(int j = 0 ; j < n ; ++j)
	// {
	// 	for(int i = 0 ; i < 20 ; ++i)
	// 	{
	// 		cout<<dp[j][i]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	if(dp[n][0]>=1) cout<<dp[n][0]<<endl;
	else cout<<"Impossible"<<endl;
}