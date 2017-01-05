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

const int maxn = 500 + 10;
const int maxp = 500;
const int c = 83;
const int N = 432;
int prime[] = {2,3,5,7,11,13,17,19,23,29,//10  
              31,37,41,43,47,53,59,61,67,//9  
              71,73,79,83,89,97,101,103,107,//9  
              109,113,127,131,137,139,149,151,//8  
              157,163,167,173,179,181,191,193,  
              197,199,211,223,227,229,233,239,  
              241,251,257,263,269,271,277,281,  
              283,293,307,311,313,317,331,337,  
              347,349,353,359,367,373,379,383,  
              389,397,401,409,419,421,431}; 

int fac[N][c];
long long ret[N][N];

int main(int argc, char const *argv[])
{
    
    int n,m,tmp;
    for(int i = 0 ; i <= N - 1 ; i++ )
    {
        for(int j = 0 ; j < c ; j++)
        {
            fac[i][j] = 0;
            tmp = i;
            while(tmp > 0)
            {
               fac[i][j] += tmp / prime[j];
               tmp /= prime[j];
            }
        }
    }
    SET(ret,0);
    while (scanf("%d%d", &n, &m)!=EOF)
    {
        if(ret[n][m] == 0)
        {
            ret[n][m] = 1;
            for (int i = 0 ; i < c ; i++)
                ret[n][m] = ret[n][m] * (fac[n][i] - fac[m][i] - fac[n - m][i] + 1);
            printf("%I64d\n",ret[n][m]);
        }
        else
        {
            printf("%I64d\n",ret[n][m]);
        }
    }
    return 0;
}