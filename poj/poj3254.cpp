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



int const mod = 100000000;
int m,n;
int farm[13],dp[13][1<<13];



int init()
{
  for(int i = 0 ; i < (1 << n) ; i++)
    {
            
      if( (( i & (i << 1)) == 0  )  && ( (i & (~farm[0])) ==0  ) )
	{
	  dp[0][i] = 1;
#ifdef DEBUG
	  std::cout << "i = " << i << std::endl;
	  //std::cout << farm[0] << std::endl;
#endif
	}
    }
  return 0;
}

int dfs(int im,int in,int tmp,int d)
{
  if(d == n)
    {
      if( (tmp & (tmp << 1)) == 0 )
	if(( tmp & (~farm[im+1])  ) == 0 )
	  if((tmp & in) ==0 )
	    dp[im+1][tmp] = (dp[im+1][tmp] + dp[im][in]) % mod;

      return 1;
    }
  
#ifdef DEBUG
  std::cout<<"tmp="<<tmp<<std::endl;
  std::cout<<"farm[im+1]="<<farm[im+1]<<std::endl;
  std::cout<<"in"<<in<<std::endl;
#endif
    
  dfs(im,in,tmp,d+1);
  dfs(im,in,tmp|(1<<d),d+1);
  
  return 1;
}


int main(int argc,char* argv[])
{
    #ifdef DEBUG
    READ;
    #endif

    std::cin>>m>>n;

    memset(dp,0,sizeof(dp));
    memset(dp,0,sizeof(farm));
    
    for(int i = 0 ; i < m ; i++)
      {
	for(int j = 0 ; j < n ; j++)
	  {
	    int tmp = 0;
	    std::cin>>tmp;

	    if(tmp == 1)
	      farm[i] = farm[i] + (1 << j);
	  }
#ifdef DEBUG
	std::cout<<"farm: "<<farm[i]<<std::endl;
#endif
      }

    init();

    for(int i = 0 ; i < m ; i++)
      {
	for(int j = 0 ; j < (1 << n) ; j++)
	  {
	    if(dp[i][j] != 0)
	      dfs(i,j,0,0);
	  }
      }

    int ret = 0;

    for(int i = 0 ; i < (1 << n) ; i++)
      {
	ret = (ret + dp[m-1][i]) % mod;
      }
    std::cout<<ret<<std::endl;
    return 0;
}
