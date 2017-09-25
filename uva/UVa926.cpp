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
#include <array>

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

template<class T>
inline bool is_in_square(T x, T y,T minw, T minh, T maxw ,T maxh)
{
  if(x >= minw && x < maxw && y >= minh && y < maxh)
    return true;
  else
    return false;
}



int32_t c = 0;

int32_t main(int32_t argc,char* argv[])
{
  std::cin>>c;

  for(int32_t t = 0 ; t < c ; t++)
    {
      int32_t n = 0;
      int32_t startx,starty,endx,endy;
      std::cin >> n >> startx >> starty >> endx >>endy;

      std::vector<std::vector<int32_t> > m(n + 1,std::vector<int32_t>(n + 1,0));
      std::vector<std::vector<std::array<int32_t,2> > > r(n + 1,std::vector<std::array<int32_t,2> >(n + 1,{0,0}));
      std::vector<std::vector<int64_t> > dp(n + 1,std::vector<int64_t>(n + 1,0));

      int32_t w,px,py;
      char ch;
      std::cin >> w;
      for(int32_t i = 0 ; i < w ; i++)
        {
          std::cin >> px >>py;

          scanf(" %c",&ch);
          if(ch == 'S')
            {
              r[px][py][0] = 1;
            }

          if(ch == 'N')
            {
              r[px][py+1][0] = 1;
            }

          if(ch == 'W')
            {
              r[px][py][1] = 1;
            }

          if(ch == 'E')
            {
              r[px+1][py][1] = 1;
            }
        }

      dp[startx][starty] = 1;

      for(int32_t i =  starty; i < endy + 1 ; i++)
        {
          for(int32_t j = startx; j < endx + 1; j++ )
            {
              if(  r[j][i][0] != 1)  dp[j][i] = dp[j][i] + dp[j][i-1];
              if(  r[j][i][1] != 1)  dp[j][i] = dp[j][i] + dp[j-1][i];
            }
        }
      std::cout<<dp[endx][endy]<<std::endl;

    }

  return 0;
}
