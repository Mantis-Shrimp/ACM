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
//#define ONLINE_JUDGE

int t,m;

struct doll
{
    int w;
    int h;
    bool operator < (const doll b) const
	{
	    if(w < b.w)
		return true;
	    else
		{
		    if(w == b.w && h >b.h)
			    return true;
		    return false;
		}
	}
};

struct doll dolls[21000];
int dp[21000];

int main(int argc,char* argv[])
{
    SYNCOFF;
#ifndef ONLINE_JUDGE
    READ;
#endif

    //std::cin >> t;
    scanf("%d",&t);
    while(t--)
    {	scanf("%d",&m);
	//std::cin >> m;
	for(int i = 0 ; i < m ; i++)
	    scanf("%d %d",&dolls[i].w,&dolls[i].h);
	//std::cin>>dolls[i].w>>dolls[i].h;
	std::sort(dolls,dolls+m,std::less<doll>());

#ifndef ONLINE_JUDGE
	for(int i = 0 ; i < m ; i++)
	    std::cout<<"(" << dolls[i].w << "," <<dolls[i].h << ")" << " ";
	std::cout<<std::endl;
#endif


	//for(int i = 0 ; i < m ; i++)
	//    dp[i] = 0;

	memset(dp,0,sizeof(dp));
	//dp[0] = 1;
	int ret = 1;

	for(int i = 0 ; i < m ; i++)
	{
	    for(int j = 1; j <= ret ; j++ )
	    {
		if( dp[j] < dolls[i].h )
		{
		    dp[j] = dolls[i].h;
		    break;
		}
	    }
	    if(dp[ret] !=0 ) ret ++;

	    
//int max = 0;
	    //for(int j = i - 1; j >=0 ; j--)
	    //{
	    //	if(dolls[i].h <= dolls[j].h )
	    //	{
	    //	    if(max < dp[j])
	    //		max = dp[j];
	    //	}
	    //}
	    //dp[i] = max + 1; 

#ifndef ONLINE_JUDGE
	    for(int i = 0 ; i < m; i++)
		std::cout<<dp[i]<<" ";
	    std::cout<<std::endl;
#endif
	}


	//int ret = 0;
	//for(int i = 0 ; i < m ; i++)
	//{
	//    if(ret < dp[i])
	//	ret = dp[i];
	//}
	printf("%d\n",ret-1);
	//std::cout<<ret - 1 <<std::endl;
    }
    return 0;
}
