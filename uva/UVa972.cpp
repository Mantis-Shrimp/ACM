//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2014-1-24
// Description : 离散化
//============================================================================

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <string>
#include <algorithm>
#define MID(x,y) ( ( x + y ) >> 1 )
#define L(x) ( x << 1 )
#define R(x) ( x << 1 | 1 )
#define BUG puts("here!!!")
#define STOP system("pause")

using namespace std;

const int MAX = 110;
const double inf = 1e30;
struct point {double x,y;};
point f[MAX],g[MAX];
double x[MAX*2];

int main()
{
	int n,m;
	
	while( ~scanf("%d",&n) )
	{
		int cnt = 0;
		double sx = 0;
		x[cnt++] = 0;
		for(int i=0; i<n; i++)
		{
			scanf("%lf%lf",&f[i].x, &f[i].y);
			sx += f[i].y;
			x[cnt++] = sx;
		}
		scanf("%d",&m);
		
		sx = 0;
		for(int i=0; i<m; i++)
		{
			scanf("%lf%lf",&g[i].x, &g[i].y);
			sx += g[i].y;
			x[cnt++] = sx;
		}
		
		sort(x, x+cnt);
		cnt = unique(x, x+cnt) - x;
		
		int ff = 0,gg = 0;
		double fx = 0, gx = 0;
		double h = 0,minh = inf;
		for(int i=0; i<cnt; i++)
		{
			while( fx <= x[i] && ff < n )
			{
				fx += f[ff].y;
				ff++;
			}
			while( gx <= x[i] && gg < m )
			{
				gx += g[gg].y;
				gg++;
			}
			h = max(f[ff-1].x, g[gg-1].x);
			minh = min(h, minh);
		}
		
		printf("%.3lf\n", minh);
	}

return 0;
}
