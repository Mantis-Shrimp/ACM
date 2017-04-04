/*
ID: 15864532
PROG: crypt1
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
#define read            freopen("crypt1.in", "r", stdin)
#define write           freopen("crypt1.out", "w", stdout)
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
const int maxn = 210000;
const int N = 50;


int num[N],flag[N];
int n,a,b,c,d,e,ret;
int r1,r2,r3;

int IsOk()
{
	// r1[0] = a * e;
	// r1[1] = b * e;
	// r1[2] = c * e;

	// r2[0] = a * d;
	// r2[1] = b * d;
	// r2[2] = c * d;

	// r3[0] = r2[0];
	// r3[1] = r1[0] + r2[1];
	// r3[2] = r1[1] + r2[2];
	// r3[3] = r1[2];

	// for(int i = 0 ; i < 3 ; i++)
	// 	if(flag[r1[i]]==0) return 0;

	// for(int i = 0 ; i < 3 ; i++)
	// 	if(flag[r2[i]]==0) return 0;

	// for(int i = 0 ; i < 4 ; i++)
	// 	if(flag[r3[i]]==0) return 0;

	// return 1;

	r1 = (a * 100 + b * 10 + c) * e;
	r2 = (a * 100 + b * 10 + c) * d;
	r3 = r2 * 10 + r1;

	if(r1 > 999) return 0;
	if(r2 > 999) return 0;
	if(r3 > 9999) return 0;

	if(flag[r1%10]==0 || flag[(r1/10)%10]==0 || flag[(r1/100)%10]==0) return 0;
	if(flag[r2%10]==0 || flag[(r2/10)%10]==0 || flag[(r2/100)%10]==0) return 0;
	if(flag[r3%10]==0 || flag[(r3/10)%10]==0 || flag[(r3/100)%10]==0 || flag[(r3/1000)%10]==0) return 0;
	return 1;
}

int main(int argc, char const *argv[])
{
	write;
	read;
	SET(flag, 0);
	SD(n);
	ret = 0;
	for(int i = 0 ; i < n ; i++)
	{
		SD(num[i]);
		flag[num[i]] = 1;
	}


	for(int aa = 0 ; aa < n ; aa++)
	{
		for(int bb = 0 ; bb < n ; bb++)
		{
			for(int cc = 0 ; cc < n ; cc++)
			{
				for(int dd = 0 ; dd < n ; dd++)
				{
					for(int ee = 0 ; ee < n ; ee++)
					{
						a = num[aa];
						b = num[bb];
						c = num[cc];
						d = num[dd];
						e = num[ee];

						if(IsOk())
						{
							
							ret++;
							// printf("      %d %d %d\n",a,b,c);
							// printf("   x    %d %d\n",d,e);
							// printf("    -------\n");
							// printf("      %d %d %d \n",r1[0],r1[1],r1[2]);
							// printf("    %d %d %d \n",r2[0],r2[1],r2[2]);
							// printf("    -------\n");
							// printf("    %d %d %d %d\n",r3[0],r3[1],r3[2],r3[3]);
							// return 0;
						}
					}
				}
			}
		}
	}

	PF(ret);

	return 0;
}