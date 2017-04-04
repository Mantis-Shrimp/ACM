/*
ID: 15864532
PROG:maze1
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
#define read            freopen("maze1.in", "r", stdin)
#define write           freopen("maze1.out", "w", stdout)
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}

const int N = 300;

char maze[N][N];
int dis[3][N][N],W,H,x[3],y[3],idx;

int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};
struct node
{
	int x,y;
	int dis;
};

int BFS(int id)
{
	queue<node> Q;
	node top,tmp;

	top.x = x[id];
	top.y = y[id];
	top.dis = 1;
	dis[id][top.y][top.x] = top.dis;
	Q.push(top);

	while(!Q.empty())
	{
		top = Q.front();
		Q.pop();

		for(int i = 0 ; i <= 3 ; i++)
		{
			tmp = top;

			tmp.x = tmp.x + dx[i];
			tmp.y = tmp.y + dy[i];
			tmp.dis ++;

			if(dis[id][tmp.y][tmp.x]== INT_MAX && maze[ top.y * 2 + dy[i]  ][top.x * 2 + dx[i] ] ==' ' )
			{
				Q.push(tmp);
				dis[id][tmp.y][tmp.x] = tmp.dis;
			}

		}
	}

	// for(int j = 1 ; j <= H ; j++)
	// {
	// 	for(int i = 1 ; i <= W ; i++)
	// 	{
	// 		printf("%d ",dis[id][j][i]);
	// 	}
	// printf("\n");
	// }

}

int main(int argc, char const *argv[])
{
	write;
	read;
	SSD(W, H);
	idx = 0;
	gets(maze[0]);
	for(int i = 1 ; i <= H*2+1 ;i++)
		gets(&maze[i][1]);
	// 
	// for(int i = 1 ; i <= H *2 + 1 ;i++)
	// 	puts(&maze[i][1]);


	for(int i = 1 ; i <= H *2 + 1 ; i++)
	{
		
		if(maze[i][1]==' ')
		{
			idx++;
			x[idx]=1,y[idx]=i/2;
		}
		if(maze[i][2*W+1]==' ')
		{
			idx++;
			x[idx]=W,y[idx]=i/2;
		}
	}

	for(int i = 1 ; i <= W * 2 + 1 ; i++)
	{
		if(maze[1][i]==' ')
		{
			idx++;
			x[idx]=i/2,y[idx]=1;
		}
		if(maze[2*H+1][i]==' ')
		{
			idx++;
			x[idx]=i/2,y[idx]=H;
		}
	}

	// printf("x1=%d,y1=%d\n",x[1],y[1]);
	// printf("x2=%d,y2=%d\n",x[2],y[2]);
	// printf("idx = %d\n",idx);

	// memset(dis, -1, sizeof(dis));
	
	for(int k = 1 ; k <= 2 ; k++)
		for(int j = 1 ; j <= H ; j++)
			for(int i = 1 ; i <= W ; i++)
				dis[k][j][i] = INT_MAX;

	BFS(1);
	BFS(2);

	int ret = -1;

	for(int j = 1 ; j <= H ; j++)
	{
		for(int i = 1 ; i <= W ; i++)
		{
			if(ret < Min(dis[1][j][i],dis[2][j][i]))
				ret = Min(dis[1][j][i],dis[2][j][i]);
		}
	}

	printf("%d\n",ret);

	// system("pause");
	return 0;
}