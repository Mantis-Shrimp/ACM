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


char str[1000];
int dp[1000][1000];

int getMax(int s,int e)
{
    if(e - s <= 0 )
	return 0;

    if(e - s == 1)
    {
	if( (str[s] =='(' && str[e] == ')') || (str[s]=='[' && str[e] == ']'))
	    return dp[s][e] = 2;
	else
	    return dp[s][e] = 0;
    }

    if(dp[s][e] != -1 )
	return dp[s][e];
    int ret = 0;

#ifndef ONLINE_JUDGE
//    std::cout<<s<<" "<<e<<std::endl;
#endif
    
    for(int i = s; i < e ; i++)
    {
	int tmp = getMax(s,i)+getMax(i+1,e);


#ifndef ONLINE_JUDGE
	//std::cout<<"("<<s<<","<<i<<")" <<"(" << i+1 <<","<<e<<")"<<std::endl;
#endif


	if(tmp > ret)
	    ret = tmp;
    }

    if((str[s] =='('&&str[e]==')' ) ||  (str[s] =='['&&str[e]==']' ) )
    {
	int tmp = getMax(s+1,e-1) + 2;
	if(tmp > ret)
	    ret = tmp;
    }

    dp[s][e] = ret;
    
    return dp[s][e];
}

int main(int argc,char* argv[])
{
    SYNCOFF;
#ifndef ONLINE_JUDGE
    READ;
#endif

    while(std::cin.getline(str,1000))
    {
#ifndef ONLINE_JUDGE
	std::cout<<str<<std::endl;
#endif
	if(str[0] == 'e' ) break;

	memset(dp,-1,sizeof(dp));

	int len = strlen(str);

	std::cout<<getMax(0,len-1)<<std::endl;
    }
    
    return 0;
}
