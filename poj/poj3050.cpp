#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <cstdio>


int flag[1000000];
int grid[5][5];
int ret = 0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};



int dfs(int y,int x,int d,int num)
{
  if(d == 6)
    {
      flag[num] = 1;
      return 1;
    }

  int tmp = num * 10 + grid[y][x];

  for(int i = 0 ; i < 4 ; i++)
    {
      int tmpx = x + dx[i];
      int tmpy = y + dy[i];

      if(tmpx < 0 || tmpx > 4) continue;
      if(tmpy < 0 || tmpy > 4) continue;

      dfs(tmpy,tmpx,d+1,tmp);
    }
 
  
  return 1;
}

int main(int argc,char* argv[])
{

  freopen("in.txt","r",stdin);
  ret = 0;
  for(int j = 0; j < 5 ; j++)
    {
      for(int i = 0 ; i < 5 ; i++)
	{
	  std::cin>>grid[j][i];
	}
    }

  memset(flag,0,sizeof(flag));

  for(int j = 0 ; j < 5 ; j++)
    {
      for(int i = 0 ; i < 5 ; i++)
	{
	  dfs(j,i,0,0);
	}
    }

  for(int i = 0 ; i <= 999999 ; i++)
    ret = ret + flag[i];

  std::cout<<ret<<std::endl;
}
