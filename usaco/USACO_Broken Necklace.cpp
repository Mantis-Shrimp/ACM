/*
ID: 15864532
PROG: beads
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
#define getint(i) scanf("%d\n", &n)
#define SET(arr, what)  memset(arr, what, sizeof(arr))
#define FF(i, s, e)        for(int i=s; i<e; i++)
#define SD(a)           scanf("%d", &a)
#define SSD(a, b)       scanf("%d%d", &a, &b)
#define SF(a)           scanf("%lf", &a)
#define SS(a)           scanf("%s", a)
#define SLD(a)          scanf("%lld", &a)
#define PF(a)           printf("%d\n", a)
#define PPF(a, b)       printf("%d %d\n", a, b)
#define SZ(arr)         (int)a.size()
#define SWAP(a,b)       a=a xor b;b= a xor b;a=a xor b;
#define read            freopen("beads.in", "r", stdin)
#define write           freopen("beads.out", "w", stdout)
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


int n;
char f[701];

int main(void)
{
    int i, limit;
    int a = 0, b = 0, w = 0;
    char c = '0';
    int m = 0;
    read;
    write;
    getint(n);
    limit = 2 * n;
    fgets(f, 351, stdin);
    memcpy(f + n, f, n);
    for(i = 0; i < limit; i++){
        if(f[i] == 'w'){
            b++;
            w++;
        }else if(f[i] == c){
            b++;
            w = 0;
        }else{
            if(b + a > m){
                m = b + a;
            }
            a = b - w;
            b = w + 1;
            w = 0;
            c = f[i];
        }
    }
    if(a + b > m){
        m = b + a;
    }
    printf("%d\n", m > n ? n : m);
    return 0;
}