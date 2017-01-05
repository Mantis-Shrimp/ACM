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
using namespace std;
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
#define read            freopen("in.txt", "r", stdin)
#define write           freopen("lamps.out", "w", stdout)
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}


int t,n,c[100],S,sq[100],flag;
int ret[100];


int DFS(int d)
{
	int pos,r = 0,min = 100,flag,m;
	if(d == n)
	{
		r = 1;

		for(int i = 1 ; i <= S ; i++)
		{
			if(sq[i] != S)
			{
				r = 0;
				break;
			}
		}

		return r;
	}
	
	for(int i = 1 ; i <= S ; i++)//
	{
		if(sq[i] < min) 
		{
			min = sq[i];
			pos = i;
		}
	}

	m = 0;
	while(sq[pos]==sq[pos+m]) m++;

	if(m > S - min)
		m = S - min;



	for(int i = m ; i >= 1 ; i--)
	{
		if(c[i]>0)
		{	
				c[i]--;
				for(int j =  0; j < i; j++)
					sq[j+pos] = sq[j+pos] + i;
				
				if(DFS(d+1)==1) 
					return 1;
				
				c[i]++;
				for(int j =  0; j < i; j++)
					sq[j+pos] = sq[j+pos] - i;
		}
	}

	return 0;
}

int main(int argc, char const *argv[])
{
	int s0,size;
	SD(t);
	while(t--)
	{
		size = 0;
		SD(S);
		SD(n);
		SET(c,0);
		for(int i = 1 ; i <= n ; i++)
		{
			SD(s0);
			c[s0]++;
			size += (s0 * s0); 
		}
		SET(sq,0);
		
		if(size == S*S)
		{
			if(DFS(0)==1)
				printf("KHOOOOB!\n");
			else
				printf("HUTUTU!\n");
		}
		else
			printf("HUTUTU!\n");
	}
	return 0;
}