/*
ID: 15864532
PROG: milk2
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
#define read            freopen("milk2.in", "r", stdin)
#define write           freopen("milk2.out", "w", stdout)
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
const int maxn = 20000 + 10 ;
const int N = 5010;



struct TagSeg
{
    int s;
    int e;
    bool operator < (const TagSeg& a) const
    {
        return s < a.s;
    }
};

TagSeg Seg[N];
int n,nt;
int ret0,ret1;

int main(void)
{
    read;
    write;
    SD(n);
    FF(i, 0, n)
        SSD(Seg[i].s,Seg[i].e);
    sort(Seg,Seg+n);
    nt = 0 ;
    FF(i , 1 , n)
    {
        if(Seg[i].s <= Seg[nt].e)
        {
            if(Seg[nt].e < Seg[i].e)
                Seg[nt].e = Seg[i].e;
        }
        else
        {
            nt++;
            Seg[nt].s = Seg[i].s;
            Seg[nt].e = Seg[i].e;
        }
    }
    ret0 = 0;
    ret1 = Seg[0].e - Seg[0].s;
    FF(i , 1 , nt+1)
    {
        if(Seg[i].s - Seg[i-1].e > ret0)
            ret0 = Seg[i].s - Seg[i-1].e;
        if(Seg[i].e - Seg[i].s > ret1)
            ret1 = Seg[i].e - Seg[i].s;
    }

    // FF(i, 0, nt)
    //     printf("%d %d\n",Seg[i].s, Seg[i].e);

    PPF(ret1, ret0);
    return 0;
}