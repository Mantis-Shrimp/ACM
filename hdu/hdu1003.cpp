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
#include <climits>
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



int t,n,a[110000],dp[110000],pos[110000];

int main(int argc,char* argv[])
{
#ifndef ONLIN_JUDGE
    READ;
#endif
    std::cin>>t;
    for(int i = 1 ; i <= t ; i++)
    {
	std::cin>>n;
	for(int j = 0 ; j < n ; j++)
	    std::cin>>a[j];

	dp[0] = a[0],pos[0] = 0;

	for(int j = 1 ; j < n ; j++ )
	{
	    if(dp[j-1] >= 0)
	    {
		dp[j] = dp[j-1] + a[j];
		pos[j] = pos[j-1];
	    }
	    else
	    {
		dp[j] = a[j];
		pos[j] = j;
	    }   
	}

	int ret = INT_MIN;
	int idx = 0;

	for(int j = 0 ; j < n ; j++)
	{
	    if(ret < dp[j])
	    {
		ret = dp[j];
		idx = j;
	    }
	}

	std::cout<<"Case "<<i<<":"<<std::endl;
	std::cout<<ret<<" "<<pos[idx]+1<<" "<<idx+1<<std::endl;
	if(i != t)
	    std::cout<<std::endl;
    }
    return 0;
}
