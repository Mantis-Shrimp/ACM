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


int t,n,p,q;
int ha[90000],a[90000],b[90000];
int l[90000],dp[90000];

int main(int argc,char* argv[])
{
#ifndef ONLINE_JUDGE
    READ;
#endif

    std::cin>>t;

    for(int it = 1 ; it <= t ; it++)
	{
	    std::cin>>n>>p>>q;
	    p = p + 1;
	    q = q + 1;

	    for(int i = 0 ; i < p ; i++)
		std::cin>>a[i];
	    for(int i = 0 ; i < q ; i++)
		std::cin>>b[i];
	    memset(ha,-1,sizeof(ha));
	    int idx = 0;
	    for(int i = 0 ; i < p ; i++)
		ha[a[i]] = i;


	    for(int i = 0 ; i < q ; i++)
		{
		    if(ha[b[i]] != -1 )
			{
			    l[idx] = ha[b[i]];
			    idx = idx + 1;
			}
		}

	    for(int i = 0 ; i <= idx ; i++)
		dp[i] = INT_MAX;

	    for(int i = 0 ; i < idx ; i++)
		{
		    *lower_bound(dp+1,dp+idx,l[i]) = l[i];
		}

	    int ret = 0;

	    for(int i = 1 ; i <= idx ; i++)
		{
		    if(dp[i] == INT_MAX)
			{
			    ret = i - 1;
			    break;
			}
		}

	    std::cout<<"Case "<<it<<": "<<ret<<std::endl;
	}
    
    return 0;
}
