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


int z,m,h,ai,bi;


long long powermod(long long n,long long p,long long mod)
{
    long long tmp = n % mod;
    long long ret = 1;
    while(p!=0)
    {
	//tmp = (tmp * n) % mod;
	if(p&1==1)
	    ret = (ret * tmp) % mod;
	p = p >> 1;
	tmp = (tmp * tmp) % mod;
    }
    return ret;
}


int main(int argc,char* argv[])
{
#ifndef ONLINE_JUDGE
    READ;
#endif
    std::cin>>z;
    while(z--)
    {
	int ret = 0;
	std::cin>>m;
	std::cin>>h;
	for(int i = 0 ; i < h ;i++)
	    {
		std::cin>>ai>>bi;
		ret = (ret + powermod(ai,bi,m)) % m;
	    }
	std::cout<<ret<<std::endl;
    }
}
