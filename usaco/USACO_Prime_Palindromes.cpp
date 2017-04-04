/*
ID: 15864532
PROG: pprime
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
#define read            freopen("pprime.in", "r", stdin)
#define write           freopen("pprime.out", "w", stdout)
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}


inline int IsPrime(int n)
{
	for(int i = 2; i * i <= n ; i++)
		if(n%i==0) return 0;
	return 1;
}

set<int> ma;
int m,n,lm,ln;

int main(int argc, char const *argv[])
{
	
	write;
	read;
	SD(m);
	SD(n);

	int tmp = 0;
	// 1
	for(int a = 2 ; a <= 9 ; a++ )
		if(a >= m && a <= n)
			if(IsPrime(a)==1) ma.insert(a);

	// 2 
	for(int a = 1 ; a <= 9 ; a++)
	{
		tmp = 10*a +a;
		if(tmp >= m && tmp <= n)
		{
			if(IsPrime(tmp)==1)
				ma.insert(tmp);
		}
	}

	//3 4
	for(int a = 0 ; a <= 9 ; a++)
	{
		for(int b = 1 ; b <= 9 ; b+=2)
		{
			//3
			tmp = 100*b +10*a + b;
			if(tmp >= m && tmp <= n)
			{
				if(IsPrime(tmp)==1)
					ma.insert(tmp);
			}


			//4
			tmp = 1000*b +100*a + 10*a + b;
			if(tmp >= m && tmp <= n)
			{
				if(IsPrime(tmp)==1)
					ma.insert(tmp);
			}

		}
	}


	// 5  6
	for(int a = 0; a <= 9 ; a++)
	{
		for(int b = 0 ; b <= 9 ; b++)
		{
			for(int c = 1 ; c <= 9 ; c+=2)
			{
				//5
				tmp = 10000*c +1000*b + 100*a +10*b + c;
				if(tmp >= m && tmp <= n)
				{
					if(IsPrime(tmp)==1)
						ma.insert(tmp);
				}
				//6
				tmp = 100000*c +10000*b + 1000*a+100*a +10*b + c;
				if(tmp >= m && tmp <= n)
				{
					if(IsPrime(tmp)==1)
						ma.insert(tmp);
				}
			}
		}

	}


	// 7  8
	for(int a = 0; a <= 9 ; a++)
	{
		for(int b = 0 ; b <= 9 ; b++)
		{
			for(int c = 0 ; c <= 9 ; c++)
			{
				for(int d = 1; d <= 9; d+=2)
				{
					//7
					tmp = 1000000*d+ 100000*c +10000*b + 1000*a +100*b + 10*c + d;
					if(tmp >= m && tmp <= n)
					{
						if(IsPrime(tmp)==1)
							ma.insert(tmp);
					}

					//8
					tmp = 10000000*d+ 1000000*c +100000*b + 10000*a + 1000*a + 100*b + 10*c + d;
					if(tmp >= m && tmp <= n)
					{
						if(IsPrime(tmp)==1)
							ma.insert(tmp);
					}
				}
				
			}
		}
	}



	for(set<int>::iterator it = ma.begin() ; it!=ma.end() ; it++)
		PF(*it); 

	// system("pause");
	return 0;
}