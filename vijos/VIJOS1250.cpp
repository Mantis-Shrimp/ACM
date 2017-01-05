//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-5-23
// Description : 并查集 分组的背包
//============================================================================

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

#define N 2000

using namespace std;

int F[N];
int dp[N];
int n,wmax,k;
int pi[N],wi[N];
int p[N][N];
int num;
int son[N];

inline int init()
{
	for(int i = 1 ; i < N ; ++i ) 
		F[i] = i;
	return 0;
}

int findroot(int a)
{
	if(F[a] == a) 
		return a;
	else 
		return F[a] = findroot(F[a]);
}

int uion(int a,int b)
{
	int pa = findroot(a);
	int pb = findroot(b);
	if(pa!=pb)
		F[pb] = pa;
	return 0;
}

int main(int argc, char const *argv[])
{
	freopen("in.txt","r",stdin);
	int tempa,tempb;
	int tempp;
	int dpmax;

	memset(son,0,sizeof(son));
	memset(dp,0,sizeof(dp));
	memset(p,0,sizeof(p));	
	init();

	cin>>n>>wmax>>k;
	for(int i = 1 ; i <= n ; ++i)
		cin>>pi[i]>>wi[i];
	
	for(int i = 1 ; i <= k ; ++i)
	{
		cin>>tempa>>tempb;
		uion(tempa,tempb);
	}

	for(int i = 1 ; i <= n ; ++i)
	{
		tempp = findroot(i);
		son[tempp]++;
		p[tempp][son[tempp]] = i;
	}

	for(int j = 1 ; j <= n ; ++j)
	{
		for(int i = wmax ; i >= 0 ; --i)
		{
			dpmax = dp[i];
			
			for(int k = 0 ; k <= son[j] ; ++k)
				if( i >= wi[p[j][k]] && dpmax < dp[i-wi[p[j][k]]] + pi[p[j][k]] )
					dpmax = dp[i-wi[p[j][k]]] + pi[p[j][k]];
			
			dp[i] = dpmax;
		}
	}

	cout<<dp[wmax]<<endl;

	return 0;
}