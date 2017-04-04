/*
ID: 15864532
PROG: friday
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
#define FF(i, s, e)        for(int i=s; i<e; i++)
#define SD(a)           scanf("%d", &a)
#define SSD(a, b)       scanf("%d%d", &a, &b)
#define SF(a)           scanf("%lf", &a)
#define SS(a)           scanf("%s", a)
#define SLD(a)          scanf("%lld", &a)
#define PF(a)           printf("%d\n", a)
#define PPF(a, b)       printf("%d %d\n", a, b)
#define SZ(arr)         (int)a.size()
#define SWAP(a,b)       a=a xor b;b= a xor b;a=a xor b;
#define read            freopen("friday.in", "r", stdin)
#define write           freopen("friday.out", "w", stdout)
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

int n,days;
int week[8];
int main(int argc, char const *argv[])
{
	read;
	write;
	days = 0;
	SET(week, 0);
	SD(n);
	
	FF(i, 0, n)
	{
		// 1
		week[(days + 13) % 7] ++ ;
		days += 31;

		// 2
		week[(days + 13) % 7] ++ ;
		if( 
			((1900+i)%100==0&&(1900+i)%400==0)
			|| 
			((1900+i)%100!=0&&(1900+i)%4==0) 
			)
		days += 29;
		else
		days += 28;

		// 3
		week[(days + 13) % 7] ++ ;
		days += 31;

		// 4
		week[(days + 13) % 7] ++ ;
		days += 30;

		// 5
		week[(days + 13) % 7] ++ ;
		days += 31;

		// 6
		week[(days + 13) % 7] ++ ;
		days += 30;

		// 7
		week[(days + 13) % 7] ++ ;
		days += 31;

		// 8
		week[(days + 13) % 7] ++ ;
		days += 31;

		// 9
		week[(days + 13) % 7] ++ ;
		days += 30;

		// 10
		week[(days + 13) % 7] ++ ;
		days += 31;

		// 11
		week[(days + 13) % 7] ++ ;
		days += 30;

		// 12
		week[(days + 13) % 7] ++ ;
		days += 31;

	}
	
	FF(i, -1, 5)
		printf("%d ",week[(i + 7 ) % 7]);
	printf("%d",week[(5 + 7 ) % 7]);
	printf("\n");
	return 0;
}