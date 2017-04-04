/*
ID: 15864532
LANG: C++
TASK: contact
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
#define read            ifstream fin("contact.in");
#define write           ofstream fout("contact.out");
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}

const int MAXN = 210000;

char str[MAXN];
int a,b,n;

read;
write;

struct node
{
  int f,n,l;
  bool operator > (const node& a) const
  {
    if(f > a.f) return true;
    if(f == a.f && l < a.l) return true;
    if(f == a.f && l == a.l && n < a.n) return true;
    return false;
  }
};

node Q[5000*15];
int cnt;

inline int toBin(int n , int l)
{
  int v = 1;
  for(int i = 1 ; i < l ; i++) v = v *2;
  for(int i = 0 ; i < l ; i++)
    {
      fout<< n/v;
      n = n % v;
      v = v /2;
    }
  return 0;
}
int main(int argc,char* argv[])
{
  fin>>a>>b>>n;
  fin.getline(str,81);
  int s = 0;
  int f[15][5000];
  while(fin.getline(str+s,81))
      s+=80;
  SET(f,0);
  int len = strlen(str);
  int tmp = 0,v = 1;
  
  for(int i = a ; i <= b ; i++)
    {
      v = 1;
      for(int k = 1 ; k < i ; k++) 
	v = v *2;
      
      tmp = 0;
      for(int j = 0 ; j < len ; j++)
	{
	  if(j<=i-2) tmp = tmp *2 + (str[j]-'0');
	  if(j==i-1)
	    {
	      tmp = tmp *2 + (str[j]-'0');
	      f[i][tmp]++;
	    }
	  if(j>=i)
	    {
	      tmp = tmp % v;
	      tmp = tmp *2 + (str[j]-'0');
	      f[i][tmp]++;
	    }
	}
    }

  cnt = 0;
  for(int i = 0 ; i < 15 ; i++)
    {
      for(int j = 0 ; j < 5000 ; j++)
	{
	  if(f[i][j]>0)
	    {
	      Q[cnt].f = f[i][j];
	      Q[cnt].n = j;
	      Q[cnt].l=i;
	      cnt++;
	    }
	}
    }
  sort(Q,Q+cnt,greater<node>() );
  tmp = 0;
  int idx = 0;
  int sta = -1;
  int w = 0;
  while(idx < cnt)
    {
      if(Q[idx].f==sta)
	{
	  if((w + 1 + Q[idx].l) <= 80)
	    {
	      fout<<" ";
	      toBin(Q[idx].n,Q[idx].l);
	      w = w + 1 + Q[idx].l;
	    }
	  else
	    {
	      fout<<endl;
	      toBin(Q[idx].n,Q[idx].l);//Q[idx].n;
	      w =  Q[idx].l;
	    }
	  idx++;
	}
      else
	{
	  tmp++;
	  if(tmp>n) break;
	  sta = Q[idx].f;
	  if(idx!=0) fout<<endl;
	  fout<<Q[idx].f<<endl;
	  toBin(Q[idx].n,Q[idx].l);//Q[idx].nQ[idx].n;
	  w = Q[idx].l;
	  idx++;
	}
    };
  fout<<endl;
  fin.close();
  fout.close();
  return 0;
}
