//============================================================================
// Name        : Vijos1062
// Author      :
// Version     :
// Copyright   : 2013-10-31
// Description : data structure 
//============================================================================
#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 1000001
using namespace std;
int N , L ;
int next[MAXN] , add[MAXN] , a[MAXN] , s[MAXN] ;
struct data
{
    int s , num ;
} q[MAXN] ;

int main()
{
    scanf("%d%d", &N, &L);
    scanf("%d%d", &next[N], &add[1]);
    int tot = 0 ;
    for (int i = 2 ; i <= N ; i++)
    {
        scanf("%d%d", &next[i - 1] , &add[i]);
        tot += next[i - 1] ;
    }
    next[N] = L - tot ;
    
    for (int i = 1 ; i <= N ; i ++)
        a[i] = add[i] - next[i] ;
    
    for (int i = N + 1 ; i <= 2 * N - 1 ; i++)
        a[i] = a[i - N];
    
    s[0] = 0 ;
    
    for (int i = 1 ; i <= 2 * N - 1 ; i++)
        s[i] = s[i - 1] + a[i] ;
    int l = 0 , r = 0 ;
    
    for (int i = 1 ; i <= N - 1 ; i++)
    {
        while (r > l && q[r].s > s[i]) r--;
        r++;
        q[r].s = s[i] ;
        q[r].num = i ;
    }
    
    for (int i = N ; i <= 2 * N - 1; i++)
    {
        while (q[l].num <= i - N && l < r) l++;
        while (r > l && q[r].s > s[i]) r--;
        r++;
        q[r].s = s[i] ;
        q[r].num = i ;
        if (s[i - N] <= q[l].s) printf("%d ", i - N + 1);
    }
    return 0 ;
}