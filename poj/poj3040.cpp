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

struct coin
{
  int d;
  int c;
  bool operator > (const coin & a) const
  {
    return d > a.d;
  }
};

int n,c;
struct coin coins[25];

int main(int argc,char* argv[])
{
  //READ;
  std::cin>>n>>c;
  for(int i = 0 ; i < n ; i++)
    {
      std::cin>>coins[i].d>>coins[i].c;
    }
  sort(coins,coins+n,std::greater<coin>());

  int r = 0;

  for(int i = 0 ; i < n ; i++)
    {
      if(coins[i].d >= c)
	{
	  r = r + coins[i].c;
	  coins[i].c = 0;
	}
    }

  int tmp = 0;
  
  do
    {
      tmp = 0;
      for(int i = 0 ; i < n ; i++)
	{
	  while(coins[i].c >= 1 && coins[i].d + tmp <= c)
	    {
	      coins[i].c -- ;
	      tmp = tmp + coins[i].d;
	    }
	}
      
      if(tmp == c)
	{
	  r = r + 1;
	  continue;
	}

      for(int i = n - 1; i >= 0 ; i--)
	{
	  while(coins[i].c >=1 &&  tmp < c )
	    {
	      coins[i].c --;
	      tmp = tmp + coins[i].d;
	    }
	}

      if(tmp >= c)
	{
	  r = r + 1;
	}
      
    }while(tmp >= c );

    std::cout<<r<<std::endl;
  return 0;
}
