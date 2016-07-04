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

//const int N = 30;

long long dp[12][1<<12];
int w,h;


int init(int sta, int pos)
{
  if(pos == w)
    {
      dp[0][sta] = 1;
      return 0;
    }

  if(pos + 1 <= w)
    init(sta,pos+1);
  
  if(pos + 2 <= w)
    init(sta|3<<pos,pos+2);

  return 0;
}

int pushdp(int ih,int presta,int nextsta,int pos)
{
  if(pos >= w)
    {
      dp[ih+1][nextsta] = dp[ih+1][nextsta] + dp[ih][presta];
      return 0;
    }

  pushdp(ih,presta,nextsta,pos+1);

  if(pos <= w -2 && !(nextsta & (1<<pos) ) && !(nextsta & (1 << (pos + 1)  ) ) )
    pushdp(ih, presta,nextsta | 1 << pos | 1 << (pos+1)  ,pos + 2);

  return 0;
  
}


int main(int argc,char* argv[])
{
    #ifdef DEBUG
    READ;
    #endif

    while(std::cin>> h >>w && !(h==0 && w==0 ))
      {
	
#ifdef DEBUG
	std::cout<<h<<" "<<w<<std::endl;
#endif
	memset(dp,0,sizeof(dp));
	init(0,0);

	for(int i = 0; i < h ; i++)
	  {
	    for(int j = 0 ; j < (1<<w) ; j++ )
	      {
		pushdp(i,j,~j & ((1<<w)-1) ,0);
	      }
	  }
	std::cout<<dp[h-1][(1 << w) -1 ]<<std::endl;
      }
    return 0;
}
