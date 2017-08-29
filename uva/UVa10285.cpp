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



int32_t n,r,c;
int32_t m[105][105];
int32_t dp[105][105];
string name;


int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int get_max_height(int y,int x)
{
  if (dp[y][x] != -1)
    return dp[y][x];


  bool flag = true;
  for(int32_t i = 0 ; i < 4 ; i++)
    {
      int32_t tmpx = x + dx[i];
      int32_t tmpy = y + dy[i];

      if(tmpy >=0 && tmpy < r && tmpx >= 0 && tmpx  <c )
        if (m[tmpy][tmpx] < m[y][x])
          flag = false;
    }

  if(flag == true)
    return dp[y][x] = 0;


  int32_t ret = 0;

  for(int32_t i = 0 ; i < 4 ; i++)
    {
      int32_t tmpx = x +dx[i];
      int32_t tmpy = y +dy[i];

      if(tmpy >= 0 && tmpy < r && tmpx >= 0 && tmpx < c)
        {
          if(m[tmpy][tmpx] < m[y][x])
            if( get_max_height(tmpy, tmpx) > ret )
              ret = get_max_height(tmpy, tmpx);
        }
    }

  return dp[y][x] = ret + 1;


}



int main(int argc,char* argv[])
{

  std::cin>>n;
  std::cin.get();

  while(n--)
    {
      std::cin>>name>>r>>c;

      for(int j = 0 ; j < r ; j++)
        for(int i = 0 ; i < c ; i++)
          {
            std::cin>>m[j][i];
            dp[j][i] = -1;
          }

      int32_t ret = 0;
      for(int j = 0 ; j < r ; j++)
        {
          for(int i = 0 ; i < c ;i++)
            {
              dp[j][i] = get_max_height(j, i);
              if(dp[j][i] > ret)
                ret = dp[j][i];
            }
        }

      std::cout<<name<<": "<<ret+1<<std::endl;

    //   for(int j = 0 ; j < r ; j++ )
    //     {
    //       for(int i = 0 ; i < c ; i++)
    //         {
    //           std::cout<<dp[j][i]<<" ";
    //         }
    //       std::cout<<std::endl
    //     }
    }

  return 0;
}
