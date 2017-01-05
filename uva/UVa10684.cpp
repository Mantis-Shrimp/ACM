//============================================================================
// Name        : UVa_10684. cpp
// Author      :
// Version     :
// Copyright   : 2013-12-22 
// Description : 最大子段和
//============================================================================

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int N = 15000;


vector<int> seq(N),dp(N);
int n,Max;

int main(int argc,char* argv[])
{
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		dp[0] = 0;
		Max = INT_MIN;
		for (int i = 1; i <= n; ++i)
			scanf("%d",&seq[i]);

		for(int i = 1; i <= n ; ++i)
		{
			if(dp[i-1]>=0)
				dp[i] = dp[i-1] + seq[i];
			else dp[i] = seq[i];
			
			if(Max < dp[i])
				Max = dp[i];
		}

		// for (int i = 0; i <= n; ++i)
		// {
		// 	printf("%d ", seq[i]);
		// }
		// printf("\n");

		// for (int i = 0; i <= n; ++i)
		// {
		// 	printf("%d ", dp[i]);
		// }
		// printf("\n");

		if(Max > 0) printf("The maximum winning streak is %d.\n",Max);
		else printf("Losing streak.\n");
	}
	return 0;
}