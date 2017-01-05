#include <cstdlib>
#include <climits>
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
  
int mp[10][10]; 
int n , m , lim; 
bool den[10][10]; 
bool valid(int x,int y) 
{ 
    return x>=1 && x<=n && y>=1 && y<=m; 
} 
bool check() 
{ 
    for(int i = 1; i <= n; i++) 
    { 
        for(int j = 1; j <= m; j++) 
        { 
            if(mp[i][j] == -2)return false; 
            if(mp[i][j]>=1 && mp[i][j] <= 4) return false; 
        } 
    } 
    return true; 
} 
int dir[4][2] = {1,0,0,1,-1,0,0,-1}; 
bool canput(int x,int y) 
{ 
    for(int i = 0; i < 4; i++) 
    { 
        int tx = x + dir[i][0]; 
        int ty = y + dir[i][1]; 
        if(valid(tx,ty)) 
        { 
            if( mp[tx][ty] == 0 ) return false; 
        } 
    } 
    return true; 
} 
void go(int x,int y) 
{ 
    if(mp[x][y]==-2) 
    { 
        mp[x][y] = 5; 
        return ; 
    } 
    if(mp[x][y]>=5)    mp[x][y]++; 
} 
void gao(int x,int y) 
{ 
    for(int i = 0; i < 4; i++) 
    { 
        int tx = x + dir[i][0]; 
        int ty = y + dir[i][1]; 
        if(valid(tx,ty)) 
        { 
            if(mp[tx][ty]>=1 && mp[tx][ty]<=4)    mp[tx][ty] --; 
        } 
    } 
    for(int i=y+1;i<=m;i++) 
    { 
        go(x,i); 
        if(mp[x][i]>=-1 && mp[x][i] <= 4) break; 
    } 
    for(int i=y-1;i>=1;i--) 
    { 
        go(x,i); 
        if(mp[x][i]>=-1 && mp[x][i] <= 4) break; 
    } 
    for(int i=x-1;i>=1;i--) 
    { 
        go(i,y); 
        if(mp[i][y]>=-1 && mp[i][y] <= 4) break; 
    } 
    for(int i=x+1;x<=n;i++) 
    { 
        go(i,y); 
        if(mp[i][y]>=-1 && mp[i][y] <= 4) break; 
    } 
} 
void Go(int x,int y) 
{ 
    if(mp[x][y]==5)    mp[x][y] = -2; 
    if(mp[x][y]> 5)    mp[x][y] -- ; 
} 
void clear(int x,int y) 
{ 
    for(int i = 0; i < 4; i++) 
    { 
        int tx = x + dir[i][0]; 
        int ty = y + dir[i][1]; 
        if(valid(tx,ty)) 
        { 
            if(mp[tx][ty]>=0 && mp[tx][ty]<=3)    mp[tx][ty] ++; 
        } 
    } 
    for(int i=y+1;i<=m;i++) 
    { 
        Go(x,i); 
        if(mp[x][i]>=-1 && mp[x][i] <= 4) break; 
    } 
    for(int i=y-1;i>=1;i--) 
    { 
        Go(x,i); 
        if(mp[x][i]>=-1 && mp[x][i] <= 4) break; 
    } 
    for(int i=x-1;i>=1;i--) 
    { 
        Go(i,y); 
        if(mp[i][y]>=-1 && mp[i][y] <= 4) break; 
    } 
    for(int i=x+1;x<=n;i++) 
    { 
        Go(i,y); 
        if(mp[i][y]>=-1 && mp[i][y] <= 4) break; 
    } 
} 
int ans; 
void dfs(int dep,int x,int y)  
{ 
    if(dep>ans) return ; 
    if(x>n)  
    { 
        if(check()) 
        { 
            if(dep<ans) ans=dep;  
        } 
        return ; 
    } 
    if(x>1 && mp[x-1][y]==-2 && mp[x][y]>=-1&&mp[x][y]<=4 ) return ; 
    if(y<m) dfs(dep,x,y+1); 
    else dfs(dep,x+1,1); 
    if(mp[x][y]==-2) 
    { 
        if(canput(x,y))  
        { 
            den[x][y] = true; 
            mp[x][y] = 5; 
            gao(x,y); 
            if(y<m) dfs(dep+1,x,y+1); 
            else dfs(dep+1,x+1,1); 
            den[x][y]=false; 
            mp[x][y] = -2; 
            clear(x,y); 
        } 
    } 
} 
int main() 
{ 
    int b , r , c , k ; 
    while(scanf("%d%d",&n,&m),n||m) 
    { 
        for(int i = 1; i <= n; i++) 
        { 
            for(int j = 1; j <= m; j++) 
            { 
                mp[i][j] = - 2; 
            } 
        } 
        scanf("%d",&b); 
        for(int i = 0; i < b; i++) 
        { 
            scanf("%d%d%d",&r,&c,&k); 
            mp[r][c] = k; 
        } 
        ans = 1000; 
        dfs(0,1,1); 
        if(ans<1000)  printf("%d\n",ans); 
        else puts("No solution"); 
    } 
    return 0; 
} 