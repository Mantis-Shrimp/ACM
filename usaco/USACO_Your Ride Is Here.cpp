/*
ID: 15864532
PROG: ride
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
#define FF(i, a)        for(int i=1; i<a; i++)
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
const int maxn = 20000 + 10 ;


int ma[maxn],aa,bb;
char a[maxn],b[maxn];

int main() 
{
	freopen("ride.in","r",stdin);
	freopen("ride.out","w",stdout);
	scanf("%s",a);
	scanf("%s",b);
	aa = bb = 1;
	int alen = strlen(a);
	int blen = strlen(b);

	for(int i = 0 ; i < alen ; i++)
		aa = ((a[i] - 'A' + 1) * aa ) % 47;
	
	for(int i = 0 ; i < blen ; i++)
		bb = ((b[i] - 'A' + 1) * bb ) % 47;
	
	if(aa==bb)
		printf("GO\n");
	else
		printf("STAY\n");
	
	return 0;
}