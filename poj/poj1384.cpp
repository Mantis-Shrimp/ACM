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
#include <climits>
using namespace std ;
#define SET(arr, what)  memset(arr, what, sizeof(arr))
#define FF(i, s, e)     for(int i=s; i<e; i++)
#define SZ(arr)         (int)a.size()
#define SWAP(a,b)       a=a xor b;b= a xor b;a=a xor b;
#define read            ifstream fin("fact4.in");
#define write           ofstream fout("fact4.out");
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}

const static int N = 10000;

int T,E,F,M,n,p,w,dp[N];
int main(int argc, char const *argv[])
{
    cin>>T;
    for(int t = 1 ; t <= T ; t++)
    {
        cin>>E>>F;
        cin>>n;
        SET(dp,-1);
        dp[0] = 0;

        for(int i = 1 ; i <= n ; i++)
        {
            cin>>p>>w;

            for(int j = 0 ; j <= F - E ; j++)
            {
                if(dp[j] != -1)
                    if( (j + w) <= F - E )
                    {
                        if( dp[j + w] == -1 || dp[j] + p < dp[j + w] )
                            dp[j + w] = dp[j] + p;
                    }
            }
        }

        if(dp[F-E] == -1)
            cout<<"This is impossible."<<endl;
        else
            cout<<"The minimum amount of money in the piggy-bank is "<<dp[F-E]<<"."<<endl;
    }
}