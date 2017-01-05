#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>


#define N (100+50)
#define M (5000+50)

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
	
//	freopen("in.txt","r",stdin);
	int pa;
	int pb;
	int sum;
	int num;
	int flag = 0;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		for (int i = 0; i < n*(n-1)/2; ++i)
		{
			scanf("%d%d%d%d",&e[i].from,&e[i].to,&e[i].val,&flag);
			
			if(flag==1) e[i].val = 0; 
		}
		
		for(int i = 1; i <= n ; i++)
			p[i] = i;
		
		sum = 0;
		num = 0;
		
		sort(e,e+n*(n-1)/2,cmp);

		for(int i = 0 ; i < n*(n-1)/2 ; i++)
		{
			pa = findroot(e[i].from);
			pb = findroot(e[i].to);
			if(pa!=pb)
			{
				sum += e[i].val;
				p[pb] = pa;
				num++;
				if(num==n-1) break;
			}
		}

		//cout<<sum<<endl;
		printf("%d\n",sum);
	}
	return 0;
}
