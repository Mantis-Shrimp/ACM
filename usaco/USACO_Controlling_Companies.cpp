/*
ID: 15864532
PROG:concom
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
#include <queue>
#include <stack>
#include <fstream>
#include <iomanip>
#include <bitset>
#include <list>
#include <ctime>
using namespace std;
#define SET(arr, what)  memset(arr, what, sizeof(arr))
#define FF(i, s, e)     for(int i=s; i<e; i++)
#define SD(a)           scanf("%d", &a)
#define SSD(a, b)       scanf("%d%d", &a, &b)
#define SF(a)           scanf("%lf", &a)
#define SS(a)           scanf("%s", a)
#define SLD(a)          scanf("%lld", &a)
#define PF(a)           printf("%d\n", a)
#define PPF(a, b)       printf("%d %d\n", a, b)
#define SZ(arr)         (int)a.size()
#define SWAP(a,b)       a=a xor b;b= a xor b;a=a xor b;
#define read            freopen("concom.in", "r", stdin)
#define write           freopen("concom.out", "w", stdout)
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}

const int N = 200;

struct Edge
{
	int from,to,w;
};


vector<int> G[N];
vector<int> Ret[N];
vector<Edge> edges;
int vis[N],sum[N];
int t,n,fr,to,w,C,S;


int DFS(int p)
{
	for(int i = 0 ; i < G[p].size() ; i++)
	{
		int a,b,c,cnt;
		cnt = G[p][i];
		b = edges[cnt].to;
		c = edges[cnt].w;
		sum[b] = sum[b] + c;
		if(sum[b] > 50 && vis[b] == 0)
		{
			vis[b] = 1;
			DFS(b);
			Ret[S].push_back(b);
		}	
	}

	return 0;
}

int main(int argc, char const *argv[])
{
	read;
	write;
	int m;SD(t),C=0;
	for(int i = 1 ; i <= t ; i++)
	{
		SD(fr);SD(to);SD(w);
		edges.push_back((Edge){fr,to,w});
		m = edges.size();
		G[fr].push_back(m-1);
		AMax(n, fr);
		AMax(n, to);
	}

	for(int i = 1 ; i <= n ;i++)
	{
		SET(vis, 0);
		SET(sum, 0);
		S = i;
		vis[i]=1;
		DFS(i);
	}


	for(int i = 1 ; i <= n ;i++)
	{
		sort(Ret[i].begin(),Ret[i].end());
		for(int j = 0 ; j < Ret[i].size() ; j++)
			printf("%d %d\n",i,Ret[i][j]);
	}

	// system("pause");
	return 0;
}