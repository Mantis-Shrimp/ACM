/*
ID:15864532
LANG:C++
TASK:zerosum
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
#define PLF(a)          printf("%lld\n", a)
#define PPF(a, b)       printf("%d %d\n", a, b)
#define SZ(arr)         (int)a.size()
#define SWAP(a,b)       a=a xor b;b= a xor b;a=a xor b;
#define read            freopen("money.in", "r", stdin)
#define write           freopen("money.out", "w", stdout)
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
 
ifstream fin("zerosum.in");
ofstream fout("zerosum.out");
int n,m;
void dfs(int step,int sum,int num,string s){
  string s1=s;
  if(step==n){if(sum+num==0)fout<<s<<endl;return;}
  if(num>0)dfs(step+1,sum,num*10+step+1,s+" "+char(step+1+48));
  else dfs(step+1,sum,num*10-step-1,s+" "+char(step+1+48));
  dfs(step+1,sum+num,step+1,s+"+"+char(step+1+48));
  dfs(step+1,sum+num,-1*step-1,s+"-"+char(step+1+48));
}
void solve(){
  fin>>n;
  dfs(1,0,1,"1");
}
int main(){
  solve();
  return(0);
}