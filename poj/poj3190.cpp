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
#define MAX             51000
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}


struct tim
{
  int t;
  int flag;
  int n;
  int idx;
  bool operator < (const tim& tmp) const
  {
    if(t < tmp.t)
      return true;
    else
      if(t == tmp.t)
	return flag < tmp.flag;
    return false;
  }
};

tim t[MAX + MAX ];
int s[MAX];
int flag[MAX], ret[MAX];
int n;
std::priority_queue<int> Q;
int main()
{
  //READ;
  SYNCOFF;
  std::cin >> n;
  for(int i = 0 ; i < n ; i++)
    {
      std::cin >> t[i*2].t;
      t[i*2].flag = 0;
      t[i*2].n = i;


      std::cin >> t[i*2 + 1].t;
      t[i*2+1].flag = 1;
      t[i*2+1].n = i;
    }

  std::sort(t,t+2*n,less<tim>());
  memset(flag,0,sizeof(flag));
  memset(ret,0,sizeof(ret));


  int idx = 0;
  for(int i = 0 ; i < 2 * n ; i++)
    {
      if( t[i].flag == 0 )
	{
	  //while(flag[idx] != 0 )
	  //  idx ++;
	  if(Q.empty())
	    {
	      t[i].idx = idx;
	      s[t[i].n] = idx;
	      flag[idx] = 1;
	      idx = idx + 1;
	    }
	  else
	    {
	      int tmp = Q.top();
	      Q.pop();
	      t[i].idx = tmp;
	      s[t[i].n] = tmp;
	      flag[idx] = 1;
	    }
	}
      else
	{
	  Q.push(s[t[i].n]);
	  flag[s[t[i].n]] = 0;
	}
    }


  for(int i = 0 ; i < 2 * n ; i++)
    {
      if(t[i].flag == 0)
	{
	  ret[t[i].n] = t[i].idx;
	}
    }


  std::cout<<idx<<std::endl;
  for(int i = 0 ; i < n ; i++)
    std::cout << ret[i] + 1  << std::endl;

}
