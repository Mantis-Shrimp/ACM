#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <climits>
#include <queue>
#include <map>
#include <algorithm>
#include <cstring>


#define MAX 110000

struct cow
{
  int s;
  int m;
  bool operator > (const cow &a) const
  {
    return s > a.s;
  }
};


struct cmp
{
  bool operator ()  (const cow &a,const cow &b) const
  {
    return a.m < b.m;
  }
};


cow cows[MAX];
int sum1[MAX],sub1[MAX];
int sum2[MAX],sub2[MAX];
int n,c,f;


std::priority_queue<cow,std::vector<cow>,cmp> Q;

int main(int argc,char* argv[])
{

  //freopen("in.txt","r",stdin);
  std::ios::sync_with_stdio(false);
  while(std::cin>>n>>c>>f)
    {
      while(!Q.empty())
	Q.pop();
      for(int i = 0 ; i < c ; i++)
	std::cin >> cows[i].s >> cows[i].m;
      std::sort(cows,cows+c,std::greater<cow>() );

  //    for(int i = 0 ; i < c ; i++)
	// {
	//  std::cout<<cows[i].s << " "  <<cows[i].m << std::endl;
	// }

      memset(sum1,0,sizeof(sum1));
      memset(sub1,0,sizeof(sub1));
      sum1[0] = cows[0].m;
      for(int i = 1 ; i < c ; i++)
	{
	  sum1[i] = sum1[i-1] + cows[i].m;
	}

      int idx = n / 2;

      for(int i = 0 ; i <= idx ; i++)
	{
	  Q.push(cows[i]);
	}

      for(int i = idx + 1 ; i <= ((c - 1) - (n  / 2)) ; i++)
	{
	  sub1[i] = Q.top().m + sub1[i-1] ;
	  Q.pop();
	  Q.push(cows[i]);
	}

      while(!Q.empty())
	Q.pop();
      memset(sum2,0,sizeof(sum2));
      memset(sub2,0,sizeof(sub2));
      sum2[c-1] = cows[c-1].m;
      for(int i = c - 2 ; i >= 0 ; i--)
	{
	  sum2[i] = sum2[i+1] + cows[i].m;
	}

      idx = n / 2;

      for(int i = (c-1) ;  i >= (c-1) -idx   ;i--)
	{
	  Q.push(cows[i]);
	}

      for(int i = (c-1) -idx -1 ; i  >= idx; i-- )
	{
	  sub2[i] = sub2[i+1] + Q.top().m;
	  Q.pop();
	  Q.push(cows[i]);
	}

      int flag = 0;

  //      for(int i = 0 ; i < c ; i++)
	// {
	//   std::cout<<sum1[i]<<" ";
	// }
  //     std::cout<<std::endl;
  //
  //     for(int i = 0 ; i < c ; i++)
	// {
	//   std::cout<<sub1[i]<<" ";
	// }
  //     std::cout<<std::endl;
  //
  //     for(int i = 0 ; i < c ; i++)
	// {
	//   std::cout<<sum2[i]<<" ";
	// }
  //     std::cout<<std::endl;
  //
  //     for(int i = 0 ; i < c ; i++)
	// {
	//   std::cout<<sub2[i]<<" ";
	// }
  //     std::cout<<std::endl;

      for(int i = idx ; i <= (c-1) -idx ; i++)
	{
	  if( (sum1[i-1] - sub1[i]   )  +  cows[i].m +  (sum2[i+1] - sub2[i]   ) <= f    )
	    {
	      flag = 1;
	      std::cout<<cows[i].s<<std::endl;
        break;
	    }
	}
      if(flag == 0)
	std::cout<<"-1"<<std::endl;

    }
  return 0;
}
