//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-3-27
// Description : 贪心
//============================================================================

#include <cstdio>
#include <cmath>
#include <iostream>
#include <queue>

using namespace std;


int n;
int temp;
priority_queue<int,vector<int>,greater<int> > q;
int main()
{
	int a,b,c;
	c = 0;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>temp;
		q.push(temp);
	}
	while(q.size()>=2)
	{
		a = q.top();
		q.pop();
		b = q.top();
		q.pop();
		q.push(a+b);
		c += (a + b);
	}
	cout<<c<<endl;
}