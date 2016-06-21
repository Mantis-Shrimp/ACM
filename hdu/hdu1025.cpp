#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <climits>
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
#include <utility>
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
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}


#define N 5100000

struct way
{
  int x;
  int y;
  bool operator < (const struct way & a) const
  {
    return x < a.x;
  }
};

int dp[N],n;
way ways[N];

int main(int argc,char* argv[])
{
#ifdef DEBUG
  READ;
  //SYNCOFF;
#endif
  int cnt = 1;
  while(scanf("%d",&n)!=EOF)
    {
      for(int i = 0 ; i < n ; i++)
	{
	  //std::cin>>ways[i].x>>ways[i].y;
	  scanf("%d%d",&ways[i].x,&ways[i].y);
	}
      

      std::sort(ways,ways+n,std::less<way>());



      for(int i = 0 ; i < N ; i++)
	dp[i] = INT_MAX;
      for(int i = 0 ; i < n ; i++)
	{
	  *std::lower_bound(dp + 1, dp + n, ways[i].y) = ways[i].y;
	}
      int ret = 1;
      while(dp[ret] != INT_MAX)
	ret ++ ;
      ret = ret - 1;
	
      std::cout<<"Case "<<cnt++<<":"<<std::endl;
      if(ret == 1)
	std::cout<<"My king, at most "<<ret<<" road can be built.\n\n";
      if(ret > 1)
	std::cout<<"My king, at most "<<ret<<" roads can be built.\n\n";
    }
  return 0;
}
