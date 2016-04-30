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
#define SYNCOFF         std::ios_base::sync_with_stdio(false);
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}



std::map<string,int> flag;
struct status
{
  int pos;
  int n;
  string chess;
  status(int pos,int n,string chess)
  {
    this->pos = pos;
    this->n = n;
    this->chess = chess;
  }
};

std::vector<std::vector<int> > trans(8,std::vector<int>());

int bfs()
{
  std::queue<status> Q;
  Q.push(status(0,0,"01234567"));
  flag["01234567"] = 0;

  while(!Q.empty())
    {
      status tmp = Q.front();
      Q.pop();

      for(int i = 0 ; i < trans[tmp.pos].size(); i++)
	{
	  int pos = trans[tmp.pos][i];
	  string chess = tmp.chess;
	  SWAP(chess[pos],chess[tmp.pos]);
	  int n = tmp.n + 1;
	  if(flag.count(chess) == 0)
	    {
	      flag[chess] = n;
	      Q.push(status(pos,n,chess));
	    }
	}
      
    }
  return 0;
}

int main(int argc,char* argv[])
{
  trans[0].push_back(1);
  trans[0].push_back(4);
  
  trans[1].push_back(0);
  trans[1].push_back(2);
  trans[1].push_back(5);

  trans[2].push_back(1);
  trans[2].push_back(3);
  trans[2].push_back(6);

  trans[3].push_back(2);
  trans[3].push_back(7);

  trans[4].push_back(5);
  trans[4].push_back(0);
  
  trans[5].push_back(4);
  trans[5].push_back(6);
  trans[5].push_back(1);

  trans[6].push_back(5);
  trans[6].push_back(7);
  trans[6].push_back(2);

  trans[7].push_back(6);
  trans[7].push_back(3);

  bfs();
  int ch;
  SYNCOFF;
  while(std::cin>>ch)
    {
      string str;
      str.push_back((char) (ch + '0'));
      for(int i = 0 ; i < 7 ; i++)
	{
	  std::cin>>ch;
	  str.push_back((char)(ch + '0'));
	}
      std::cout<<str<<std::endl;
      // std::cout<<flag[str]<<std::endl;
    }
  return 0;
}
