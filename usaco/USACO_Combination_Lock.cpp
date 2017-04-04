/*
ID: 15864532
LANG: C++
TASK: combo
*/
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
#include <map>
#include <queue>
#include <stack>
#include <fstream>
#include <iomanip>
#include <bitset>
#include <list>
#include <ctime>
#include <climits>
using namespace std ;
#define SET(arr, what)  memset(arr, what, sizeof(arr))
#define FF(i, s, e)     for(int i=s; i<e; i++)
#define SD(a)           scanf("%d", &a)
#define SSD(a, b)       scanf("%d%d", &a, &b)
#define SF(a)           scanf("%lf", &a)
#define SS(a)           scanf("%s", a)
#define SLD(a)          scanf("%lld", &a)
#define PF(a)           printf("%d\n", a)
#define PLF(a)          printf("%lld\n", a)
#define PPF(a, b)       printf("%d %d\n", a, b)
#define SZ(arr)         (int)a.size()
#define SWAP(a,b)       a=a xor b;b= a xor b;a=a xor b;
#define read            freopen("combo.in", "r", stdin)
#define write           freopen("combo.out", "w", stdout)
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}


struct lock
{
  int a,b,c;
  bool operator< (const lock& t) const
  {
    if(a<t.a) return true;
    
    if(a==t.a && b<t.b) return true;

    if(a==t.a && b==t.b && c<t.c) return true;

    return false;

  }
  //bool operator!= (const lock& t) const
  //{
  //  if(a!=t.a||b!=t.b||c!=t.c)
  //    return true;
  //  else
  //    return false;
  //}
};


set<lock> s;

//set<int> s;
int main(int argc,char* argv[])
{
  read;
  write;
  int n,a[3],b[3];
  lock l;
  scanf("%d",&n);
  for(int i = 0 ; i < 3 ; i++)
    scanf("%d",&a[i]);
  for(int i = 0 ; i < 3 ; i++)
    scanf("%d",&b[i]);
  
  for(int i = -2 ; i <= 2 ; i++ )
    for(int j = -2 ; j <= 2 ; j++)
      for(int k = -2 ; k <= 2 ; k++)
	{
	  l.a = (a[0]+n+i)%n,
	  l.b = (a[1]+n+j)%n,
	  l.c = (a[2]+n+k)%n;
	  s.insert(l);

	  l.a = (b[0]+n+i)%n;
	  l.b = (b[1]+n+j)%n;
	  l.c = (b[2]+n+k)%n;
	  s.insert(l);
	}

  printf("%d\n",(int)s.size());
  return 0;
}

