//============================================================================
// Name        : UVa_836. cpp
// Author      :
// Version     :
// Copyright   : 2013-12-21 
// Description : 2D最大子段和
//============================================================================

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100 + 10;

int ma[N][N],m,n;
char str[N];

int getMax1D(int ma[])
{
	int sum = INT_MIN,ans = INT_MIN;
	for(int i = 0 ; i < n ; i++)
	{
		if(sum >= 0 )
			sum += ma[i];
		else
			sum = ma[i];
		ans = max(ans,sum);
	}

	return ans;
}

int getMax2D(int ma[][N])
{
	int sum[N];
	int ans = INT_MIN;
	for(int i = 0; i < m ; i++)
	{
		memset(sum,0,sizeof(sum));
		for(int j = i ; j < m ; j++)
		{
			for(int k = 0 ; k < n ; k++)
				sum[k] += ma[j][k];
			

			ans = max(ans,getMax1D(sum));
		}
	}
	return ans;
}



int main(int argc ,char* argv[])
{
	int T;
	scanf("%d",&T);
	getchar();
	gets(str);
	
	while(T--)
	{
		gets(str);
		n = m = strlen(str);
		for(int i = 0 ; i < n ; i++)
			ma[0][i] = str[i] - '0';
		int p = 1;
		while(gets(str) && str[0])
        {
            for (int j = 0; j < n; j++)
                ma[p][j] = str[j] - '0';
            p++;
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (ma[i][j] == 0)  ma[i][j] = -100;

        int ans = getMax2D(ma);
        if(ans < 0) ans = 0;
        printf("%d\n", ans);
        if (T)  printf("\n");
	}
	return 0;
}