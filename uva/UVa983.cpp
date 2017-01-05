//============================================================================
// Name        : UVa_10324. cpp
// Author      :
// Version     :
// Copyright   : 2013-12-24 
// Description : 简单
//============================================================================
#include <cstdio>
#include <cstdlib>
using namespace std;



char buf[128];
int sum[1001][1001];
int N, M,a,t = 0;
int main()
{
	while(2 == scanf("%d %d", &N, &M))
	{
		if (++t > 1)
			printf("\n");
		for(int r=1; r <= N; ++r)
		{
			for(int c=1; c <= N; ++c)
			{
				scanf("%d",&a);
				sum[r][c] = a;
				sum[r][c] += sum[r-1][c];
				sum[r][c] += sum[r][c-1];
				sum[r][c] -= sum[r-1][c-1];
			}
		}

		int blurSize = N - M + 1;

		int total = 0;

		for(int r = 1; r <= blurSize; ++r)
		{
			for(int c = 1; c <= blurSize; ++c)
			{
				int sq4 = sum[r+M-1][c+M-1];
				int sq3 = sum[r+M-1][c-1];
				int sq2 = sum[r-1][c+M-1];
				int sq1 = sum[r-1][c-1];

				int sq = sq4 - sq3 - sq2 + sq1;
				printf("%d\n", sq);
				total += sq;		
			}
		}
		printf("%d\n", total);
	}

	return 0;
}