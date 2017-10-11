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

// b不能是負數
uint32_t pow_mod(uint32_t a,uint32_t b ,uint32_t m)   // aᵇ mod m
{
  int32_t x = 1;
  a = a % m;
  while(b>0)
    {
      if (b & 1)
        x =(x * a) % m;
      a = (a * a) %m;
      b = b / 2;
    }
  return x;
}

int32_t main(int32_t argc,char* argv[])
{
  int32_t b,p,m;
  while(cin>>b>>p>>m)
    {
      cout<<pow_mod(b,p,m)<<endl;
    }
  return 0;
}
