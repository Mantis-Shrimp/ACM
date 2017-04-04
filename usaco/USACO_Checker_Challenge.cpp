/*
ID: 15864532
PROG:checker
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
using namespace std ;
#define SET(arr, what)  memset(arr, what, sizeof(arr))
#define FF(i, s, e)     for(int i=s; i<e; i++)
#define SD(a)           scanf("%d", &a)
#define SSD(a, b)       scanf("%d%d", &a, &b)
#define SF(a)           scanf("%lf", &a)
#define SS(a)           scanf("%s", a)
#define SLD(a)          scanf("%lld", &a)
#define PF(a)           printf("%d\n", a)
#define PPF(a, b)       printf("%d %d\n", a, b)
#define SZ(arr)         (int)a.size()
#define SWAP(a,b)       a=a xor b;b= a xor b;a=a xor b;
#define read            freopen("checker.in", "r", stdin)
#define write           freopen("checker.out", "w", stdout)
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}

const int N = 200;

int n,chess[N],a[N],b[N],c[N],cnt;

int DFS(int d)
{
	
	if(d==n+1)
	{
		cnt ++;
		if(cnt<=3)
		{
			printf("%d",chess[1]);
			for(int i = 2; i <= n; i++)
				printf(" %d",chess[i]);
			printf("\n");
		}
		return 1;
	}

	for(int i = 1 ; i <= n ; i++)
	{
		if(a[i]==0&&b[d+i]==0&&c[d-i+100]==0)
		{
			chess[d] = i;
			a[i]=b[d+i]=c[d-i+100]=1;
			DFS(d+1);
			a[i]=b[d+i]=c[d-i+100]=0;
		}
	}

	return 1;
}

int main(int argc, char const *argv[])
{
	write;
	read;
	SD(n);
	SET(a,0);
	SET(b,0);
	SET(c,0);
	cnt = 0;
	DFS(1);
	PF(cnt);
	return 0;
}