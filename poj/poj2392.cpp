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

struct block
{
    int hi;
    int ai;
    int ci;

    bool operator < (const struct block& b) const
	{
	    return ai < b.ai;
	}
};

block blocks[410];
int dp[41000],k;


int main(int argc,char* argv[])
{
    
#ifndef ONLINE_JUDGE
    READ;
#endif
    std::cin >> k;
    for(int i = 0 ; i < k ; i++)
    {
	std::cin>>blocks[i].hi>>blocks[i].ai>>blocks[i].ci;
    }
    sort(blocks,blocks+k);

#ifndef ONLINE_JUDGE
    for(int i = 0 ; i < k ; i++)
    {
	std::cout<<blocks[i].hi<<blocks[i].ai<<blocks[i].ci<<std::endl;
    }
#endif

    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    
    for(int i = 0; i < k ; i++)
    {
	for(int j = blocks[i].ai; j >= 0 ; j --)
	{
	    for(int l = 0 ; l <= blocks[i].ci ; l++)
	    {
		int tmp = j - l * blocks[i].hi;

		if(tmp >= 0)
		    if(dp[tmp] == 1 )
			dp[j] = 1;
	    }
	}
    }


    for(int i = 40000 ; i >= 0 ; i--)
    {
	if(dp[i] == 1)
	{	   
	    std::cout<<i<<std::endl;
	    break;
	}
    }
    return 0;
}
