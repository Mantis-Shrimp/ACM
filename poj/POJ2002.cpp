//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-4-30
// Description : hash 
//============================================================================

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>

#include <vector>

#define N 1000

using namespace std;

vector<pair<int,int> > hash[N];
pair<int,int > point[N];
int n;
int x1,y1;
int x2,y2;
int ret;

int init()
{
	for(int i = 0 ; i < N ; ++i)
		hash[i].clear();
	return 1;
}

int insert(pair<int,int> p)
{
	int idx = (p.first * p.first + p.second * p.second) % (N - 3) ;
	hash[idx].push_back(p);
	return 0;
}

int find(pair<int,int > p)
{
	int idx = (p.first * p.first + p.second * p.second) % (N - 3)  ;
	
	for(int i = 0 ; i < hash[idx].size() ;++i)
		if(hash[idx][i]==p) return 1;
	return 0;
}


int main(int argv,char* arg[])
{
	while(cin>>n&&n!=0)
	{
		init();
		ret = 0;
		for(int i = 0 ; i < n ; ++i)
		{
			cin >> point[i].first >> point[i].second;
			insert(point[i]);
		}

		for(int i = 0 ; i < n ; ++i)
		{
			for(int j = i + 1 ; j < n ; ++j)
			{

				x1 = point[i].first + (point[i].second - point[j].second);
				y1 = point[i].second - (point[i].first - point[j].first);

				x2 = point[j].first + (point[i].second - point[j].second);
				y2 = point[j].second - (point[i].first - point[j].first);
				if(find(make_pair(x1,y1))==1&&find(make_pair(x2,y2))==1)
					 ++ret;
				 x1 = point[i].first -(point[i].second - point[j].second);
				 y1 = point[i].second + (point[i].first - point[j].first);

				 x2 = point[j].first - (point[i].second - point[j].second);
				 y2 = point[j].second + (point[i].first - point[j].first);

				if(find(make_pair(x1,y1))==1&&find(make_pair(x2,y2))==1)
					++ret;
			}
		}

		cout << ret/4<<endl;
	}
}