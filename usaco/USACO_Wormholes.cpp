/*
ID: 15864532
LANG: C++
TASK: wormhole
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
#define read            ifstream fin("wormhole.in");
#define write           ofstream fout("wormhole.out");
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}

vector<pair<int,int> > wormholes(100);
vector<int> pairs(100);
vector<bool> unused(100,1);
vector<int> next(100,-1);

int n,ret=0;

read;
write;

int checkpair()
{
  int flag = 1;
  int m = 0;
  for(int i = 0 ; i < n ; i++)
    {
      	m = i;
	do
	{
	  m = pairs[m];
	  m = next[m];
	}while(m!=-1&&m!=i);
      if(m==i) return 0;
    }
  return 1;
}

int makepair(int d)
{
  if(d==(n/2+1))
  {
    //    for(int i = 0 ; i < n ; i++)
    //      fout<<'('<<i<<pairs[i]<<')';
    //    fout<<endl;
    
    if(checkpair()==0) ret++;
    
    return 0;
  }  
  
  for(int j = 0 ; j < n ; j++)
  {
    if(unused[j]==0) continue;
    
    for(int k = j+1 ; k < n ; k++)
      {
	if(unused[k]==0) continue;

	pairs[j]=k;
	pairs[k]=j;

	unused[j]=unused[k]=0;
	makepair(d+1);
	unused[j]=unused[k]=1;
      }
    
    break;
  }
    return 0;
}

int makenext()
{
  for(int i = 0 ; i < n ; i++)
    {
      int m = -1;
      for(int j = 0 ; j < n ; j++)
	{
	  if(i==j) continue;
	  
	  if(wormholes[i].second==wormholes[j].second && wormholes[i].first < wormholes[j].first )
	    {
	      if(m==-1) m = j;
	      else
		{
		  if(wormholes[m].first > wormholes[j].first) m = j;
		}
	    }
	}
      next[i] = m;
    }

  for(int i = 0 ; i < n ; i++)
    //    fout << next[i] << " ";
    //  fout <<endl;

  return 0;
}

int main(int argc,char* argv[])
{

  fin>>n;
  for(int i = 0 ; i < n ; i++)
    {
      int x,y;
      fin>>x>>y;
      wormholes[i]=make_pair(x,y);
    }

  makenext();
  makepair(1);
  fout<<ret<<endl;
  fin.close();
  fout.close();
  return 0;
}

