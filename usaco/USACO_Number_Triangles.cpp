/*
ID: 15864532
PROG: numtri
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
#define read            freopen("numtri.in", "r", stdin)
#define write           freopen("numtri.out", "w", stdout)
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}

const int R = 1005;

int r,m[R][R],dp[R][R];
int main(int argc, char const *argv[])
{
	read;
	write;

	SET(dp,0);
	SD(r);
	for(int i = 1 ; i <= r ; i++)
		for(int j = 1 ; j <= i ; j++)
			SD(m[i][j]);
	// SET(m,0);
	
	for(int i = 1 ; i <= r ; i++)
		dp[r][i] = m[r][i];

	for(int i = r - 1 ; i >= 1; i--)
		for(int j = 1 ; j <= i ; j++)
			dp[i][j] = Max(dp[i+1][j] + m[i][j] , dp[i+1][j+1] + m[i][j]) ;
	
	PF(dp[1][1]);
	return 0;
}