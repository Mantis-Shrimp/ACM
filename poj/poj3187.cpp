#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <climits>
#include <queue>
#include <map>
#include <cstring>


int flag[11];
int ret[11];
int tmp[11];
int n,sum;



int dfs(int d)
{

  if(d == n+1)
    {
      for(int i = 1 ; i <= n; i++)
	tmp[i] = ret[i];
      for(int j = 1 ; j <= n - 1 ; j++)
	{
	  for(int i = n ; i >= j + 1 ; i--)
	    {
	      tmp[i] = tmp[i] + tmp[i-1];
	    }
	}

      if(tmp[n] == sum )
	{
	  for(int i = 1 ; i <= n ; i++)
	    std::cout<<ret[i] <<" ";
	  std::cout<<std::endl;
	  return 1;
	}
    }

  for(int i = 1 ; i <= n ;i++)
    {
      if(flag[i]==0)
	{
	  ret[d] = i;
	  flag[i] = 1;
	  if(dfs(d+1)==1) return 1;
	  flag[i] = 0;
	}
    }
  return 0;
}

int main(int argc,char* argv[])
{
  std::cin>>n>>sum;
  memset(flag,0,sizeof(flag));
  dfs(1);
}

