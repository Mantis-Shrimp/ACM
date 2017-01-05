//============================================================================
// Name        : POJ_3278.cpp
// Author      : 
// Version     :
// Copyright   : 2012-7-9
// Description : Catch That Cow 广度优先
//============================================================================

#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
typedef struct
{
	int pos;
	int num;
}e;
e e0,e1;
queue<e> q;
int N,K;
char flag[100005];
int main()
{
	scanf("%d%d",&N,&K);
	memset(flag,0,sizeof(flag)),e0.pos = N,e0.num=0;
	flag[N]=1;
	q.push(e0);
	while(!q.empty())
	{
		e0=q.front();
		q.pop();
		if(e0.pos==K) {printf("%d\n",e0.num); return 0;}
		//
		if(e0.pos-1>=0&&e0.pos-1<=100000&&flag[e0.pos-1]==0)
		{
			e1=e0;
			e1.pos--;
			e1.num++;
			flag[e1.pos]=1;
			q.push(e1);
		}
		//
		if(e0.pos+1>=0&&e0.pos+1<=100000&&flag[e0.pos+1]==0)
		{
			e1=e0;
			e1.pos++;
			e1.num++;
			flag[e1.pos]=1;
			q.push(e1);
		}
		//
		if(e0.pos*2>=0&&e0.pos*2<=100000&&flag[e0.pos*2]==0)
		{
			e1=e0;
			e1.pos*=2;
			e1.num++;
			flag[e1.pos]=1;
			q.push(e1);
		}
	}

	return 0;
}
