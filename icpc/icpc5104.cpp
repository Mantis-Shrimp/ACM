#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
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


#define SWAP(a,b)       a=a xor b;b= a xor b;a=a xor b;
#define READ            freopen("in.txt", "r", stdin)
#define WRITE           freopen("fracdec.out", "w", stdout)
#define SYNCOFF         std::ios_base::sync_with_stdio(false);
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline bool is_in_square(T x, T y,T minw, T minh, T maxw ,T maxh)
{
  return x >= minw && x < maxw && y >= minh && y < maxh;
}

using std::cin;
using std::cout;
using std::vector;
using std::array;
using std::map;
using std::endl;


double getMax(int x,vector<double>& dp,vector<double> &p, vector<double> &w, vector<vector<std::pair<int, double> > >& graph)
{
  if( dp[x] != -1 ) return dp[x];
  dp[x] = p[x];
  for(int32_t i = 0 ; i < graph[x].size() ; i++)
    {
      dp[x] = std::max(getMax(graph[x][i].first,dp,p,w,graph)* graph[x][i].second, dp[x]);
    }
  return dp[x];
}

int32_t main(int32_t argc,char* argv[])
{
  int32_t n;
  while(std::cin>>n && n != 0)
    {
      vector<double> p(n);
      vector<double> w(n);
      vector<double> dp(n,-1);
      vector<vector<std::pair<int,double> > > graph(n);
      for(int i = 0 ; i < n ; i++)
        {
          std::cin>>p[i]>>w[i];
          //    std::cout<<p[i]<<" "<<w[i]<<std::endl;
        }

      int32_t m;
      std::cin>>m;
      //std::cout<<m<<std::endl;

      for(int i = 0 ; i < m ; i++)
        {
          int32_t k,a0,a1;
          double b;
          std::cin>>k>>a0;
          for(int j = 0 ; j < k - 1 ; j++)
            {
              std::cin>>b>>a1;
              graph[a0-1].push_back(std::make_pair(a1-1,b));
              a0 = a1;
            }
        }

      double ret = 0;
      for(int i = 0 ; i < n ; i++)
        {
        	ret = ret + getMax(i,dp,p,w,graph) * w[i];
        }

      // for(auto tmp0 : from)
      //   {
      //     for(auto tmp1 : tmp0)
      //       std::cout<<tmp1<<" ";
      //     std::cout<<std::endl;
      //   }
      // std::cout<<std::endl;
      // for(auto tmp0 : ratio)
      //   {
      //     for(auto tmp1 : tmp0)
      //       std::cout<<tmp1<<" ";
      //     std::cout<<std::endl;
      //   }

      //std::cout<<std::endl;

      //std::cout<<std::fixed<<std::setprecision(2)<<ret<<std::endl;
        printf("%.2f\n",ret);
    }

  return 0;
}
