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



int T0[] = {1,1,2,6,4,2,2,4,2,8};
int T1[] = {6,6,2,6,4,4,4,8,4,6};
int n,a,b,tmp;

int main(int argc,char* argv[])
{


    while (cin >> n)
    {
        tmp = n;
        a = b = 0;
        if (n < 10)
        {
            cout << setw(5) << n <<" -> " << T0[n % 10] << endl;
            continue;
        }

        a =  T1[n % 10];
        n = n / 5;

        while (n > 0)
        {
            a = (a * T1[n % 10]) % 10;
            b = (b + n) % 4;
            n = n / 5;
        }

        for (int i = 1 ; i <= b; i++)
        {
            if ((a / 2) % 2 == 1) a = ( a + 10 ) / 2;
            else a = a / 2;
        }

        cout<<setw(5)<< tmp <<" -> " << a % 10 << endl;
    }
}
