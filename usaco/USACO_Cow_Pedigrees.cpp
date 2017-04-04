/*
ID:15864532
LANG:C++
TASK:nocows
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
#define read            freopen("nocows.in", "r", stdin)
#define write           freopen("nocows.out", "w", stdout)
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
int main()
{
    int n,k,dp[200][200];
    write;
    read;  
    SSD(n, k);
    memset(dp,0,sizeof(dp));
    dp[1][1]=1;
    for (int i=3;i<=n;i+=2)
        for (int j=1;j<=i-2;j+=2)
            for (int k1=1;k1<=(j+1)/2;k1++)
                for (int k2=1;k2<=(i-j)/2;k2++)
                {
                    dp[i][max(k1,k2)+1]+=dp[j][k1]*dp[i-j-1][k2];
                    dp[i][max(k1,k2)+1]%=9901;
                }
    PF(dp[n][k]);
}
    