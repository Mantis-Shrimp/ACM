//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2014-1-24
// Description : 离散化
//============================================================================

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
using namespace std ;
typedef long long  LL;
#define SET(arr, what)  memset(arr, what, sizeof(arr))
#define FF(i, s, a)     for(int i=s; i<=a; i++)
#define SD(a)           scanf("%d", &a)
#define SSD(a, b)       scanf("%d%d", &a, &b)
#define SF(a)           scanf("%lf", &a)
#define SS(a)           scanf("%s", a)
#define SLD(a)          scanf("%lld", &a)
#define PF(a)           printf("%d\n", a)
#define PPF(a, b)       printf("%d %d\n", a, b)
#define SZ(arr)         (int)a.size()
#define SWAP(a,b)       a=a xor b;b= a xor b;a=a xor b;
#define read            freopen("in.txt", "r", stdin)
#define write           freopen("out.txt", "w", stdout)
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
const int maxn = 100000 + 10 ;
const int N = 300;

double x[N],y[N],dx[N],dy[N];
int n,cor[N][N],fx[N],fy[N],cas;
double a,b,r,ret;

int main(int argc, char const *argv[])
{
	
	cas = 1;
	//cin>>n;
	while(scanf("%d",&n)!=EOF && n!=0)
	{
	ret = 0;
	FF(i, 1, n)
	{
		scanf("%lf %lf %lf", &a, &b, &r);
		x[i] = a -r;
		y[i] = b - r;
		x[i+n] = a + r;
		y[i+n] = b + r;
	}

	FF(i, 1, 2*n)
		dx[i] = x[i],dy[i] = y[i];
	
	sort(dx+1,dx+1+n+n);
	int nx = unique(dx+1,dx+1+n+n) - (dx+1);
	FF(i, 1, 2*n)
		fx[i] = lower_bound(dx+1,dx+1+nx,x[i]) - (dx+1) + 1;
	
	sort(dy+1,dy+1+n+n);
	int ny = unique(dy+1,dy+1+n+n) - (dy+1);
	FF(i, 1, 2*n)
		fy[i] = lower_bound(dy+1,dy+1+ny,y[i]) - (dy+1) + 1;

	SET(cor, 0);

	for(int i = 1 ; i <= n ; i++)
		for(int ix = fx[i] + 1; ix <= fx[i+n];ix++)
			for(int iy = fy[i] + 1 ; iy <= fy[i+n];iy++)
				cor[iy][ix]=1;
	
	for (int i = 2; i <= 2 * n; i++)
        for (int j = 2; j <= 2 * n; j++)
            if (cor[i][j]==1) 
            	ret += (dy[i] - dy[i - 1])*(dx[j] - dx[j - 1]);
    
    printf("%d %.2lf\n", cas++, ret);
	}
	return 0;
}