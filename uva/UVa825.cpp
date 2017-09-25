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

int32_t dx[] = { 0,-1};
int32_t dy[] = {-1, 0};

int32_t main(int32_t argc,char* argv[])
{
  //  std::cout<<"yqweuiryuiwey";
  int32_t nCase = 0;
  std::cin>>nCase;
  //std::cout<<t<<"312647826357861237857823";
  for(int t = 0 ; t < nCase ; t++)
    {
      int32_t w = 0;
      int32_t n = 0;
      std::cin>>w>>n;
      //     std::cout<<w<<n;

      std::vector<std::vector<int32_t> > city(w, std::vector<int32_t>(n,0));
      std::vector<std::vector<int32_t> > dp1(w, std::vector<int32_t>(n,0));
      std::vector<std::vector<int32_t> > dp2(w, std::vector<int32_t>(n,0));

      //std::string tmp;
      //std::cin>>tmp;
      std::cin.get();

      for(int j = 0 ; j < w ; j++)
        {
          std::string tmp;
          std::getline(std::cin,tmp);
          //   std::cout<<tmp<<std::endl;
          std::istringstream fin = std::istringstream(tmp);

          int32_t tmp_n = 0;
          fin>>tmp_n;
          while(fin>>tmp_n)
            {
              city[j][tmp_n - 1] = -1;
            }
        }


      // for(int32_t i = 0 ; i < city.size(); i++)
      //   {
      //     for(int32_t j = 0; j < city[i].size(); j++ )
      //       {
      //         std::cout<<city[i][j]<<" ";
      //       }
      //     std::cout<<std::endl;
      //   }

      for(int32_t i = 0 ; i < city.size(); i++)
        {
          for(int32_t j = 0 ; j < city[i].size(); j++)
            {

              int32_t tmp = INT_MAX / 2;
              for(int32_t k = 0 ; k < 2 ; k++)
                {
                  int32_t y = i + dy[k];
                  int32_t x = j + dx[k];
                  if ( is_in_square(x, y, 0, 0, (int32_t)city[y].size() , (int32_t)city.size() ) && city[y][x] == 0)
                    {
                      if(tmp > dp1[y][x])
                        tmp = dp1[y][x];
                    }
                }

              if( i == 0 && j == 0)
                dp1[i][j] = 0;
              else dp1[i][j] = tmp + 1;

              tmp = 0;
              for(int32_t k = 0 ; k < 2 ; k++)
                {
                  int32_t y = i + dy[k];
                  int32_t x = j + dx[k];
                  if ( is_in_square(x, y, 0, 0,(int32_t)city[y].size() , (int32_t)city.size()) && city[y][x] == 0)
                    {
                      if(dp1[i][j]  == dp1[y][x] + 1 )
                        {
                          tmp += dp2[y][x];
                        }
                    }
                }

              if(i == 0 && j == 0)
                dp2[i][j] = 1;
              else
                dp2[i][j] = tmp;
            }
        }


      // for(int32_t i = 0 ; i < dp1.size(); i++)
      //   {
      //     for(int32_t j = 0; j < dp1[i].size(); j++ )
      //       {
      //         std::cout<<dp1[i][j]<<" ";
      //       }
      //     std::cout<<std::endl;
      //   }

      // for(int32_t i = 0 ; i < dp2.size(); i++)
      //   {
      //     for(int32_t j = 0; j < dp2[i].size(); j++ )
      //       {
      //         std::cout<<dp2[i][j]<<" ";
      //       }
      //     std::cout<<std::endl;
      //   }


      if(t == 0)
        std::cout<<dp2[w-1][n-1]<<std::endl;
      else
        {
          std::cout<<std::endl;
          std::cout<<dp2[w-1][n-1]<<std::endl;
        }
    }
  return 0;
}
