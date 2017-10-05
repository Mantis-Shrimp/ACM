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
template<class T> inline bool is_in_square(T x, T y,T minw, T minh, T maxw ,T maxh)
{
  if(x >= minw && x < maxw && y >= minh && y < maxh)
    return true;
  else
    return false;
}



array<array<int,110>,110> C;

int32_t main(int32_t argc,char* argv[])
{
  for(int32_t i = 1 ; i <= 100 ; i++)
    C[i][1] = C[i][i + 1] = 1;

  for(int32_t j = 2 ; j <= 100 ; j++)
    {
      for(int32_t i = 2 ; i <= j+1 ; i++)
        {
          C[j][i] = C[j-1][i] + C[j-1][i-1];
        }
    }

  int32_t n,m;

  while(cin>>n>>m && !(n== 0 && m == 0) )
    {
      cout<<n<<" things taken "<<m<<" at a time is "<<C[n][m+1]<<" exactly."<<endl;
    }

  return 0;
}
