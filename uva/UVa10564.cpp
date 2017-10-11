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
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <fstream>
#include <iomanip>
#include <bitset>
#include <list>
#include <ctime>
#include <climits>
#include <array>

using std::cin;
using std::cout;;
using std::vector;
using std::map;
using std::unordered_map;
using std::stack;
using std::string;
using std::endl;
using std::array;

#define READ            freopen("in.txt", "r", stdin)
#define WRITE           freopen("fracdec.out", "w", stdout)
#define SYNCOFF         std::ios_base::sync_with_stdio(false);
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1

template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline bool IsSquare(T x, T y,T minw, T minh, T maxw ,T maxh)
{
  if(x >= minw && x < maxw && y >= minh && y < maxh)
    return true;
  else
    return false;
}


int32_t main(int32_t argc,char* argv[])
{
  int64_t n,s;
  while(cin>>n>>s && n+s != 0)
    {
      array<array<int64_t,20>,40> m;
      array<array<unordered_map<int64_t,int64_t>,20>,40> dp;

      for(int64_t i = 0 ; i < n ; i++)
        {
          for(int64_t j = 0 ; j < n - i ; j++)
            {
              cin>>m[i][j];
            }
        }

      for(int64_t i = n ; i < n + n - 1 ; i++)
        {
          for(int64_t j = 0; j < i - n + 2  ; j++)
            {
              cin>>m[i][j];
            }
        }


      // for(int64_t i = 0 ; i < n ; i++)
      //   {
      //     for(int64_t j = 0 ; j < n - i ; j++)
      //       {
      //         cout<<m[i][j]<<" ";
      //       }
      //     cout<<endl;
      //   }

      // for(int64_t i = n ; i < n + n - 1 ; i++)
      //   {
      //     for(int64_t j = 0; j < i - n + 2  ; j++)
      //       {
      //         cout<<m[i][j]<<" ";
      //       }
      //     cout<<endl;
      //   }

      for(int64_t i = 0 ; i < n ; i++)
        {
          int64_t tmp = m[n + n - 2][i];
          dp[n + n - 2][i][tmp] = 1;
        }

      for(int64_t i = n + n - 3 ; i >= n - 1  ; i--)
        {
          for(int64_t j = 0; j < i - n + 2 ; j++ )
            {
              int64_t tmp0 = m[i][j];

              for(auto &it : dp[i+1][j+1])
                {
                  dp[i][j][it.first + tmp0]+=it.second;
                }

              for(auto &it : dp[i+1][j])
                {
                  dp[i][j][it.first + tmp0]+=it.second;
                }
            }
        }

      for(int64_t i = n - 2 ; i >= 0 ; i--)
        {
          for(int64_t j = 0; j < n - i ; j++ )
            {

              int64_t tmp0 = m[i][j];

              if(j - 1 >= 0)
                {
                  for(auto &it : dp[i+1][j-1])
                    {
                      dp[i][j][it.first + tmp0]+=it.second;
                    }
                }

              if(j <= n - (i + 1))
                {
                  for(auto &it :  dp[i+1][j])
                    {
                      dp[i][j][it.first + tmp0]+=it.second;
                    }
                }
            }
        }


      int64_t ret = 0;
      for(int64_t i = 0 ; i < n ; i++)
        {
          if( dp[0][i].find(s) != dp[0][i].end())
            {
              ret = ret + dp[0][i][s];
            }
        }

      cout<<ret<<endl;

      if(ret == 0)
        {
          cout<<endl;
          continue;
        }
      for(int64_t i = 0 ; i < n ; i++)
        {
          if( dp[0][i].find(s) != dp[0][i].end())
            {
              ret = i;
              break;
            }
        }


      cout<<ret<<" ";


      s = s - m[0][ret];
      for(int64_t i = 1 ; i < n ; i++)
        {
          if(ret - 1 >= 0)
            {
              if( dp[i][ret-1].find(s) != dp[i][ret-1].end())
                {
                  cout<<"L";
                  s = s - m[i][ret-1];
                  ret = ret -1;
                  continue;
                }
            }

          if(ret <= n - (i + 1))
            {
              if( dp[i][ret].find(s) != dp[i][ret].end())
                {
                  cout<<"R";
                  s = s - m[i][ret];
                  ret = ret;
                }
            }
        }

      for(int64_t i = n ; i < n + n - 1  ; i++)
        {
          if( dp[i][ret].find(s) != dp[i][ret].end())
            {
              cout<<"L";
              s = s - m[i][ret];
              ret = ret;
              continue;
            }

          if( dp[i][ret+1].find(s) != dp[i][ret+1].end())
            {
              cout<<"R";
              s = s - m[i][ret+1];
              ret = ret+1;
            }
        }

      cout<<endl;
    }
  return 0;
}
