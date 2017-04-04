/*
ID: 15864532
PROG: packrec
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
#define read            freopen("packrec.in", "r", stdin)
#define write           freopen("packrec.out", "w", stdout)
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> T Max(T a,T b)
					{
						return a>b?a:b;
					}

#define MMM 35

struct RET
{
	int p;
	int q;
	bool operator < (const RET &a) const
	{
	 	if(p*q < a.p*a.q)
	 		return true;
	 	if(p*q == a.p*a.q)
	 		if(p<a.p)
	 			return true;
	 	return false;
	}

	bool operator == (const RET &a) const
	{
		if(p==a.p&&q==a.q)
			return true;
		else
			return false;
	}
};

int rect[4][2], q[4] ,cnt,bin,flag[4],w[4],h[4];
RET ret[1920];
int W,H;
int DFS(int d)
{
	if(d == 4)
	{
		for(int i = 0 ; i <= 15 ; i++)
		{
			//printf("%d %d %d %d\n", (i>>3)&1, (i>>2)&1 , (i>>1)&1 , (i>>0)&1 );
			// printf("%d %d %d %d\n", i>>3&1, i>>2&1 , i>>1&1 , i>>0&1 );
			// printf("%d %d %d %d\n", i>>3&1^1,i>>2&1^1,i>>1&1^1,i>>0&1^1);
			w[0] = rect[q[0]][i>>3&1];
			w[1] = rect[q[1]][i>>2&1];
			w[2] = rect[q[2]][i>>1&1];
			w[3] = rect[q[3]][i>>0&1];
		
			h[0] = rect[q[0]][i>>3&1^1];
			h[1] = rect[q[1]][i>>2&1^1];
			h[2] = rect[q[2]][i>>1&1^1];
			h[3] = rect[q[3]][i>>0&1^1];

			//
			W = w[0] + w[1] + w[2] + w[3];
			H = Max(Max(Max(h[0],h[1]),h[2]),h[3]);
			if(W>H)
				ret[cnt].p = H,ret[cnt].q = W;
			else
				ret[cnt].p = W,ret[cnt].q = H;
			cnt++;
			//

			W = Max(w[0]+w[1]+w[2],h[3]);
			H = ((Max(Max(h[0],h[1]),h[2])) + w[3]);
			if(W>H)
				ret[cnt].p = H,ret[cnt].q = W;
			else
				ret[cnt].p = W,ret[cnt].q = H;
			cnt++;
			//

			W = Max(w[0]+w[1],h[3])+w[2];
			H = Max(Max(h[0]+w[3],h[1]+w[3]),h[2]);
			if(W>H)
				ret[cnt].p = H,ret[cnt].q = W;
			else
				ret[cnt].p = W,ret[cnt].q = H;
			cnt++;
			//

			W = Max(w[1],w[2]) + w[0] + w[3];
			H = Max(Max(h[0],h[1]+h[2]),h[3]);
			if(W>H)
				ret[cnt].p = H,ret[cnt].q = W;
			else
				ret[cnt].p = W,ret[cnt].q = H;
			cnt++;

			//
			
			W = Max(w[0]+w[1],w[2]+w[3]);
			
			if( (h[3]>h[2]&&w[0]>w[2])
				||
				(h[2]>h[3]&&w[1]>w[3])
				)
				H = Max(h[0],h[1])+Max(h[2],h[3]);
			else
				H = Max(h[0]+h[2],h[1]+h[3]);

			if(W>H)
				ret[cnt].p = H,ret[cnt].q = W;
			else
				ret[cnt].p = W,ret[cnt].q = H;
			cnt++;
		}
		return 0;
	}
	
	for(int i = 0 ; i <= 3 ; i++)
	{
		if(flag[i]==0)
		{
			q[d] = i;
			flag[i] = 1;
			DFS(d+1);
			flag[i] = 0;
		}
	}

	return 0;
}

int cmp( const RET &a, const RET &b )
{
    if( a.p * a.q < b.p * b.q )
       return 1;
    if( a.p * a.q == b.p * b.q )
    	if(a.p < b.p)
    		return 1;
    return 0;
}

int main(int argc, char const *argv[])
{
	write;
	read;
	memset(flag, 0, sizeof(flag));
	for(int i = 0 ; i < 40 ; i++)
		scanf("%d %d",&rect[i][0],&rect[i][1]);
	cnt = 0;
	DFS(0);
	sort(ret,ret+1920);
	unique(ret,ret+1920);
	int idx = 0;
	int r = 0;
	r = ret[idx].p * ret[idx].q;
	PF(r);
	while(ret[idx].p * ret[idx].q == r)
	{
		PPF(ret[idx].p, ret[idx].q);
		idx++;
	}
	return 0;
}
