#include <cstdlib>
#include <cstdint>
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


uint64_t dp[100][100];

uint64_t  get_trib(int32_t n, int32_t back)
{



  uint64_t ret = 0;

  if(n<=0) return 1;
  if(n==1) return 1;


  if(dp[n][back] != -1)
    return dp[n][back];


  for(int32_t i = 1; i <= back; i++)
    ret += get_trib(n-i,back);


  ret = ret + 1;
  return dp[n][back] = ret;
}


int32_t main(void)
{
  int32_t t = 0;
  int32_t n,back;
  while(true)
    {

      t = t + 1;
      std::cin>>n>>back;

      if(n > 60)
        {
          return 0;
        }

      for(int32_t i = 0 ; i <= n ; i++)
        {
          for(int32_t j = 0 ; j <= back ; j++)
            {
              dp[i][j] = -1;
            }
        }

      std::cout<<"Case "<<t<<": "<<get_trib(n, back)<<std::endl;
    }
}



