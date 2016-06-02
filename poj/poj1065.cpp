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
 
int B[5005];  
struct node  
{   int len,wg;  
};  
int comp(node A,node B)  
{   if(A.wg!=B.wg) return A.wg<B.wg;  
    if(A.wg==B.wg&&A.len!=B.len) return A.len<B.len;  
}  
int main()  
{   int i,n,k,j;  
    cin>>k;  
    node a[5005];  
    while(k--)  
    {  cin>>n;  
       int num=0;  
       for(i=0;i<n;i++)  
          cin>>a[i].len>>a[i].wg;  
       sort(a,a+n,comp);  
       for(i=0;i<n;i++)  
       {  int flag=0;  
          for(j=0;j<num;j++)  
            if(a[i].len>=B[j])  
            {  flag=1;  
               B[j]=a[i].len;  
               break;  
            }  
          if(!flag) B[num++]=a[i].len;  
       }  
       cout<<num<<endl;  
    }   
    return 0;  
}  