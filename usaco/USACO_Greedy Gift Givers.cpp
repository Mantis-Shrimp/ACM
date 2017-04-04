/*
ID: 15864532
PROG: gift1
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
#define FF(i, a)        for(int i=0; i<a; i++)
#define SD(a)           scanf("%d", &a)
#define SSD(a, b)       scanf("%d%d", &a, &b)
#define SF(a)           scanf("%lf", &a)
#define SS(a)           scanf("%s", a)
#define SLD(a)          scanf("%lld", &a)
#define PF(a)           printf("%d\n", a)
#define PPF(a, b)       printf("%d %d\n", a, b)
#define SZ(arr)         (int)a.size()
#define SWAP(a,b)       a=a xor b;b= a xor b;a=a xor b;
#define read            freopen("gift1.in", "r", stdin)
#define write           freopen("gift1.out", "w", stdout)
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
const int NP = 100;
const int LEN = 20;

char name[NP][LEN],na[LEN];
int account[NP],np;
int money,ng,temp;


int main(int argc, char const *argv[])
{
	read;
	write;
	SET(account, 0);
	SD(np);
	FF(i, np) SS(name[i]);
	while(SS(na)!=EOF)
	{
		SSD(money, ng);
		
		if(ng==0) continue;
		FF(i, np)
			if(strcmp(na,name[i])==0)
				account[i] -= (money/ng*ng);

		FF(i, ng)
		{
			SS(na);
			FF(i, np)
			if(strcmp(na,name[i])==0)
				account[i] += (money/ng);

		}
	}
	FF(i, np)
		printf("%s %d\n",name[i],account[i]);
	return 0;
}