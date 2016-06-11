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
#define maxn 90
int dp_min[maxn];
int dp_max[maxn];

int smaller(char *s1,char *e1,char *s2,char *e2)
{
    while(*s1=='0'&&s1!=e1)++s1;
    while(*s2=='0'&&s2!=e2)++s2;
    int len1=e1-s1;
    int len2=e2-s2;
    if(len1!=len2)
        return len1-len2;
    while(s1!=e1)
    {
        if(*s1!=*s2)
            return *s1-*s2;
        ++s1;
        ++s2;
    }
    return 1;
}

int main()
{
    char str[maxn];
    while(scanf("%s",str+1)&&strcmp(str+1,"0"))
    {
        int n=strlen(str+1);
        for(int i=1;i<=n;i++)
            dp_min[i]=dp_max[i]=1;//注意这个初始化，开始时每个数结尾的范围都是1-dp[i];
        for(int i=2;i<=n;i++)
        {
            for(int j=i-1;j>=1;j--)
            {
                if(smaller(str+dp_min[j],str+j+1,str+j+1,str+i+1)<0)
                {
                    dp_min[i]=j+1;
                    break;
                }
            }
        }

        int m=dp_min[n];
        dp_max[m]=n;
        int i,j;
        for(i=m-1;i>=1&&str[i]=='0';i--)
            dp_max[i]=n;
        for(;i>=1;i--)
        {
            for(j=m-1;j>=i;j--)
            {
                if(smaller(str+i,str+j+1,str+j+1,str+dp_max[j+1]+1)<0)
                {
                    dp_max[i]=j;
                    break;
                }
            }
        }

        int f=0;
        for(i=1,j=dp_max[i];i<=n;j=dp_max[j+1])
        {
            if(!f) f=1;
            else printf(",");
            while(i<=j&&i<=n)
                printf("%c",str[i++]);
        }
        puts("");
    }
	return 0;
}

