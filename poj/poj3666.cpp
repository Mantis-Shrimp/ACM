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
#define SZ(arr)         (int)arr.size()
#define SWAP(a,b)       a=a xor b;b= a xor b;a=a xor b;
#define READ            freopen("in.txt", "r", stdin)
#define WRITE           freopen("fracdec.out", "w", stdout)
#define SYNCOFF         std::ios_base::sync_with_stdio(false);
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}

const int MAXN = 2005;

int n, cur, a[MAXN], b[MAXN];
long long f[2][MAXN];

int myabs(int x)
{
    return x < 0 ? -x : x;
}

long long solve(int st, int ed, int delta)
{
    long long best;
    memset(f, 0, sizeof(f));
    cur = 0;
    for (int i = st; i != ed; i += delta)
    {
        best = 0x7fffffff;
        for (int j = 0; j < n; ++j)
        {
            best = min(best, f[cur ^ 1][j]);
            f[cur][j] = best + myabs(b[j] - a[i]);
        }
        cur ^= 1;
    }
    cur ^= 1;
    best = 0x7fffffff;
    for (int i = 0; i < n; ++i) best = min(best, f[cur][i]);
    return best;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b, b + n);
    cout << min(solve(0, n, 1), solve(n - 1, -1, -1)) << endl;
    return 0;
}
