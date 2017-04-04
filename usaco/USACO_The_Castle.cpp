/*
ID: 15864532
PROG: castle
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
using namespace std ;
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
#define read            freopen("castle.in", "r", stdin)
#define write           freopen("castle.out", "w", stdout)
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}

const int N = 100;
int W[N][N][4],C[N][N],w,h;
int cnt,wei[N*N];
queue<int> Q;
int ret = 0,f=0,s=0,X,Y;

int bloodfill(int x,int y,int cnt)
{
	int c = 1;
	while(!Q.empty()) Q.pop();
	Q.push(x*1000+y);
	C[y][x] = cnt;
	while(!Q.empty())
	{
		x = Q.front() / 1000;
		y = Q.front() % 1000;
		Q.pop();
		//S
		if(y+1<h && W[y+1][x][2]==0 && C[y+1][x] == 0)
		{
			Q.push(x*1000+(y+1));
			C[y+1][x] = cnt;
			c++;
		}
		//N
		if(y-1>=0 && W[y-1][x][0]==0 && C[y-1][x] == 0)
		{
			Q.push(x*1000+(y-1));
			C[y-1][x] = cnt;
			c++;
		}
		// E
		if(x+1 < w && W[y][x+1][3]==0 && C[y][x+1] == 0)
		{
			Q.push((x+1)*1000+y);
			C[y][x+1] = cnt;
			c++;
		}
		// W
		if(x-1>=0 && W[y][x-1][1]==0 && C[y][x-1] == 0)
		{
			Q.push((x-1)*1000+y);
			C[y][x-1] = cnt;
			c++;
		}
	}

	return c;
}

int main(int argc, char const *argv[])
{
	write;
	read;
	int tmp;
	SET(C,0);
	SET(W,0);
	scanf("%d%d",&w,&h);
	for(int i = 0 ; i < h ; i++)
		for(int j = 0 ; j < w ; j++)
			{
				SD(tmp);
				if(tmp>=8)
				{
					W[i][j][0] = 1;
					tmp = tmp - 8;
				}
				if(tmp>=4)
				{
					W[i][j][1] = 1;
					tmp = tmp - 4;
				}
				if(tmp>=2)
				{
					W[i][j][2] = 1;
					tmp = tmp - 2;
				}
				if(tmp>=1)
				{
					W[i][j][3] = 1;
					tmp = tmp - 1;
				}
			}

	for(int j = 0 ; j < h ; j++)
	{
		for(int i = 0 ; i < w ; i++)
		{
			if(C[j][i]==0)
			{
				cnt ++;
				wei[cnt] = bloodfill(i,j,cnt);
				if(wei[cnt] > s) s = wei[cnt];
			}
		}
	}

	for(int i = 0 ; i < w ; i++)
	{
	for(int j = h - 1 ; j >=0  ; j--)
		
		{
			if(W[j][i][2]==1 && j-1>=0 &&C[j][i]!=C[j-1][i])
			{
				if(wei[C[j][i]]+wei[C[j-1][i]] > ret)
				{
					ret = wei[C[j][i]]+wei[C[j-1][i]];
					f = 1;
					X = i;
					Y = j;
				}
			}
			
			if(W[j][i][1]==1 && i+1< w &&C[j][i]!=C[j][i+1])
			{
				if(wei[C[j][i]]+wei[C[j][i+1]] > ret)
				{
					ret = wei[C[j][i]]+wei[C[j][i+1]];
					f = 2;
					X = i;
					Y = j;
				}
			}
		}
	}

	PF(cnt);
	PF(s);
	PF(ret);
	printf("%d %d ",Y+1,X+1);
	if(f==1) printf("N\n");
	else printf("E\n");
	// system("pause");
	return 0;
}