//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-3-28
// Description : 动态规划 树形动态规划
//============================================================================

#include <iostream>
#include <cstring>

#define LEN 150

using namespace std;

int n;
int tree[LEN];
long long dp[LEN][LEN];
int v[LEN][LEN];



long long DFS(int s,int e)
{
	long long temp = 0;
	long long a,b;
	if(dp[s][e]!=0) return dp[s][e];
	if(s==e)
	{ 
		dp[s][e] = tree[s];
		v[s][e] = s;
		return dp[s][e];
	}
	if(s>e) return dp[s][e] = 1;
	
	for (int i = 0; i <= e-s; ++i)
	{
		a = DFS(s,s+i-1);
		b = DFS(s+i+1,e);
		temp = a * b + tree[s+i];
		if(temp > dp[s][e])
			dp[s][e] = temp,v[s][e] = i;
	}
	return dp[s][e];
}


int output(int s,int e)
{
	if(s==e)
	{
		cout<<s << " ";
		return 0;
	}

	if (s>e) return 0;
	cout << s + v[s][e]<< " ";
	output(s,s+v[s][e]-1);
	output(s+v[s][e]+1,e);
	return 0;
}


int main(int argc, char const *argv[])
{
	memset(v,0,sizeof(v));
	memset(dp,0,sizeof(dp));
	cin>>n;
	for(int i = 1 ; i <= n; ++i) cin>> tree[i];
	cout<<DFS(1,n)<<endl;
	output(1,n);
	return 0;
}