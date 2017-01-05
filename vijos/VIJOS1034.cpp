//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-3-25
// Description : 并查集
//============================================================================

#include <cstdio>
#include <iostream>
#include <cmath>

#define LEN 10000


using namespace std;

int fa[LEN];
int p,r,q;

int find_root(int a)
{
	if(fa[a]==a) return a;
	else return fa[a]=find_root(fa[a]);
}

int Uion(int a,int b)
{
	int pa = find_root(a);
	int pb = find_root(b);
	fa[pb] = pa;
	return 0;
}


int main()
{
	int a,b;
	cin >> p >> r >>q;

	for(int i = 0 ; i <= p; i++) fa[i] = i;
	
	while(r--)
	{
		cin >> a >> b;
		Uion(a,b);
	}
	
	while(q--)
	{
		cin >> a >> b;
		if(find_root(a)==find_root(b))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}