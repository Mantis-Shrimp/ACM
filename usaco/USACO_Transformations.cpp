/*
ID: 15864532
PROG: transform
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
#define read            freopen("transform.in", "r", stdin)
#define write           freopen("transform.out", "w", stdout)
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
const int N = 15;


int a[N][N],b[N][N],c[N][N];
int n;


int rotation90(int a[N][N],int b[N][N])
{
	int temp[N][N];
	FF(j, 0, n)
		FF(i, 0, n)
			temp[i][n-j-1] = a[j][i];
	FF(j, 0, n)
		FF(i, 0, n)
			b[j][i] = temp[j][i];
	return 0;
}

int reflection(int a[N][N],int b[N][N])
{
	int temp[N][N];
	FF(j, 0, n)
		FF(i, 0, n)
			temp[j][n-i-1] = a[j][i];
	FF(j, 0, n)
		FF(i, 0, n)
			b[j][i]=temp[j][i];
	return 0;
}

int equal(int a[N][N],int b[N][N])
{
	FF(j, 0, n)
		FF(i, 0, n)
			if(a[j][i]!=b[j][i])
				return 0;
	return 1;
}


int main(void)
{
    read;
    write;
    SD(n);
    getchar();
    FF(j, 0, n)
    {
		FF(i, 0, n)
			a[j][i] = getchar();
		getchar();
	}

	FF(j, 0, n)
    {
		FF(i, 0, n)
			b[j][i] = getchar();
		getchar();
	}


	rotation90(a,c);
	if(equal(c,b))
	{
		PF(1);
		return 0;
	}

	rotation90(c,c);
	if(equal(c,b))
	{
		PF(2);
		return 0;
	}

	rotation90(c,c);
	if(equal(c,b))
	{
		PF(3);
		return 0;
	}

	reflection(a,c);
	if(equal(c,b))
	{
		PF(4);
		return 0;
	}

	rotation90(c,c);
	if(equal(c,b))
	{
		PF(5);
		return 0;
	}

	rotation90(c,c);
	if(equal(c,b))
	{
		PF(5);
		return 0;
	}

	rotation90(c,c);
	if(equal(c,b))
	{
		PF(5);
		return 0;
	}

	if(equal(a,b))
	{
		PF(6);
		return 0;
	}

	PF(7);	
	//rotation90(a,a);
	//reflection(a,a);

	// FF(j, 0, n)
 //    {
	// 	FF(i, 0, n)
	// 		putchar(a[j][i]);
	// 	putchar('\n');
	// }


	// FF(j, 0, n)
 //    {
	// 	FF(i, 0, n)
	// 		putchar(b[j][i]);
	// 	putchar('\n');
	// }
    return 0;
}