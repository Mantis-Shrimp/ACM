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
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}

#define N 100000

int dp[N],m[N],n;

int main(int argc,char* argv[])
{
    #ifdef DEBUG
    READ;
    #endif
    int cnt = 0;
    while(1)
      {
	int tmp;
	std::cin>>tmp;

	if(tmp == -1)
	  break;

	n = 0;
	m[n] = tmp;
	n = n + 1;
	cnt = cnt + 1;
	while(1)
	  {
	    std::cin>>tmp;
	    if(tmp == -1)
	      break;
	    m[n] = tmp;
	    n = n + 1;
	  }

#ifdef DEBUG
	for(int i = 0 ; i < n ; i++)
	  std::cout<<m[i]<<" ";
	std::cout<<std::endl;
#endif

	memset(dp,0,sizeof(dp));

	for(int i = 0; i < n ; i++)
	  {
	    *std::upper_bound(dp+1,dp+1+n,m[i],std::greater<int>()) = m[i] ;
	  }

#ifdef DEBUG
	int tmpi = 1;
	while(dp[tmpi] != 0 )
	  {
	    std::cout<<dp[tmpi]<<" ";
	    tmpi++;
	  }
	std::cout<<std::endl;

	std::cout<<"n = "<<n<<"\n";
#endif
	
	int ret = 1;
	while(dp[ret] != 0)
	  {
	    ret++;
	  }
	std::cout<<"Test #"<<cnt<<":"<<std::endl;
	std::cout<<"  maximum possible interceptions: "<<ret-1<<std::endl;
	std::cout<<std::endl;
	
      }
    return 0;
}
