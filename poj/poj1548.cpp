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


struct point
{
    int x;
    int y;
    point(int x = 0,int y = 0)
	{
	    this->x = x;
	    this->y = y;
	}
    bool operator < (struct point a) const
	{
	    if(x < a.x)
		{
		    return true;
		}
	    else
		{
		    if(x == a.x)
			return y < a.y;
		    return false;
		}
	}
};


struct point p[1000];
int idx,dp[1000];
//int x,y;
int main(int argc,char* argv[])
{
#ifndef ONLINE_JUDGE
    READ;
#endif
    while(1)
	{
	    int x,y;
	    idx = 0;
	    while(std::cin>>x>>y)
		{
		    if(x==0 && y==0 ) break;
		    if(x==-1 && y==-1) return 0;
		    p[idx].x = x;
		    p[idx].y = y;
		    idx = idx + 1;
		}
	    sort(p,p+idx,less<point>());

#ifndef ONLINE_JUDGE
	    for(int i = 0 ; i < idx ; i++)
		std::cout<<"("<<p[i].x<<","<<p[i].y<<")";
	    std::cout<<endl;
#endif
	    memset(dp,0,sizeof(dp));
	    int ret = 1;
	    for(int i = 0 ; i < idx ; i++)
		{
		    for(int j = 1 ; j <= ret ; j++)
			{
			    if(p[i].y >= dp[j])
				{
				    dp[j] = p[i].y;
				    break;
				}
			}

		    
		    if(dp[ret] != 0 ) ret = ret + 1;
#ifndef ONLINE_JUDGE
		    for(int i = 0 ; i < ret ; i++)
			std::cout<<dp[i]<<" ";
		    std::cout<<std::endl;
#endif
		}
	    std::cout<<ret - 1 <<std::endl;
	}
    return 0;
}
