//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-4-29
// Description : 广度搜索 hash
//============================================================================

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>


#define N 1000

using namespace std;


struct e
{
	int val;
	int d;
	int c;
	int num;
};


int n,in[N+50];
vector<e> hash[N];



int insert(int val ,int d, int c)
{
	e temp;
	int idx = ((val % (N -3)) + N - 3) % (N - 3);
	int pos ;

	for(pos = 0 ; pos < hash[idx].size() ; ++pos)
		if(hash[idx][pos].val=val)
			return ++hash[idx][pos].num;

	temp.val = val ;
	temp.d = d ;
	temp.c = c ;
	temp.num = 1;
	hash[idx].push_back(temp);

	return 1;
}




int main(int arg,char* argv[])
{
	e temp;
	int idx;
LA:	while(cin>>n&&n!=0)
	{
		for(int i = 0; i < n ; ++i)
			cin>>in[i];
		
		sort(in,in+n,greater<int>());

		for(int id = 0; id < n ; ++id)
		{
			

			for(int i = 0; i < N ; ++i)
				hash[i].clear();

			for(int ic = 0 ; ic < n ; ++ic)
			{
				if(ic == id) continue;
				insert(in[id]-in[ic],in[id],in[ic]);
			}

			for(int ib = 0 ; ib < n ; ++ib)
			{
				if(ib==id) continue;
				for(int ia = 0 ; ia < n ; ++ia)
				{
					if(ia==id) continue;
					if(ia==ib) continue;

					idx = (((in[ia] + in[ib] ) %(N -3) ) + (N - 3)) % (N - 3);

					for(int i = 0 ; i < hash[idx].size();++i)
					{
						if(hash[idx][i].val == in[ia] + in[ib]&&
							hash[idx][i].c != in[ia]&&
							hash[idx][i].c != in[ib]
						   )
						{
							cout<<in[id]<<endl;
							goto LA;
						}
					}
				}
			}
		}

		cout<<"no solution"<<endl;
	}
	return 0;
}