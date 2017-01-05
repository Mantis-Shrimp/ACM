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
#define read            freopen("preface.in", "r", stdin)
#define write           freopen("preface.out", "w", stdout)
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}



struct Chess
{
	int x[4];
	int y[4];
	int step,which;
	unsigned long long map;
	unsigned long long getMap()
	{
		map = 0;
		for(int i = 0 ; i < 4 ; i++)
		{
			map += (unsigned long long) 1 <<((x[i]-1)*8+(y[i]-1)); 
		}
	};

	bool operator < (const Chess &a) const
	{
		return map < a.map;
	};
};


map<Chess,int> m;
queue<Chess> Q;
Chess start,end;
int dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};


bool getChild(Chess top,Chess& tmp,int ith,int d)
{
	tmp.x[ith] = top.x[ith] + dir[d][0];
	tmp.y[ith] = top.y[ith] + dir[d][1];

	if(tmp.x[ith] < 1 || tmp.x[ith] > 8 || tmp.y[ith] < 1 || tmp.y[ith] > 8)
		return false;
	for(int i = 1 ; i < 4 ; i++)
	{
		if(tmp.x[ith]==top.x[(ith + i) % 4] && tmp.y[ith]==top.y[(ith + i) % 4])
		{
			tmp.x[ith] +=dir[d][0];
			tmp.y[ith] +=dir[d][1];

			if(tmp.x[ith] < 1 || tmp.x[ith] > 8 || tmp.y[ith] < 1 || tmp.y[ith] > 8)
				return false;

			for(int i = 1 ; i < 4 ; i++)
			if(tmp.x[ith]==top.x[(ith + i) % 4] && tmp.y[ith]==top.y[(ith + i) % 4])
				return false;

			return true;
		}
	}
	return true;
}

bool BFS()
{
	Chess top,tmp;
	int d,v;
	m.clear();
	while(!Q.empty()) Q.pop();

	start.step = end.step = 0;
	start.which  = 1;
	end.which = 2;
	start.getMap(); end.getMap();
	m[start] = 1; m[end] = 2;
	Q.push(start);Q.push(end);

	while(!Q.empty())
	{
		top = Q.front();Q.pop();
		v = m[top];
		for(int i = 0 ; i < 4 ; i++)
		{
			for(int d = 0 ;d < 4 ; d++)
			{
				if(getChild(top,tmp,i,d))
				{
					for(int k = 1 ; k < 4 ; k++)
						tmp.x[(i+k)%4] = top.x[(i+k)%4],
						tmp.y[(i+k)%4] = top.y[(i+k)%4];

					tmp.step = top.step + 1;
					if(tmp.step > 4) continue;
					tmp.which = top.which;
					tmp.getMap();
					v=m[tmp];
					if(v==tmp.which) continue;
					if(v!=0&&v!=tmp.which) return true;
					m[tmp]=tmp.which;
					Q.push(tmp);

				}
			}
		}
	}
	return false;
}


int main(int argc, char const *argv[])
{
    while(1)
    {  
        for(int i=0;i<4;i++)
            if(scanf("%d%d",&start.x[i],&start.y[i])==EOF)  
                return 0;  
        for(int i=0;i<4;i++)  
            scanf("%d%d",&end.x[i],&end.y[i]);  
       printf(BFS()?"YES\n":"NO\n");
    }  
	return 0;
}