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

int n,m,r;
int s[1100],e[1100],p[1100],dp[1100];


int dfs(int idx)
{

  if(dp[idx] != -1 )
    return dp[idx];

  int tmps = s[idx];
  int tmpe = e[idx];
  int max = 0;
  for(int i = 0 ;  i < m; i++)
    {
      if(tmps >=  e[i] + r)
	{
	  if(dp[i] == -1)
	    dp[i] = dfs(i);

	  if(max < dp[i])
	    max = dp[i];
	}
    }
  dp[idx] = max + p[idx];
  return dp[idx];
}


int main(int argc,char* argv[])
{
  //READ;
  memset(dp,-1,sizeof(dp));
  std::cin>>n>>m>>r;
  int max = 0;
  for(int i = 0 ; i < m ; i++)
    {
      std::cin>>s[i]>>e[i]>>p[i];
    }
  for(int i = 0 ; i < m ; i++)
    dfs(i);

  for(int i = 0  ; i < m ; i++)
    {
      if(max < dp[i])
	max = dp[i];
    }

  std::cout<<max<<std::endl;
  return 0;
}
