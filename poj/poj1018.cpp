#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <map>
#include <vector>
#include <climits>
#include <iomanip>


int t,n;
int c[150];
int price[150][150],band[150][150];
int idx[10000];

int main(int argc ,char* argv[])
{
  //freopen("in.txt","r",stdin);
  std::cin>>t;
  while(t--)
    {
      std::cin >> n;
      std::map<int ,int> m;
      m.clear();
      for(int i = 0 ; i < n ; i++)
	{
	  std::cin >> c[i];
	  for(int j = 0 ; j < c[i] ; j++)
	    {
	      std::cin >> band[i][j];
	      std::cin >> price[i][j];

	      if(m.count(band[i][j]) == 0  )
		{
		  int size = m.size();
		  m[band[i][j]] = size;
		  idx[size] = band[i][j];
		}
	      else
		{
		  ;
		}
	    }
	}
      double ret = 0;
      int flag = 0;
      for(int k = 0 ; k < m.size(); k++)
	{
	  int cband = idx[k];
	  int total = 0;
	  flag = 0;
	  for(int a = 0 ; a < n ; a++)
	    {
	      int min = INT_MAX;
	      for(int b = 0 ; b < c[a]; b++)
		{
		  if(band[a][b] >= cband )
		    if( price[a][b]  < min )
		      min = price[a][b];
		  //if(min == INT_MAX)
		  //  flag = 1;
		}

	      if(min == INT_MAX)
		flag = 1;
	      if(flag == 1) break;
	      total = total + min;
	    }
	  if(flag == 1) continue;
	  if( (double)cband / total > ret)
	    ret = (double)cband / total;
	}

      std::cout<< std::setiosflags(std::ios::fixed)<<std::setprecision(3)<<ret<<std::endl;
    }
  return 0;
}
