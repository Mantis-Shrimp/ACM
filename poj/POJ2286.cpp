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
#define read            freopen("preface.in", "r", stdin)
#define write           freopen("preface.out", "w", stdout)
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
const int N=2222222;



int n,m,depth; 
int s[24],path[N]; 
char op[]="ABCDEFGH"; 
int mid[8]={6,7,8,11,12,15,16,17};//中间位置  
int fan[8]={5,4,7,6,1,0,3,2};//反方向移动，回归  
int xh[8][7]=//8种操作，每次移动7位  
{ 
    0,2,6,11,15,20,22, 
    1,3,8,12,17,21,23, 
    10,9,8,7,6,5,4, 
    19,18,17,16,15,14,13, 
    23,21,17,12,8,3,1, 
    22,20,15,11,6,2,0, 
    13,14,15,16,17,18,19, 
    4,5,6,7,8,9,10 
}; 
   
int get(int a[]) 
{ 
    int i,cnt[4]={0,0,0,0}; 
    for(i=0;i<8;i++) 
        cnt[s[mid[i]]]++; 
    // return 8-max3(cnt[1],cnt[2],cnt[3]);// 8-返回中间最多的那个数 的数量  
    return 8 - Max(Max(cnt[1],cnt[2]),cnt[3]);
} 
   
void move(int k) 
{ 
    int i,t=s[xh[k][0]]; 
    for(i=1;i<7;i++) 
        s[xh[k][i-1]]=s[xh[k][i]]; 
    s[xh[k][6]]=t; 
} 
   
bool dfs(int k) 
{ 
    if(k>=depth) 
        return false; 
    int i,h; 
    for(i=0;i<8;i++) 
    { 
        move(i); 
        path[k]=i; 
        h=get(s); 
        if(h==0) 
            return true; 
        if((k+h)<depth&&dfs(k+1))//当前的步数加还需要的最少步数<depth  
        // if(k<depth&&dfs(k+1))
            return true; 
        move(fan[i]);//移回来  
    } 
    return false; 
} 
   
int main() 
{ 
    int i,j; 
    while(scanf("%d",&s[0])&&s[0]) 
    { 
        for(i=1;i<24;i++) 
            scanf("%d",&s[i]); 
        depth=get(s);//差最少的步数  
        if(depth==0) 
        { 
            printf("No moves needed\n%d\n",s[mid[0]]); 
            continue; 
        } 
        while(!dfs(0)) 
            depth++;//如果不行，最少步数+1  
        for(i=0;i<depth;i++) 
            printf("%c",op[path[i]]); 
        printf("\n%d\n",s[6]);//输出中间位置的数字  
    } 
    return 0; 
}  