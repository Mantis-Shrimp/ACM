/*
ID: 15864532
LANG:C++
PROB:ratios
 */

#include <cstdio>
 
int d[4][3];
 
int main()
{
	freopen("ratios.in", "r", stdin);
	freopen("ratios.out", "w", stdout);
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
			scanf("%d", &d[i][j]);
	}
	int p;
	for (p = 0; p < 3; ++p)
		if (d[3][p]) break;
	for (int lam = 1; lam <= 100; ++lam)
	{
		for (int i = 0; i<=100 && d[1][0]*i<=d[0][0]*lam && d[1][1]*i<=d[0][1]*lam && d[1][2]*i<=d[0][2]*lam; ++i)
			for (int j = 0; j<=100 && d[1][0]*i+d[2][0]*j<=d[0][0]*lam && d[1][1]*i+d[2][1]*j<=d[0][1]*lam && d[1][2]*i+d[2][2]*j<=d[0][2]*lam; ++j)
			{
				int k = (d[0][p]*lam - d[1][p]*i - d[2][p]*j) / d[3][p], kk;
				for (kk = 0; kk < 3; ++kk)
				{
					if (d[1][kk]*i + d[2][kk]*j + d[3][kk]*k != d[0][kk]*lam)
						break;
				}
				if (kk == 3)
				{
					printf("%d %d %d %d\n", i, j, k, lam);
					return 0;
				}
			}
	}
	printf("NONE\n");
	return 0;
}