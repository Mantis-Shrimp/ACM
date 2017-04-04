/*
ID: 15864532
LANG: C++
TASK: rect1
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
#define read            freopen("rect1.in", "r", stdin)
#define write           freopen("rect1.out", "w", stdout)
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}


struct Square{
	int ll, lr, ul, ur;
	int color;
	int area;
	Square()
	{
	}
	Square(int ll, int lr, int ul, int ur, int color)
	{
		this->ll = ll;
		this->lr = lr;
		this->ul = ul;
		this->ur = ur;
		this->color = color;
		this->area = (ul - ll) * (ur - lr);
	}
};


void addSquare(list<Square> &squares, const Square& square)
{
	if(square.area != 0)
	{
		squares.push_front(square);
	}
}

int main()
{
	int a, b, n;
	write;
	read;
	scanf("%d%d%d", &a, &b, &n);
	list<Square> squares;
	list<Square>::iterator it = squares.begin();
	squares.push_back(Square(0, 0, a, b, 1));
	
	for(int i = 0; i < n; ++i)
	{
		int ll, lr, ul, ur, color;
		scanf("%d%d%d%d%d", &ll, &lr, &ul, &ur, &color);
		Square square(ll, lr, ul, ur, color);
		

		it = squares.begin();
		while(it != squares.end())
		{
			int maxll, maxlr, minul, minur;
			maxll = max(ll, (*it).ll);
			maxlr = max(lr, (*it).lr);
			minul = min(ul, (*it).ul);
			minur = min(ur, (*it).ur);
			if(maxll >= minul || maxlr >= minur)
			{
				it++;
			}
			else
			{
				addSquare(squares, Square((*it).ll, (*it).lr, maxll, 
					(*it).ur, (*it).color));
				addSquare(squares, Square(maxll, minur, minul, 
					(*it).ur, (*it).color));
				addSquare(squares, Square(minul, (*it).lr, (*it).ul, 
					(*it).ur, (*it).color));
				addSquare(squares, Square(maxll, (*it).lr, minul, 
					maxlr, (*it).color));

				it = squares.erase(it);
			}
		}
		addSquare(squares, square);
	}

	map<int, int> cntColors;
	
	for(it = squares.begin();it != squares.end();it++)
	{
		if(cntColors.find((*it).color) == cntColors.end())
			cntColors[(*it).color] = (*it).area;
		else
			cntColors[(*it).color] += (*it).area;
	}


	for(map<int, int>::iterator iter = cntColors.begin(); iter != cntColors.end(); ++iter)
	{
		printf("%d %d\n", iter->first, iter->second);
	}
	return 0;
}
