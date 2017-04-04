/*
ID: 15864532
PROG: milk3
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
#define read            freopen("milk3.in", "r", stdin)
#define write           freopen("milk3.out", "w", stdout)
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

struct Node_OPEN
{
	int a,b,c,p;
};

struct Node_CLOSED
{
	int a,b,c,p;
};

int ret[50],flag[25][25][25];
int A,B,C,a,b,c,p,aa,bb,cc;
int idx;
queue<Node_OPEN> open;
Node_CLOSED closed[maxn];


int main(int argc, char const *argv[])
{
	write;
	read;
	SD(A);
	SD(B);
	SD(C);
	Node_OPEN NP;
	Node_CLOSED NC;
	NP.a = NP.b = 0;
	NP.c = C;
	NP.p = -1;
	open.push(NP);

	SET(flag, 0);
	SET(ret, 0);
	flag[0][0][C] = 1;
	ret[C] = 1;


	while(open.empty()==0)
	{
		NP = open.front();
		open.pop();

		a = NP.a;
		b = NP.b;
		c = NP.c;
		p = NP.p;

		closed[idx].a = a;
		closed[idx].b = b;
		closed[idx].c = c;
		closed[idx].p = p;


		// a
		if(a!=0)
		{
			//to b
			if(B-b>=a)
			{
				bb = b + a;
				aa = 0;
				cc = c;


				if(flag[aa][bb][cc]==0)
				{
					if(aa==0)
						ret[cc] = 1;
					flag[aa][bb][cc] = 1;
					
					NP.a = aa;
					NP.b = bb;
					NP.c = cc;
					NP.p = idx;
					open.push(NP);
				}

			}
			else
			{
				aa = a - (B -b);
				bb = B;
				cc = c;

				if(flag[aa][bb][cc]==0)
				{
					if(aa==0)
						ret[cc] = 1;
					flag[aa][bb][cc] = 1;					
					NP.a = aa;
					NP.b = bb;
					NP.c = cc;
					NP.p = idx;
					open.push(NP);
				}
			}
			//to c

			if( (C-c) > a)
			{
				cc = c + a;
				bb = b;
				aa = 0;

				if(flag[aa][bb][cc]==0)
				{
					if(aa==0)
						ret[cc] = 1;
					flag[aa][bb][cc] = 1;					
					NP.a = aa;
					NP.b = bb;
					NP.c = cc;
					NP.p = idx;
					open.push(NP);
				}
			}
			else
			{
				cc = C;
				bb = b;
				aa = a - (C -c);

				if(flag[aa][bb][cc]==0)
				{
					if(aa==0)
						ret[cc] = 1;
					flag[aa][bb][cc] = 1;					
					NP.a = aa;
					NP.b = bb;
					NP.c = cc;
					NP.p = idx;
					open.push(NP);
				}
			}

		}

		if(b!=0)
		{
			//to a
			if(A-a>b)
			{
				aa = a + b;
				bb = 0;
				cc = c;

				if(flag[aa][bb][cc]==0)
				{
					if(aa==0)
						ret[cc] = 1;
					flag[aa][bb][cc] = 1;					
					NP.a = aa;
					NP.b = bb;
					NP.c = cc;
					NP.p = idx;
					open.push(NP);
				}
			}
			else
			{
				aa = A;
				bb = b - (A-a);
				cc = c;

				if(flag[aa][bb][cc]==0)
				{
					if(aa==0)
						ret[cc] = 1;
					flag[aa][bb][cc] = 1;					
					NP.a = aa;
					NP.b = bb;
					NP.c = cc;
					NP.p = idx;
					open.push(NP);
				}
			}
			//to c

			if(C-c > b)
			{
				aa = a;
				bb = 0;
				cc = c + b;
				if(flag[aa][bb][cc]==0)
				{
					if(aa==0)
						ret[cc] = 1;
					flag[aa][bb][cc] = 1;					
					NP.a = aa;
					NP.b = bb;
					NP.c = cc;
					NP.p = idx;
					open.push(NP);
				}
			}
			else
			{
				aa = a;
				bb = b - (C - c);
				cc = C;

				if(flag[aa][bb][cc]==0)
				{
					if(aa==0)
						ret[cc] = 1;
					flag[aa][bb][cc] = 1;					
					NP.a = aa;
					NP.b = bb;
					NP.c = cc;
					NP.p = idx;
					open.push(NP);
				}
			}
		}

		if(c!=0)
		{
			//to a
			if(A -a > c)
			{
				aa = a + c;
				bb = b;
				cc = 0;
				if(flag[aa][bb][cc]==0)
				{
					if(aa==0)
						ret[cc] = 1;
					flag[aa][bb][cc] = 1;					
					NP.a = aa;
					NP.b = bb;
					NP.c = cc;
					NP.p = idx;
					open.push(NP);
				}
			}
			else
			{
				aa = A;
				bb = b;
				cc = c - (A-a);
				if(flag[aa][bb][cc]==0)
				{
					if(aa==0)
						ret[cc] = 1;
					flag[aa][bb][cc] = 1;					
					NP.a = aa;
					NP.b = bb;
					NP.c = cc;
					NP.p = idx;
					open.push(NP);
				}
			}
			//to b

			if(B-b > c)
			{
				aa = a;
				bb = b + c;
				cc = 0;
				if(flag[aa][bb][cc]==0)
				{
					if(aa==0)
						ret[cc] = 1;
					flag[aa][bb][cc] = 1;					
					NP.a = aa;
					NP.b = bb;
					NP.c = cc;
					NP.p = idx;
					open.push(NP);
				}
			}
			else
			{
				aa = a;
				bb = B;
				cc = c - (B-b);
				if(flag[aa][bb][cc]==0)
				{
					if(aa==0)
						ret[cc] = 1;
					flag[aa][bb][cc] = 1;					
					NP.a = aa;
					NP.b = bb;
					NP.c = cc;
					NP.p = idx;
					open.push(NP);
				}
			}
		}

		idx = idx + 1;
	}

	for(int i = 0 ; i < C ; i++)
		if(ret[i]) printf("%d ",i);
	printf("%d\n",C);

	return 0;
}