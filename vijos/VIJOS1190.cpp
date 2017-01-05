#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>


#define N (300+50)
#define M (10000+50)

using namespace std;

struct edge
{
	int from;
	int to;
	int val;
};

edge e[M];
int u,v,c;
int p[N];
int m,n;



bool cmp (edge a,edge b)
{
	return a.val<b.val;
}



int findroot(int r)
{
	if(r==p[r]) return r;
	else return p[r] = findroot(p[r]);
}



int main()
{
	
	freopen("in.txt","r",stdin);
	int pa;
	int pb;
	int max;
	int num;
	while(cin>>n>>m)
	{
		for (int i = 0; i < m; ++i)
			cin>>e[i].from>>e[i].to>>e[i].val;
		
		for(int i = 1; i <= n ; i++)
			p[i] = i;
		
		max = 0;
		num = 0;
		
		sort(e,e+m,cmp);

		for(int i = 0 ; i < m ; i++)
		{
			pa = findroot(e[i].from);
			pb = findroot(e[i].to);
			if(pa!=pb)
			{
				if(max < e[i].val) max = e[i].val;
				p[pb] = pa;
				num++;
				if(num==n-1) break;
			}
		}

		cout<<n-1<<" "<<max<<endl;
	}
	return 0;
}
