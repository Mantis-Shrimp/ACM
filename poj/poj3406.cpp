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

const int maxn = 1000000 + 10;
const int maxp = 700000;
int vis[maxn];//1表示合数，0表示1或者素数。
int prime[maxp];

int factorn[maxp],factorm[maxp],factormn[maxp],factor[maxp];

//筛素数

void sieve(int n)
{
    int m = (int)sqrt(n+0.5);//避免浮点误差
    memset(vis,0,sizeof(vis));
    for(int i = 2 ; i <= m ; i++)
        if(!vis[i])
            for(int j = i*i ; j <= n ; j+=i)
                vis[j] = 1;
}

//生成素数表，放在prime数组中，返回素数个数
 int gen_primes(int n)
 {
    int c = 0;
    sieve(n);
    for(int i = 2 ; i <= n ; i++)
        if(!vis[i])
            prime[c++] = i;
    return c;
 }


int main(int argc, char const *argv[])
{
    int n,m,c,tmp,ret,n2,n5;
    
    scanf("%d%d",&n,&m);
    c = gen_primes(n);
    
    memset(factorn, 0, sizeof(factorn));
    memset(factorm, 0, sizeof(factorm));
    memset(factormn, 0, sizeof(factormn));
    for(int i = 0 ; i < c ; i++)
    {
        tmp = n;
        while((tmp/=prime[i])>0)
            factorn[i] += tmp;
    }

    for(int i = 0 ; i < c ; i++)
    {
        tmp = m;
        while((tmp/=prime[i])>0)
            factorm[i] += tmp;
    }

    for(int i = 0 ; i < c ; i++)
    {
        tmp = n-m;
        while((tmp/=prime[i])>0)
            factormn[i] += tmp;
    }

    ret = 1;

    for(int i = 0 ; i < c ; i++)
        factor[i] = factorn[i]-factorm[i]-factormn[i];
    // printf("%d\n",ret);
    
    // factor[0] = factor[0] - factor[2];
    
    while(factor[0] && factor[2])
    {
        factor[0] --;
        factor[2] --;
    }

    for(int i = c - 1 ; i >= 0 ; i--)
        for(int j = 1 ; j <= factor[i] ; j++)
            ret = (ret * (prime[i] % 10)) % 10;

    printf("%d\n",ret);
    return 0;
}