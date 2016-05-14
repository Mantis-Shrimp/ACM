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


long long dp[1000000+5][21];
long long num[21];
int n;

long long search(int n,int l)
{
  long long ret = 0;
  for(int i = l ; i >= 0 ; i--)
    {
      int tmpn = n - num[i];

      if(tmpn > 0)
	{
	  if(dp[tmpn][i] == -1 )
	    {

	      dp[tmpn][i] = search(tmpn,i) ; 
	      //if(dp[tmpn][i] > 1000000000 )
	      //	dp[tmpn][i] = dp[tmpn][i] % 1000000000;
	      ret = (ret +  dp[tmpn][i])  ;

	      //if(ret > 1000000000)
	      //	ret = ret % 1000000000;
	    }
	  else
	    {
	      ret = (ret +  dp[tmpn][i])  ;
	      //if(ret > 1000000000)
	      //	ret = ret % 1000000000;
	    }
	}
      if(tmpn == 0)
	{
	  ret = ret + 1;
	}
    }

  if(ret < 1000000000)
    return ret;
  else
    return ret % 1000000000;
}

int main(int argc,char* argv[])
{
  memset(dp,-1,sizeof(dp));
  while(std::cin>>n)
    {
      num[0] = 1;
      for(int i = 1 ; i < 21 ; i++)
	num[i] = num[i-1] * 2;
      long long ret = search(n,20) % 1000000000;
      std::cout<<ret<<std::endl;
    }
  return 0;
}
