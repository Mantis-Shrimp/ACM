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
#define SZ(arr)         (int)a.size()
#define SWAP(a,b)       a=a xor b;b= a xor b;a=a xor b;
#define read            ifstream fin("fact4.in");
#define write           ofstream fout("fact4.out");
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}



int g(int m,int n)
{
	int a = 0;
	if((m % 10) >= n ) a = 1;

	if(m <= 0) return 0;
	return m / 10 + a + g(m / 5 , n);
}

int f(int m,int n)
{
	if(m <= 0) return 0;
	return g(m,n) + f(m / 2 , n);
}

int h(int m,int n)
{
	if(m <= 0) return 0;
	return m / n + h(m/n,n);
}


int n2,n3,n5,n7,n9;
int main(int argc, char const *argv[])
{
	int m , n;
    while (cin >> m >> n)
    {

    	int ret = 1;
        n2 = h(m, 2) - h(m - n, 2);
        n3 = f(m,3) - f(m-n,3);
        n5 = h(m, 5) - h(m - n, 5);
        n7 = f(m,7) - f(m-n,7);
        n9 = f(m,9) - f(m-n,9);

        n2 = n2 - n5;
        
        for(int i = 1 ; i <= n3 % 4 ; i++)
        	ret = ((ret % 10) * 3) %10;

        for(int i = 1 ; i <= n7 % 4 ; i++)
        	ret = ((ret % 10) * 7) %10;

        for(int i = 1 ; i <= n9 % 4 ; i++)
        	ret = ((ret % 10) * 9) %10;

        if(n2 >= 1)
        {
        	ret = (ret * 2) % 10;
        	n2 --;
        }

        for(int i = 1 ; i <= n2 % 4 ; i++)
        	ret = ((ret % 10) * 2) %10;

        cout << ret << endl;

    }
}