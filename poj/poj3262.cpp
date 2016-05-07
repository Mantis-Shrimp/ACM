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
#include <climits>
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

#define N_MAX 110000

int n;
struct e
{
  int t;
  int d;
  bool operator < (const e& a) const
  {
    return t * a.d < a.t * d ;
  }
};
struct e cows[N_MAX];

int main(int argc,char* argv[])
{
  //READ;
SYNCOFF;
  std::cin>>n;
  int total_time = 0;
  for(int i = 0 ; i < n ; i++)
    {
      //std::cin>>t[i]>>d[i];
      //total_time = total_time + t[i];
      std::cin >> cows[i].t >> cows[i].d;
    }
  
  std::sort(cows,cows+n);

  long long r = 0;
  long long t = 0;

  for(int i = 0 ; i < n ; i++)
    {
      r = r + cows[i].d * t * 2;
      t = t + cows[i].t;
      //std::cout<<r<<" "<<t<<std::endl;
    }
  
  std::cout<<r<<std::endl;
  return 0;
}
