//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-4-27
// Description : 双向广度搜索 数字hash
//============================================================================

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>


#define N 1000

using namespace std;

int a,b,c,d;
int ret;
struct e
{
	int val;
	int num;
};

vector<e> hash[N];


int insert(int val)
{
	
	e e0;
	int idx = (val % (N - 3) + (N - 3))% ( N - 3);
	for(int i = 0 ; i < hash[idx].size();++i)
		if(hash[idx][i].val==val)
			return (++hash[idx][i].num);
	e0.val = val;
	e0.num = 1;
	hash[idx].push_back(e0);
	return 1;
}

int find(int val)
{
	int idx = (val % (N - 3) + (N - 3))% ( N - 3);
	for(int i = 0 ; i < hash[idx].size();++i)
	{
		if(hash[idx][i].val==val)
			return hash[idx][i].num;
	}
	return 0;;
}


int main(int arg,char*argv[])
{
	while(cin>>a>>b>>c>>d)
	{
		ret = 0;
		
		if(a<0&&b<0&&c<0&&d<0
		 ||a>0&&b>0&&c>0&&d>0)
		{
			cout<<"0"<<endl;
			continue;
		}

		for(int i = 0 ; i < N ; ++i) hash[i].clear();

		for(int x1 = 1 ; x1 <= 100 ; ++x1)
			for(int x2 = 1 ; x2 <= 100 ; ++x2)
				insert(a*x1*x1+b*x2*x2);

		for(int x3 = 1 ; x3 <= 100 ; ++x3)
			for(int x4 = 1 ; x4 <= 100 ; ++x4)
				ret+=find(-c*x3*x3-d*x4*x4);
		cout<<ret*16<<endl;
	}
	return 0;
}
