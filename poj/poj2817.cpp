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



int pre[11][11], dp[1<<10][11];
char word[11][15];
int n;

int pretreatment(int x,int y)
{
  pre[x][y]=pre[y][x]=0;
  int l1=strlen(word[x]);
  int l2=strlen(word[y]);
  for(int i=0; i<l1; i++)
    for(int j=0; j<l2; j++)
      {
	int k=0;
	int s=0;
	while(i+k<l1&&j+k<l2)
	  {
	    if(word[x][i+k]==word[y][j+k])
	      s++;
	    k++;
	  }
	if(s>pre[x][y])
	  pre[x][y]=pre[y][x]=s;
      }  
  return 0;
}


int getdp(int x,int y)
{

  if(dp[x][y] > 0)
    return dp[x][y];

  int ret = 0;
  int tmp = x & (~(1 << y));

  for(int i = 0 ; i < n ; i++)
    {
      if( (tmp & (1 << i )) != 0 )
	if(ret < (getdp(tmp,i) + pre[y][i]) )
	  ret = getdp(tmp,i) + pre[y][i];
    }
  return dp[x][y] = ret;
}



int main(int argc,char* argv[])
{

#ifdef DEBUG
  READ;
#endif


  
  while(std::cin>>n && n!=0)
    {
      std::cin.get();

      memset(dp,0,sizeof(dp));
      memset(pre,0,sizeof(pre));
      memset(word,0,sizeof(word));


      for(int i = 0 ; i < n ; i++)
	std::cin.getline(word[i],15);

#ifdef DEBUG
      for(int i = 0 ; i < n ; i++)
	std::cout<<word[i]<<std::endl;
#endif


      
  
      for(int i = 0 ; i < n ; i++)
	for(int j = 0 ; j < n ; j++ )
	  pretreatment(i,j);

      for(int i = 0 ; i < n ; i++)
	for(int j = 0 ; j < n ; j++)
	  {
	    if(i != j)
	      {
		int tmp =  (1 << i | 1 << j);
		dp[tmp][i] = dp[tmp][j] = pre[i][j];
	      }
	  }


      
#ifdef DEBUG
      for(int i = 0 ; i < n ; i++)
	{
	  for(int j = 0 ; j < n ; j++)
	    {
	      std::cout<<pre[i][j]<<" ";
	    }
	  std::cout<<std::endl;
	}	
#endif


      for(int i = 0 ; i < n ; i++)
	dp[(1<<n) -1 ][i] = getdp((1<<n) - 1,i);
      int ret = 0;

      for(int i = 0 ; i < n ; i++)
	if(ret < dp[(1<<n) - 1 ][i])
	  ret = dp[(1<<n) - 1][i];
	//ret = dp[(1<<n)-1][i] + ret;
      std::cout<<ret<<std::endl;
    }
    return 0;
}
