/*
ID: 15864532
PROG: frac1
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
#define read            freopen("frac1.in", "r", stdin)
#define write           freopen("frac1.out", "w", stdout)
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
#define LL              int
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}

struct Frac
{
	int a;
	int b;
	bool operator < (const Frac& f ) const
	{
		return a*f.b < f.a * b;
	}
	bool operator == (const Frac& f)const
	{
		return (a==f.a&&b==f.b);
	}
};


LL gcd(LL a,LL b)
{
    return b==0?a:gcd(b,a%b);
}

set<Frac> s;

int main(int argc, char const *argv[])
{
	Frac f;
	int n,g;
	write;
	read;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= i ; j++)
		{
			g = gcd(i,j);
			f.a = j / g;
			f.b = i /g;
			s.insert(f);
		}
	}
	printf("0/1\n");
	for(set<Frac>::iterator it = s.begin(); it != s.end() ; it++)
		printf("%d/%d\n",it->a,it->b);
	return 0;
}