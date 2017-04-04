/*
ID: 15864532
LANG: C++
TASK: kimbits
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
#define read            ifstream fin("kimbits.in");
#define write           ofstream fout("kimbits.out");
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
long long n,l,I;
long long c[35][35],A[35][35];
int ret[35]; 
int main(int argc,char* argv[])
{
  SET(c,0);
  c[1][0] = c[1][1] = 1;

  fin >> n >> l >> I;

  for(int i = 2 ; i <= 32 ; i ++)
    for(int j = 0 ; j <= i ; j++)
      c[i][j] = c[i-1][j-1] + c[i-1][j];

  for(int i = 0 ; i <= 32 ; i ++)
    for(int j = 1 ; j <= 32 ; j++)
      c[i][j] = c[i][j-1] + c[i][j];
  
  // for(int i = 0 ; i <= 6 ; i ++)
  // {
  //   for(int j = 0 ; j <= 6 ; j++)
  //   {
  //     cout<<c[i][j]<<" ";
  //   }
  // cout<<endl;
  // }


  int count = 0,remainder = l;

  for(int i = n ; i >= 1 ; i--)
  {
    if(i == 1)
    {
      if(count == I - 1) ret[i] = 0;
      else ret[i] = 1;
    }
    else
    {
      if(c[i-1][remainder] + count < I)
      {
        count = count + c[i-1][remainder];
        remainder --;
        ret[i] = 1;
      }
      else
      {
        ret[i] = 0;
      }
    }
  }

  for(int i = n ; i >= 1 ; i--)
  {
    fout<<ret[i];
  }
  fout<<endl;

}
