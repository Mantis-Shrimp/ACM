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

int t,w;

int dp[1100][35],apple[1100];

int main(int argc,char* argv[])
{
  //READ;
  memset(dp,0,sizeof(dp));
  std::cin>>t>>w;
  for(int i = 0 ; i < t; i++)
    {
      std::cin>>apple[i];
    }
  if(apple[0] == 1)
    dp[0][0] = 1;
  else
    dp[0][0] = 0;

  for(int i = 1; i < t; i++)
    {
      if(apple[i] == 1 )
	{
	  dp[i][0] = dp[i-1][0] + 1;
	}
      else
	{
	  dp[i][0] = dp[i-1][0];
	}
	
    }

  for(int i = 1 ; i <= w ; i++)
    {
      dp[0][i] = 1;
    }


  for(int i = 1 ; i < t ; i++)
    {
      for(int j = 1 ; j <= w ; j++)
	{
	  dp[i][j] = Max(dp[i-1][j-1],dp[i-1][j]) + (((apple[i] % 2)  ==  ((j +1) %2))  ? 1 : 0 );
	}
    }

  int ret = 0;
  for(int i = 0 ; i < t ; i++)
    {
      for(int j = 0 ; j <= w ; j++)
	{
	  //std::cout<<dp[i][j]<<" ";
	  if(ret < dp[i][j])
	    ret = dp[i][j];
	}
      //std::cout<<std::endl;
    }


  std::cout<<ret<<std::endl;
  return 0;
}
