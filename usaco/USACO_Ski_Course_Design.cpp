/*
ID: 15864532
LANG: C++
TASK: skidesign
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
#define read            ifstream fin("skidesign.in");
#define write           ofstream fout("skidesign.out");
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}

read;
write;

int n;
vector<int> hills(1500);
int ret = INT_MAX;

int main(int argc,char* argv[])
{
  fin>>n;
  for(int i = 0 ; i < n ; i++)
    fin>>hills[i];

  for(int i = 0 ; i < 110 ; i++)
    {
      int tmp = 0;
      
      for(int j = 0 ; j < n ; j++)
	{
	  if(hills[j] < i)
	    tmp = tmp +  (i-hills[j]) * (i-hills[j]);
	  
	  if(hills[j] > i+17)
	    tmp = tmp + (hills[j] - i - 17 ) * (hills[j] - i - 17) ;
	  
	}

      if(tmp < ret) ret = tmp;
    }

  fout<<ret<<endl;
  fin.close();
  fout.close();
  return 0;
}
