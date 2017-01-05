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
#define read            ifstream fin("fact4.in");
#define write           ofstream fout("fact4.out");
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}


const static int N = 1500;


int T0[] = {1,1,2,6,4,2,2,4,2,8};
int T1[] = {6,6,2,6,4,4,4,8,4,6};
int c[N],a,b,len;
char n[N];
int main(int argc,char* argv[])
{

  while(cin.getline(n,N))
  {
    a = b = 0;
    len = strlen(n);
    if(len==1)
    {
      cout<<T0[n[0]-'0']<<endl;
      continue;
    }
    for(int i = 0 ; i < len ; i++)
      c[i] = n[len-i-1] - '0';

    
    a =  T1[c[0]];    
    for(int i = len - 1 , tmp = 0; i >=0 ; i--)
    {
      tmp = tmp * 10 + c[i];
      c[i] = tmp / 5;
      tmp = tmp % 5;
    }
    len = len - !c[len-1];
    


    while(len > 0)
    {
      a = (a * T1[c[0]]) % 10;
      b = (b + (c[0] + c[1] * 10) % 4 ) % 4;
      for (int i = len - 1, tmp = 0 ; i >= 0 ; i--)
      {
          tmp = tmp * 10 + c[i];
          c[i] = tmp / 5;
          tmp = tmp % 5;
      }
      len = len - !c[len-1];
    }

    for(int i = 1 ; i <= b; i++)
    {
      if((a/2)%2==1) a = ( a + 10 )/2;
      else a = a/2;
    }

    cout<< a%10 << endl;
  }
}
