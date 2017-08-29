#include <cstdlib>
//#include <cstdint>
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






int64_t a[25][25];
int32_t n;


int64_t get_a(int32_t i,int32_t j)
{


  if (a[i][j] != -1) return a[i][j];

  int64_t ret = 0;

  if(i < j)
    {
      int64_t tmp = 0;

      for(int32_t k = i; k < j; k++)
        {
          if( get_a(i,k) + get_a(k+1,j)   >tmp  )
            {
              tmp = get_a(i,k) + get_a(k+1,j);
            }
        }

      ret = tmp;
    }

  if(i >= j)
    {
      int64_t tmp1 = 0;

      if(i < n)
        {
          int64_t tmp = 0;

          for(int32_t k = i + 1; k <= n ; k++)
            {
              if (get_a(k,1) + get_a(k,j) > tmp)
                tmp = get_a(k,1) + get_a(k,j);
            }

          tmp1 = tmp;

        }
      else
        {
          tmp1 = 0;
        }


      int64_t tmp2 = 0;

      if(j > 0)
        {
          int64_t tmp = 0;

          for(int32_t k = 1 ; k < j ; k++)
            {
              if(tmp < get_a(i,k) + get_a(n,k))
                tmp = get_a(i,k) + get_a(n,k);
            }

          tmp2 = tmp;
        }
      else
        {
          tmp2 = 0;
        }

      ret = tmp2 + tmp1;
    }


  return a[i][j] = ret;
}


int32_t main(int32_t argc,char* argv[])
{
  memset(a, -1, sizeof(a));
  while(std::cin>>n)
    {
      std::cin>>a[n][1];
      std::cout<<get_a(1,n)<<std::endl;
      memset(a,-1,sizeof(a));
    }
  return 0;
}
