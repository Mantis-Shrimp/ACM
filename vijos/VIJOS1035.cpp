//============================================================================
// Name        : VIJOS1035. cpp
// Author      :
// Version     :
// Copyright   : 2013-3-24
// Description : 模拟
//============================================================================

#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
#include <cstdio>

#define LEN 100

using namespace std;


struct stu
{
	int in;
	int out;
	int p;
};

int np;
string name[LEN];
map<string,stu> ma;

int main(int argc, char const *argv[])
{
//	freopen("in.txt","r",stdin);
	stu s;
	string a,b;
	int ngi,p;
	
	s.in = 0;
	s.out = 0;
	s.p = 0;

	cin >> np;
	for (int i = 0; i < np; ++i)
	{
		cin >> name[i];
		ma[name[i]] = s;
	}
	
	cin>>a;
	while(cin>>p>>ngi)
	{	
		ma[a].p += p;
		if(ngi!=0)
			ma[a].out += p / ngi * ngi;

		for (int j = 0; j < ngi; ++j)
		{
			cin >> b;
			ma[b].in += p / ngi ;
		}
		cin >> a;
	}

	for (int i = 0; i < np; ++i)
		cout<< name[i] << ' ' <<ma[name[i]].in - ma[name[i]].out<< endl;

	return 0;
}