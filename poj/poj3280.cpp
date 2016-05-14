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
#define SZ(arr)         (int)arr.size()
#define SWAP(a,b)       a=a xor b;b= a xor b;a=a xor b;
#define READ            freopen("in.txt", "r", stdin)
#define WRITE           freopen("fracdec.out", "w", stdout)
#define SYNCOFF         std::ios_base::sync_with_stdio(false);
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}


int n,m;
char str[2100];
int dp[2100][2100];
int del[200],ins[200];

int getMin(int s,int e)
    {
	if( s >= e ) return 0;
	if(dp[s][e] != -1 ) return dp[s][e];

	int a;
	int b;
	int c;
	int d;
	int f;

	if( str[s] == str[e] )
	    f = getMin(s+1,e-1);
	else
	    f = getMin(s+1,e-1) + del[str[s]] + del[str[e]] ;

	a = getMin(s+1,e) + del[str[s]];

	b = getMin(s,e-1) + del[str[e]];

	c = getMin(s,e-1) + ins[str[e]];

	d = getMin(s+1,e) + ins[str[s]];

	dp[s][e] = Min(a,Min(b,Min(c,Min(d,f))));

	return dp[s][e];
    }




int main(int argc,char* argv[])
    {

#ifndef ONLINE_JUDGE
	READ;
#endif
	std::cin>>n>>m;
	std::cin.getline(str,2100);
	std::cin.getline(str,2100);
	char ch;
	for(int i = 0 ; i < n ; i++)
	    {
		std::cin>>ch;
		std::cin>>ins[ch];
		std::cin>>del[ch];
	    }
	memset(dp,-1,sizeof(dp));

	std::cout<<getMin(0,m-1)<<std::endl;
    }
