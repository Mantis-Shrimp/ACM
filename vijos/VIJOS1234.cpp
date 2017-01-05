#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>


#define N (1000+50)
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
int m,n,k;



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
	int sum;
	int num;
	while(cin>>n>>m>>k)
	{
		for (int i = 0; i < m; ++i)
			cin>>e[i].from>>e[i].to>>e[i].val;
		
		for(int i = 1; i <= n ; i++)
			p[i] = i;
		
		sum = 0;
		num = n;
		
		sort(e,e+m,cmp);

		for(int i = 0 ; i < m ; i++)
		{
			pa = findroot(e[i].from);
			pb = findroot(e[i].to);
			if(pa!=pb)
			{
				sum += e[i].val;
				p[pb] = pa;
				num--;
				if(num==k) break;
			}
		}

		if(num==k) cout<<sum<<endl;
		else cout<<"No Answer\n";
	}
	return 0;
}
