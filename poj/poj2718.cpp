#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <climits>
#include <queue>
#include <map>
#include <stack>
#include <algorithm>
#include <cstring>


int digits[10];
int flag[10];
int num1[10];
//int num2[10];
int t,n,ret;
char ch;

int dfs(int d,int len)
{
  if(d == len)
    {
      if(d !=1 && num1[0] == 0) return 0;

      //for(int i = 0; i < d ; i++)
      //	std::cout << num1[i] << " ";
      //std::cout<< '*' <<std::endl;

      std::vector<int> num2;

      for(int i = 0; i < n ; i++)
	  if(flag[i] == 0)
	      num2.push_back(digits[i]);


      int ret0 = INT_MAX;

      do
	{
	  if(num2.size() != 1 && num2[0] ==0 ) continue;





	  //	  for(int i = 0; i < n - d ; i++)
	  //    std::cout << num2[i] << " ";
	  //std::cout<< '_' <<std::endl;

	  int n1,n2;
	  n1 = n2 = 0;


	  for(int i = 0; i < d ; i++)
	    n1 = n1 * 10 + num1[i];
	  for(int i = 0; i < num2.size();i++)
	    n2 = n2 * 10 + num2[i];

	  if(ret0 > abs(n2-n1))
	    {
	      ret0 = abs(n2-n1);
	    }
	  else
	    {
	      break;
	    }



	}while(std::next_permutation(num2.begin(),num2.end()));

      if(ret > ret0)
	ret = ret0;
      return 0;
    }

  for(int i = 0; i < n ; i++)
    {
      if(flag[i] == 0 )
	{
	  num1[d] = digits[i];
	  flag[i] = 1;
	  dfs(d+1,len);
	  flag[i] = 0;
	}
    }
}


int main(int argc,char * argv[])
{

  //freopen("in.txt","r",stdin);
  std::ios_base::sync_with_stdio(false);
  std::cin>>t;
  std::cin.get();
  while(t--)
    {
      n = 0;
      ret = INT_MAX;
      do
	{
	  ch = std::cin.get();
	  if(ch >= '0' && ch <= '9' )
	    {
	      //digits.push_back(ch - '0');
	      digits[n] = (ch-'0');
	      n++;
	    }
	}while(ch != '\n');
      //std::cout<<t<<" "<<n<<std::endl;
      //for(int i = 0 ; i < n ; i++)
      //	std::cout << digits[i] << " ";
      //std::cout << std::endl;
      memset(flag,0,sizeof(flag));
      dfs(0,n/2);
      //while(next_permutation(digits.begin(),digits.end()));
      std::cout<<ret<<std::endl;
    }
  return 0;
}
