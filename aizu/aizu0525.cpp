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
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}



int r,c;
int grid[11][10001];
int row[10];
int ret;


int dfs(int d)
{
  if(d == r)
    {

      // for(int i = 0 ; i < 10 ; i++)
      // 	std::cout<<row[i]<<" ";
      // std::cout<<std::endl;

      int total = 0;
      for(int j = 0 ; j < c;j++)
	{
	  int t0,t1;
	  t0 = t1 = 0;

	  for(int i = 0 ; i < r ; i++)
	    {
	      t0 += (grid[i][j] + row[i]) % 2;
	    }

	  for(int i = 0 ; i < r ; i++)
	    {
	      t1 += (grid[i][j] + row[i] + 1) %2;
	    }

	  total = total + Max(t0 , t1);
	}
      //std::cout<<total<<std::endl; 
      AMax(ret,total);
      return 1;
    }
  for(int i = 0 ; i < 2 ;i++)
    {
      row[d] = i;
      dfs(d+1);
    }
  return 1;
}

int main(int argc,char* argv[])
{
  //READ;
  while( std::cin>>r>>c )
    {
      if((r==0)&&(c==0))
	break;
      
      for(int j = 0 ; j < r ; j++)
	for(int i = 0 ; i < c; i++)
	  std::cin>>grid[j][i];
      
      for(int j = 0 ; j < r ; j++)
	{
	  // for(int i = 0 ; i < c; i++)
	  //   std::cout<<grid[j][i]<<" ";
	  // std::cout<<std::endl;
	}
      ret = 0;
      dfs(0);
      std::cout<<ret<<std::endl;
      
    }
  return 0;
}
