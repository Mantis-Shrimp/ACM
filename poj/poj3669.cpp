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
#define PPF(a, b)       printf("%d %d\n", a, b)
#define SZ(arr)         (int)arr.size()
#define SWAP(a,b)       a=a xor b;b= a xor b;a=a xor b;
#define READ            freopen("in.txt", "r", stdin)
#define WRITE           freopen("fracdec.out", "w", stdout)
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}


int grid[305][305];
int flag[305][305];
int m;
int xi,yi,ti;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

struct status
{
  int x;
  int y;
  int n;
  status(int y,int x,int n)
  {
    this->x = x;
    this->y = y;
    this->n = n;
  }

  status()
  {
    this->x = 0;
    this->y = 0;
    this->n = 0;
  }
};

std::queue<status> Q;


int ispass(int y,int x,int n)
{
  if( x < 0 || y < 0 )
    {
      return false;
    }
  else
    {
      if(grid[y][x] != -1)
	if(grid[y][x] <= n )
	  return false;
    }

  for(int i = 0; i < 4; i++)
    {
      int tmpx = x + dx[i];
      int tmpy = y + dy[i];
      if(tmpx < 0 || tmpy < 0) continue;
      if(grid[tmpy][tmpx] != -1)
	if(grid[tmpy][tmpx] <= n ) return false;
    }

  return true;
}


int issafe(int y,int x)
{

  if( x < 0 || y < 0 )
    {
      return false;
    }
  else
    {
      if(grid[y][x] !=-1 )
	return false;
    }

  for(int i = 0; i < 4; i++)
    {
      int tmpx = x + dx[i];
      int tmpy = y + dy[i];
      if(tmpx < 0 || tmpy < 0) continue;
      if(grid[tmpy][tmpx] != -1 ) return false;
    }

  return true;
}


int bfs()
{
  if(issafe(0,0)) return 0;
  status tmp(0,0,0);
  Q.push(tmp);
  flag[0][0] = 0;
  while(!Q.empty())
    {
      tmp = Q.front();
      Q.pop();

      for(int i = 0 ; i < 4 ; i++)
	{
	  int tmpx = tmp.x + dx[i];
	  int tmpy = tmp.y + dy[i];
	  int n = tmp.n + 1;

	  if(tmpx < 0 || tmpy < 0) continue;

	  if(flag[tmpy][tmpx] != -1)
	    if(flag[tmpy][tmpx] <= n) continue;

	  if(issafe(tmpy,tmpx) == true) return n;
	  if(ispass(tmpy,tmpx,n) == false) continue;

	  flag[tmpy][tmpx] = n;
	  Q.push(status(tmpy,tmpx,n));
	  
	}
      
    }
  return -1;
}


int main(int argc,char* argv[])
{
  READ;
  std::ios_base::sync_with_stdio(false);
  while(std::cin >> m)
    {
      memset(grid,-1,sizeof(grid));
      memset(flag,-1,sizeof(flag));
      for(int i = 0 ; i < m ;i++)
	{
	  std::cin>>xi>>yi>>ti;
	  if(grid[yi][xi] == -1 )
	    {
	      grid[yi][xi] = ti;
	    }
	  else
	    {
	      AMin(grid[yi][xi],ti);
	    }
	}

      // for(int j = 0 ; j < 10 ; j++)
      //   {
      //     for(int i = 0 ; i < 10 ; i++)
      // 	{
      // 	  std::cout<<grid[j][i]<<" ";
      // 	}
      //     std::cout<<std::endl;
      //   }

      std::cout<<bfs()<<std::endl;
    }
  return 0;
}
