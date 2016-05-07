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



#define N_MAX 11000


struct e
{
  int idx;
  int c;
  e(int idx,int c)
  {
    this->idx = idx;
    this->c = c;
    return;
  }
  e()
  {
    return;
  }
  bool operator < (const e& a) const
  {
    return c > a.c;
  }
};
int n,s;
int c[N_MAX],y[N_MAX];
long long r;

std::priority_queue<e> Q;

int main(int argc,char* argv[])
{
  //READ;
  std::cin>>n>>s;
  for(int i = 0 ; i < n ; i++)
    std::cin>>c[i]>>y[i];

  r = 0;
  for(int i = 0 ; i < n ; i++)
    {
      Q.push(e(i,c[i] - s * i  ));
      //std::cout << Q.top().idx <<std::endl;
      r = r + (c[Q.top().idx] + ( i -  Q.top().idx )* s)  * y[i];
    }

  std::cout<<r<<std::endl;
  
  return 0;
}
