/*
ID: 15864532
LANG: C++
TASK: stamps
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
#define SZ(arr)         (int)a.size()
#define SWAP(a,b)       a=a xor b;b= a xor b;a=a xor b;
#define read            ifstream fin("stamps.in");
#define write           ofstream fout("stamps.out");
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}

const static int N = 60;
const static int K = 250;
const static int MAX = 2100000;

read;
write;

int stamps[N],k,n,dp[MAX];
int main(int argc,char* argv[])
{
  fin>>k>>n;
  for(int i = 0 ; i < n ; i++)
    fin>>stamps[i];

  sort(stamps,stamps+n);

  SET(dp,0);
  dp[0] = 1;

  for(int i = 1 ; i <= k ; i++)
    {
      for(int j = i * stamps[n-1] ; j >= 0 ; j--)
	{
	  if(dp[j]==1) continue;
	  
	  for(int l = 0 ; l < n ; l++)
	    {
	      if(stamps[l]<=j)
		if(dp[j - stamps[l]] == 1) dp[j] = 1;
	    }
	}
    }

  for(int i = 0 ; i < MAX ; i++)
    {
      if(dp[i] == 0)
	{
	  fout << i -1 << endl;
	  break;
	}
    }

  return 0;
}
