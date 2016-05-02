#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <climits>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

#define MAX 2510

struct cow
{
  int min;
  int max;
  bool operator < (const struct cow a) const
  {
    return min < a.min;
  }
};


struct cmp
{
  bool operator  ()(const cow &a, const cow &b)
  {
    return a.max >  b.max;
  }
};

struct bottle
{
  int spf;
  int n;
  bool operator < (const struct bottle a) const
  {
    return this->spf < a.spf;
  }
};


int c,l;
struct cow cows[MAX];
struct bottle bottles[MAX];

std::priority_queue<cow,std::vector<cow>,cmp > Q;

int main(int argc,char* argv[])
{
  //  freopen("in.txt","r",stdin);

  while(std::cin>>c>>l)
    {
      for(int i = 0 ; i < c; i++)
	{
	  std::cin>>cows[i].min>>cows[i].max;
	}
      for(int i = 0 ; i < l; i++)
	{
	  std::cin>>bottles[i].spf>>bottles[i].n;
	}

      std::sort(cows,cows+c);
      std::sort(bottles,bottles+l);


      //    for(int i = 0 ;  i < c ; i++)
      //	{
      //	  std::cout << cows[i].min <<" " <<cows[i].max<<std::endl;
      //	}

      // for(int i = 0; i < l ; i++)
      //	{
      //	  std::cout <<bottles[i].spf << " " <<bottles[i].n <<std::endl;
      //	}



      int i = 0;
      int j = 0;
      int ret = 0;
      while(i < l)
	{
	  int spf = bottles[i].spf;

	  while( j < c   && cows[j].min <= spf )
	    {
	      Q.push(cows[j]);
	      j++;
	    }


	  if(Q.empty())
	    {
	      i++;
	    }
	  else
	    {

	      while( ! Q.empty() && Q.top().max < spf)
		{
		  //		  std::cout<<Q.top().min << "  *  " <<Q.top().max<<" "<<spf <<std::endl;
		  Q.pop();
		}

	      if(Q.empty())
		{
		  i++;
		}
	      else
		{
		  ret = ret + 1;
		  Q.pop();
		  bottles[i].n--;
		  if(bottles[i].n == 0)
		    i++;
		}
	    }
	}
      std::cout<<ret<<std::endl;
    }
  return 0;
}
