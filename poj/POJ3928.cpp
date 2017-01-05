//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-3-30
// Description : 树状数组
//============================================================================

#include <iostream>
#include <cstring>
#include <cstdio>

#define N 100009

using namespace std;

int T,n;
long long ret;
int rank[N+1],S[N],lb[N+1],ls[N+1],rb[N+1],rs[N+1];

  
int add(int idx,int val)
{
	while(idx<N)
	{
		S[idx] += val;
		idx += (idx&(-idx));
	}
	return 0;
}

int getSum(int idx)
{
	int Sum = 0;
	while(idx >= 1)
	{
		Sum += S[idx];
		idx -= (idx&(-idx));
	}
	return Sum;
}

int run()
{
	cin>>T;
	while(T--)
	{
		ret = 0;
		cin>>n;

		for (int i = 1 ; i <= n ; i++ )
			cin>>rank[i];

		memset(S,0,sizeof(S));
		for (int i = 1; i <= n; ++i) 
		{

			add(rank[i],1);
			ls[i] = getSum(rank[i]-1);
			lb[i] = getSum(N-1) - getSum(rank[i]);

		}
		memset(S,0,sizeof(S));
		for (int i = n; i >= 1; --i) 
		{
			add(rank[i],1);
			rs[i] = getSum(rank[i]-1);
			rb[i] = getSum(N-1) - getSum(rank[i]);
		}

		for (int i = 1; i <= n ; ++i) 
			ret +=((lb[i]*rs[i])+(ls[i]*rb[i]));

		printf("%I64d\n", ret);;
	}
	return 0;
}

int main()
{
	run();
	return 0;
}
