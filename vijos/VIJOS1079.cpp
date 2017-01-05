//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-3-28
// Description : 数据结构
//============================================================================

#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#define LEN 1000


using namespace std;


priority_queue<int,vector<int>, greater<int> > q;
char str[LEN];
int map[LEN];
int alen;
int solusion;


int main(int argc, char const *argv[])
{
	int a,b;
	while(scanf("%s",str)!=EOF&&!(str[0]=='E'&&str[1]=='N'&&str[2]=='D'))
	{
		alen = strlen(str);
		solusion = 0;
		memset(map,0,sizeof(map));
		for(int i = 0 ; i < alen ; i++)
			map[str[i]]++;
		for(int i = 0 ; i < 128 ; i++)
			if(map[i]>0) q.push(map[i]);
		if (q.size()==1)
		{
			q.pop();
			printf("%d %d %.1f\n",alen*8,alen,(double)alen*8/alen);
			continue;
		}
		while(q.size()>=2)
		{
			a = q.top();
			q.pop();
			b = q.top();
			q.pop();
			solusion+=(a+b);
			q.push(a+b);
		}
		q.pop();
		printf("%d %d %.1f\n",alen*8,solusion,(double)alen*8/solusion);
	}
	return 0;
}