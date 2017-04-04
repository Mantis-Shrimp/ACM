/*
ID: 15864532
PROG:fracdec
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
#define READ            freopen("fracdec.in", "r", stdin)
#define WRITE           freopen("fracdec.out", "w", stdout)
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}


const int N = 1500000;

int hash[N],circle,co;
int n,d,idx,s,z;
char buff[N],ret[N];

int read()
{
	READ;
	WRITE;
	scanf("%d %d",&n,&d);
}

int run()
{
	int c,tmp;
	idx = 0;
	circle = 0;
	SET(hash, -1);
	while(1)
	{
		// ret[idx] = n / d;
		// printf("ret = %d ", n /d );
		tmp = n / d;
		n = n % d;
		n = n * 10;

		sprintf(&ret[idx],"%d",tmp);
		// printf("c = %d \n", n);
		if(idx == 0)
			z = strlen(&ret[idx]);
		
		if(n == 0)
		{
			circle = 0;
			idx += strlen(&ret[idx]);
			break;
		}
		else
		{
			if(hash[n]==-1)
			{
				idx += strlen(&ret[idx]);
				hash[n]=idx;
			}
			else
			{
				circle = 1;
				idx += strlen(&ret[idx]);
				s = hash[n];
				break;
			}
		}
		
	}
}

int main(int argc, char const *argv[])
{
	read();
	run();
	co=0;


	int tmp,count = 0;
	if(circle==1)
	{
		for(int i = 0 ; i < idx ; i++)
		{			
			
			if(i == s)
				// printf("(");
				buff[co++] = '(';
			// printf("%d",ret[i]);
			buff[co++] = ret[i] ;
			if((i+1)==z)
				// printf(".");
				buff[co++] = '.';
			if(i == idx -1)
				// printf(")");
				buff[co++] = ')';
		}
	}
	else
	{
		for(int i = 0 ; i < idx ; i++)
		{			
			// printf("%d",ret[i]);
				buff[co++] = ret[i];
			if((i+1)==z)
				// printf(".");
				buff[co++] = '.';
			if(i==0&&idx==1)
				// printf("0");
				buff[co++] = '0';
		}
	}


	for(int i = 0 ; i < co ; i++)
	{
		printf("%c",buff[i]);
		if((i+1)%76==0)
			printf("\n");
	}
	printf("\n");
	return 0;
}