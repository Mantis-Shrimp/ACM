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
#include <utility>
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
//template<class T> inline T Min(T a,T b){return a>b?b:a;}
//template<class T> inline T Max(T a,T b){return a>b?a:b;}


#define ZERO 100000
int n,si,fi,dp[2][210000];

int main(int argc,char* argv[])
{
  
#ifdef DEBUG
  READ;
#endif
  
  std::cin>>n;
  //memset(dp,0,sizeof(dp));
  for(int j = 0 ; j < 110 ; j++)
    for(int i = 0 ; i < 210000; i++)
      dp[j%2][i] = INT_MIN;

  dp[0][ZERO] = 0;

  for(int i = 0 ; i < n ; i++)
    {

      std::cin>>si>>fi;
#ifdef DEBUG
      std::cout<<si<<" "<<fi<<std::endl;
#endif

      


      
      for(int j = -ZERO ; j <= ZERO; j++)
	{
	  if(dp[i%2][j + ZERO ] != INT_MIN)
	    {
	      int tmps = dp[i%2][j + ZERO] + si ;
	      int tmpf = j + fi;
	      
	      if(tmps >  dp[(i+1)%2][tmpf+ZERO] )
		dp[(i+1)%2][tmpf+ZERO] = tmps;

	      if(dp[i%2][j+ZERO] > dp[(i+1)%2][j+ZERO])
		dp[(i+1)%2][j+ZERO] = dp[i%2][j+ZERO];
	    }
	}
      
#ifdef DEBUG
      std::cout<<i+1<<std::endl;
      for(int k = -ZERO ; k <= ZERO; k++ )
	std::cout<<dp[(i+1)%2][k + ZERO ]<<" ";
      std::cout<<std::endl;
#endif
    }


  int ret = INT_MIN;
  for(int i = -ZERO; i <= ZERO ; i++)
    {
      if(dp[n%2][i+ZERO]>=0 && i >=0 )
	{
	  AMax(ret,i+dp[n%2][i+ZERO]);
	}
    }


  std::cout<<ret<<std::endl;
  return 0;
}
