//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2014-1-24
// Description : RMQ
//============================================================================

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
#define FF(i, a)        for(int i=1; i<a; i++)
#define SD(a)           scanf("%d", &a)
#define SSD(a, b)       scanf("%d%d", &a, &b)
#define SF(a)           scanf("%lf", &a)
#define SS(a)           scanf("%s", a)
#define SLD(a)          scanf("%lld", &a)
#define PF(a)           printf("%d\n", a)
#define PPF(a, b)       printf("%d %d\n", a, b)
#define SZ(arr)         (int)a.size()
#define SWAP(a,b)       a=a xor b;b= a xor b;a=a xor b;
#define read            freopen("in.txt", "r", stdin)
#define write           freopen("out.txt", "w", stdout)
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
const int maxn = 50000 + 10 ;
const int maxm = 100;

int N,Q,height[maxn],maxST[maxn][maxm],minST[maxn][maxm];


//elements are numbered from 1 to n
int RMQ_init(int A[],int n)
{
    for(int i = 1 ; i <= n ; i++)
    {
        maxST[i][0] = A[i];
        minST[i][0] = A[i];
    }
    for(int j = 1 ; (1<<j)<=n ; j++)
    {
        for (int i = 1; i+(1<<j)-1<=n; i++)
        {
        	maxST[i][j] = Max(maxST[i][j-1],maxST[i+(1<<(j-1))][j-1]);
        	minST[i][j] = Min(minST[i][j-1],minST[i+(1<<(j-1))][j-1]);
        }
    }
    return 0;
}

int RMQ_Max(int L , int R)
{
    int k = 0;
    while((1<<(k+1))<=R-L+1) k++;//if 2^(k+1) <= R-L + 1,then k++.
    return Max(maxST[L][k],maxST[R-(1<<k)+1][k]);
}


int RMQ_Min(int L , int R)
{
    int k = 0;
    while((1<<(k+1))<=R-L+1) k++;//if 2^(k+1) <= R-L + 1,then k++.
    return Min(minST[L][k],minST[R-(1<<k)+1][k]);
}


int main(int argc, char const *argv[])
{
	int l,r;
	SSD(N, Q);
	FF(i,N+1) SD(height[i]);
	RMQ_init(height,N);
	while(Q--)
	{
		SSD(l, r);
		PF(RMQ_Max(l, r)-RMQ_Min(l,r));
	}	
	return 0;
}