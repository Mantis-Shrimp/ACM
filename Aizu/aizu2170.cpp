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

int t[1100000],flag[1100000],idx[1100000];
char query[1100000];
int n,q;


int find(int n)
{
    //if(n == 0)
//	int m = 1;
    if(flag[n] != 0)
    {
	return n;	    
    }

    else
    {	
	return t[n] = find(t[n]);    
    }
	
    

//    int node = n;
    //while(flag[t[node]] != 1 )
//	{
//	    node = t[node];
//	}
//    return t[node];
}

int main(int argc,char* argv[])
{
#ifndef ONLINE_JUDGE
    READ;
#endif
    SYNCOFF;
    while( (std::cin>>n>>q) && !(n==0&&q==0))
    {
	int ii = 0;
	int root,tmp;
	long long ret = 0;
	char chs[100],ch;
	memset(flag,0,sizeof(flag));
	t[1] = 1;
	flag[1] = 1;
	for(int i = 2 ; i <= n ; i++)
	{
	    std::cin >> root;
	    t[i] = root;
	}

	for(int i = 0 ; i < q ; i++)
	{
	    cin.getline(chs,100);
	    ch = cin.get();
	    cin>>tmp;

	    query[i] = ch;
	    idx[i] = tmp;
	    
	    //if(ch == 'M')
	    //	flag[tmp] = 1;
	    //if(ch == 'Q')
	    //	ret = ret + find(tmp);
	}

	ii = ii + 1;
	if(ii == 5)
	    int m = 0;
	for(int i = q - 1 ; i >= 0; i--)
	{
	    if(query[i] == 'M' )  flag[idx[i]]++;
	}

	for(int i = q - 1; i >= 0 ; i--)
	{
	    if(query[i] == 'M') flag[idx[i]]--;
	    else ret = ret + find(idx[i]);
	    //std::cout<<idx[i]<<std::endl;
	    //if(idx[i] == 0)
	    //int m = 1;
	}
	
	std::cout<< ret <<std::endl;
    }
    return 0;
}
