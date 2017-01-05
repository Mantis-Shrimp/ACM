//============================================================================
// Name        : VIJOS1024. cpp
// Author      :
// Version     :
// Copyright   : 2013-3-24
// Description : 模拟
//============================================================================

#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

#define LEN 1000

using namespace std;

vector<long long> v;

long long inv(long long a)
{
  long long temp = a;
  long long b,c;
  int dig[LEN];
  int n=0;

  while(temp!=0)
  {
    dig[n++] = temp % 10;
    temp = temp / 10;
  }
  sort(dig,dig+n,greater<long long>() );

  b = c = 0;
  
  for (int i = 0; i < n; ++i)
  {
    b = b * 10;
    c = c * 10;
    b = b + dig[i];
    c = c + dig[n-1-i];
  }

  return b-c;
}

int main()
{
  long long a,c;
  int flag;
  while (cin>>a)
  {
    v.clear();
    v.push_back(a);
    c = inv(a);
    v.push_back(c);

    while (1)
    {
      c = inv(c);
      flag = -1;
      for (int i = 0 ; i < v.size() ; i++)
      {
        if (v[i]==c)
        {
          flag = i;
          break;
        }
      }

      if(flag!=-1)
      {
        for (int i = flag ; i < v.size(); i++)
          cout<<v[i]<<' ';
        cout<<endl;
        break;
      }

      v.push_back(c);
    }
  }
}