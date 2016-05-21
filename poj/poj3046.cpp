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


int t,a,s,b;
int dp[2][101000];
int ni[1010];

int main(int argc,char* argv[])
{
#ifndef ONLINE_JUDGE
    READ;
#endif
    std::cin>>t>>a>>s>>b;
    for(int i = 1 ; i <= a ; i++)
    {
	    int tmp = 0;
	    std::cin>>tmp;
	    ni[tmp]++;
    }
    memset(dp,0,sizeof(dp));
    for(int i = 0 ; i < 1010 ; i++)
	dp[i%2][0] = 1;
    //dp[0][0] = 1;
    for(int i = 1 ; i <= t ; i++)
    {

	    //if(j < ni[i])
	    //	{
	    //	    int tmp = 0;
	    //	    for(int )
	    //	}

	    
	    for(int j = 1; j <= b; j++)
	    {
		if(j  - 1 - ni[i] < 0)
		{
		    int tmp = 0;
		    for(int k = 0 ; k <= ni[i] ; k++)
		    {
			if(j - k >= 0)
			    tmp = (tmp + dp[(i-1)%2][j-k])%1000000;
		    }
		    dp[i%2][j] = tmp;
		}
		else
		{
		    dp[i%2][j] = (dp[i%2][j-1] + dp[(i-1)%2][j] - dp[(i-1)%2][j-1-ni[i]]  + 1000000  )%1000000;
		}
	    }

//	{
	    //	    if(j - 1 >= ni[i])
	    //		dp[i][j] = dp[i][j-1] + dp[i-1][j-1] - dp[i-1][j-1-ni[i]];
	    //	    else
	    //		dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
	    //	}
    }

#ifndef ONLINE_JUDGE
    for(int i = 0 ; i <= t ; i++)
	{
	    for(int j = 0 ; j <= b ; j++)
		{
		    std::cout<<dp[i%2][j]<<" ";
		}
	    std::cout<<std::endl;
	}
#endif


    int ret = 0;
    for(int i = s; i <= b ; i++)
	ret = (ret + dp[t%2][i]) % 1000000;
    std::cout<<ret <<std::endl;
    return 0;
}
