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
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}

const int MAX = 100 + 10;
int n,m,size_cur,size_pre,size_prepre;
int sta_cur[MAX],sta_pre[MAX],sta_prepre[MAX];
int size[MAX],dp[MAX][MAX][MAX],num[MAX];
char Map[MAX][MAX];



int init(int r,int pos,int sta,int count)
{
  if(pos >= m)
    {
      sta_cur[++size_cur] = sta;
      num[size_cur] = count;
      return 0;
    }
  if(Map[r][pos] == 'P')
    init(r,pos+3,sta|(1<<pos),count+1);
  init(r,pos+1,sta,count);
  return 0;
}

int getdp()
{
  for(int r = 1 ; r <= n ; r++)
    {
      memset(sta_cur,0,sizeof(sta_cur));
      size_cur = 0;
      init(r,0,0,0);
      for(int i = 1 ; i <= size_cur; i++)
	{
	  for(int j = 1; j <= size_pre;j++)
	    {
	      for(int t = 1; t <= size_prepre; t++)
		{
		  if(sta_cur[i] & sta_pre[j] ) continue;
		  if(sta_cur[i] & sta_prepre[t]) continue;
		  dp[r][i][j] = std::max(dp[r][i][j] , dp[r-1][j][t] + num[i] );
		}
	    }
	}
      for(int i = 1; i <= size_pre; i++)
	sta_prepre[i]=sta_pre[i];
      size_prepre = size_pre;

      for(int i = 1; i <= size_cur; i++)
	sta_pre[i] = sta_cur[i];
      size_pre = size_cur;

    }
  return 0;
}




int main(int argc,char* argv[])
{
    #ifdef DEBUG
    READ;
    #endif

    while(std::cin>>n>>m)
      {
	std::cin.get();
	for(int i = 1 ; i <= n ; i++)
	  std::cin.getline(Map[i],MAX);

#ifdef DEBUG
	std::cout<<n <<" " <<m<<std::endl;
	for(int i = 1; i <= n ; i++)
	  std::cout<<Map[i]<<std::endl;
#endif

	sta_pre[1] = sta_prepre[1];
	size_pre=size_prepre=1;
	getdp();


	int sum = 0;

	for(int i = 1 ; i <= size_pre ; i++)
	  {
	    for(int j = 1; j <= size_prepre; j++)
	      {
		if(dp[n][i][j] > sum)
		  sum = dp[n][i][j];
	      }
	  }

	std::cout<<sum<<std::endl;

      }
    return 0;
}
