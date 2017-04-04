/*
ID: 15864532
PROG:comehome
LANG: C++
*/
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <fstream>
#include <iomanip>
#include <bitset>
#include <list>
#include <ctime>
#include <climits>
using namespace std ;
#define SET(arr, what)  memset(arr, what, sizeof(arr))
#define FF(i, s, e)     for(int i=s; i<e; i++)
#define SD(a)           scanf("%d", &a)
#define SSD(a, b)       scanf("%d%d", &a, &b)
#define SF(a)           scanf("%lf", &a)
#define SS(a)           scanf("%s", a)
#define SLD(a)          scanf("%lld", &a)
#define PF(a)           printf("%d\n", a)
#define PLF(a)          printf("%lld\n", a)
#define PPF(a, b)       printf("%d %d\n", a, b)
#define SZ(arr)         (int)a.size()
#define SWAP(a,b)       a=a xor b;b= a xor b;a=a xor b;
#define READ            freopen("comehome.in", "r", stdin)
#define WRITE           freopen("comehome.out", "w", stdout)
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}

const int MAXN = 300;

int g[MAXN][MAXN],n,tmp,idx;
char a,b;

struct Edge 
{
	char from,to;
	int dist;
};

struct HeapNode
{
	int d;
	char u;
	bool operator < (const HeapNode & rhs) const
	{
		return d > rhs.d;
	}
};

struct Dijkstra
{
	int n,m;
	std::vector<Edge> edges;
	vector<int> G[MAXN];
	bool done[MAXN];
	int d[MAXN];
	int p[MAXN];


	void init()
	{
		this->n = 250;
		for(int i = 0 ; i < n ; i++)
			G[i].clear();
		edges.clear();
	}

	void AddEdge(int from,int to,int dist)
	{
		edges.push_back((Edge){from,to,dist});
		m = edges.size();
		G[from].push_back(m-1);
	}

	void dijkstra(char s)
	{
		priority_queue<HeapNode> Q;
		for(int i = 0 ; i < n ; i++)
			d[i] = INT_MAX;
		d[s] = 0 ;
		SET(done, 0);
		Q.push((HeapNode){0,s});
		while(!Q.empty())
		{
			HeapNode x = Q.top();Q.pop();
			char u = x.u;
			if(done[u]) continue;
			done[u] = true;

			if(u>='A' && u<'Z')
			{
				printf("%c %d\n",u,x.d);
				return ;
			}

			for(int i = 0 ; i < G[u].size() ; i++)
			{
				Edge &e = edges[G[u][i]];
				if(d[e.to] > d[u] + e.dist)
				{
					d[e.to] = d[u] + e.dist;
					p[e.to] = G[u][i];
					Q.push((HeapNode){d[e.to],e.to});
				}
			}
		}
	}
};

int read()
{
	SET(g,-1);
	SD(n);
	idx = 0;
	getchar();
	for(int i = 1 ; i <= n ; i++)
	{
		scanf("%c %c %d\n",&a,&b,&tmp);
		
		// printf("* %c %c %d\n",a,b,tmp);
		if(g[a][b] == -1)
		{
			g[a][b] = tmp;
			g[b][a] = tmp;
		}
		else
			if(g[a][b] > tmp)
			{
				g[a][b] = tmp;
				g[b][a] = tmp;
			}
		
	}
	return 1;
}
int main(int argc, char const *argv[])
{
	READ;
	WRITE;
	read();
	Dijkstra dijkstra;
	dijkstra.init();
	for(int i = 0 ; i < 300 ; i ++)
	{
		for(int j = 0 ; j < 300 ; j++)
		{
			if(g[i][j]!=-1)
			{
				// printf("* %c %c %d\n",i,j,g[i][j]);
				dijkstra.AddEdge(i, j, g[i][j]);
			}
		}
	}

	dijkstra.dijkstra('Z');
	return 0;
}