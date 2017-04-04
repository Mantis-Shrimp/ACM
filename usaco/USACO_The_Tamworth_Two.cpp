/*
ID: 15864532
PROG:ttwo
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
#define read            freopen("ttwo.in", "r", stdin)
#define write           freopen("ttwo.out", "w", stdout)
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}

const short direction[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
char map[12][12];
bool used[11][11][4][11][11][4] = {false};
int c;
class T
{
public:
	int x,
		y,
		dire;//up:0 right:1 down:2 left:3
	T() 
	{
		dire = 0;
	}
	void go()
	{
		if(map[direction[dire][0] + x][direction[dire][1] + y] == '*')
			dire = (dire+1)%4;
		else x += direction[dire][0],
			 y += direction[dire][1];
	}
 
};
 
ifstream fin("ttwo.in");
ofstream fout("ttwo.out");
T F,C;
 
void input()
{
	string in;
	for(int i=0; i<=11; i++)
		map[0][i] = '*',
		map[11][i] = '*';
	for(int i=1; i<=10; i++)
	{
		fin >> in;
		map[i][0] = '*';
		map[i][11] = '*';
		for(int j=1; j<=10; j++)
		{
			if(in[j-1] != 'C' && in[j-1] != 'F')
				map[i][j] = in[j-1];
			else 
			{
				map[i][j] = '.';
				if(in[j-1] == 'F')
					F.x = i,
					F.y = j;
				else C.x = i,
					 C.y = j;
			}
 
		}
	}
}
 
int main()
{
	input();
	c = 0;
	while(true)
	{
		if(used[F.x][F.y][F.dire][C.x][C.y][C.dire])
		{
			fout << 0 << endl;
			return 0;
		}
		used[F.x][F.y][F.dire][C.x][C.y][C.dire] = true;
		if(F.x == C.x && F.y == C.y)
		{
			fout << c << endl;
			return 0;
		}
		F.go();
		C.go();
		c++;
	}
    return 0;
}