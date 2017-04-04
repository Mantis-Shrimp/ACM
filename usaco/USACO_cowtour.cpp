/*
ID: 15864532
PROG:cowtour
LANG: C++
*/
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <iomanip>
#include <bitset>
#include <list>
#include <ctime>
#include <climits>
using namespace std ;
#define SET(arr, what)  memset(arr, what, sizeof(arr))
#define FF(i, s, e)     for(int i=s; i<e; i++)
#define SD(a)           scanf("%d", &a)
#define SSD(a, b)       scanf("%d%d", &a, &b)
#define SF(a)           scanf("%lf", &a)
#define SS(a)           scanf("%s", a)
#define SLD(a)          scanf("%lld", &a)
#define PF(a)           printf("%d\n", a)
#define PLF(a)          printf("%lld\n", a)
#define PPF(a, b)       printf("%d %d\n", a, b)
#define SZ(arr)         (int)a.size()
#define SWAP(a,b)       a=a xor b;b= a xor b;a=a xor b;
#define read            freopen("cowtour.in", "r", stdin)
#define write           freopen("cowtour.out", "w", stdout)
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}

const int MAXN = 175;
const double INF = 1E15;

int N,x[MAXN],y[MAXN],fa[MAXN];
double dist[MAXN][MAXN],dis_max[MAXN];



inline double getDist(int x1,int y1,int x2,int y2)
{
	return sqrt(1.0*(x1-x2)*(x1-x2)+1.0*(y1-y2)*(y1-y2));
}

int ReadData()
{
	char c;
	SD(N);
	for(int i = 1 ; i <= N ; i++)
	{
		dis_max[i] = - 1,fa[i] = i;
		SSD(x[i], y[i]);
	}
	for(int i = 1 ; i <= N ; i++)
	{
		getchar();
		for(int j = 1 ; j <= N ; j++)
		{
			c = getchar();
			if(i==j) dist[i][j] = 0;
			else
			{
				if(c=='0') dist[i][j]=INF;
				else 
					dist[i][j]=getDist(x[i], y[i], x[j], y[j]);
			}
		}
	}
}

int Floyd()
{
	for(int k = 1 ; k <= N ; k++)
	{
		for(int i = 1 ; i <= N ; i++)
		{
			for(int j = 1 ; j <= N ; j++)
			{
				if(k==i||k==j) continue;
                if ( dist[i][k]+dist[k][j]<dist[i][j] )
                    dist[i][j] = dist[i][k]+dist[k][j];
			}
		}
	}

	return 0;
}


int Solve()
{
	double tmp,ret;

	for(int i = 1 ; i <= N ;i++)
		for(int j = 1 ; j <= N ; j++)
			if(dist[i][j]!=INF && dis_max[i]<dist[i][j])
				dis_max[i]=dist[i][j];

	
	ret = INF;
	for(int i = 1 ; i <= N ; i++)
	{
		for(int j = i + 1 ; j <= N ; j++)
		{
			if ( dist[i][j]==INF)
            {
                tmp = getDist( x[i], y[i], x[j], y[j] );
                if ( dis_max[i]+tmp+dis_max[j]<ret )
                    ret=dis_max[i]+tmp+dis_max[j];
            }
		}
	}

	for(int i = 1 ; i <= N ; i++)
		if(dis_max[i] > ret)
			ret = dis_max[i];
	printf("%.6lf\n", ret);
}

int main(int argc, char const *argv[])
{
	write;
	read;
	ReadData();
	Floyd();
	Solve();
	return 0;
}