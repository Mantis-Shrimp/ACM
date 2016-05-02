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
//#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}

struct cover
{
  double s;
  double e;
  int flag;
  bool operator < (const cover &tmp) const
  {
    return s < tmp.s;
  }
};

#define MAX 1100

int n,d;
int px[MAX],py[MAX];
cover c[MAX];

int main(int argc,char* argv[])
{
  //READ;
  int T = 0;
  while( (std::cin>>n>>d) && (n!=0||d!=0))
    {
      T = T + 1;
      for(int i = 0; i < n ; i++)
	std::cin>>px[i]>>py[i];
      //for(int i = 0; i < n ; i++)
      //	{
      //	  std::cout<<px[i]<<" "<<py[i]<<std::endl;
      //	}


      int ret = 0;
      int flag = 1;
      for(int i = 0; i < n ; i++)
	{
	  double x = px[i];
	  double y = py[i];
	  if(d < py[i] )
	    {
	      flag = -1;
	      break;
	    }
	  double tmp = sqrt( d * d - y * y  ) ;
	   c[i].s = x - tmp;
	   c[i].e = x + tmp;
	   c[i].flag = 0;
	}

      if(flag == -1)
	{
	  std::cout<<"Case"<<" "<<T<<": "<<"-1"<<std::endl;
	  continue;
	}

      std::sort(c,c+n,less<cover>());


      while(1)
	{
      int idx = -1;
      double m = 0;

      for(int i = 0 ; i < n ; i++)
	{
	  if(c[i].flag == 0)
	    {
	      if(idx == -1)
		{
		  idx = i;
		  m = c[i].e;
		}
	      else
		{
		  if(m > c[i].e)
		    {
		      m = c[i].e;
		      idx = i;
		    }
		}
	    }
	}


      if(idx == -1)
	{
	   std::cout<<"Case"<<" "<<T<<": "<<ret<<std::endl;
	   break;
	}

      ret = ret + 1;

      for(int i = 0 ; i < n ; i++)
	{
	  if(m >= c[i].s)
	    {
	      c[i].flag = 1;
	    }
	  if(m < c[i].s )
	    break;
	}
	}
      
    }
}
