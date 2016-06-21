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




int main(int argc,char* argv[])
{
    int T;
    std::cin>>T;
    while(T--)
    {
      long long a,b,c,n,m,k;
      std::cin>>a>>b>>c>>n>>m>>k;
      long long sa,sb,sc;
      sa=(2*b*c)*(2*b*c)-(b*b+c*c-a*a)*(b*b+c*c-a*a);
      sb=(2*a*c)*(2*a*c)-(a*a+c*c-b*b)*(a*a+c*c-b*b);
      sc=(2*a*b)*(2*a*b)-(a*a+b*b-c*c)*(a*a+b*b-c*c);
      long long la=sqrt(sa),lb=sqrt(sb),lc=sqrt(sc);
      if(la*la==sa&&lb*lb==sb&&lc*lc==sc)
        std::cout<<"YES\n";
      else
        std::cout<<"NO\n";
    }
      return 0;
}
