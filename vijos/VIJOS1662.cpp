//============================================================================
// Name        : Vijos1064
// Author      :
// Version     :
// Copyright   : 2013-10-29
// Description : greedy algorithm
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxn 100001

int cmp1(const void *a, const void *b)
{
    return *(long *)a - *(long *)b;
}

int cmp2(const void *a, const void *b)
{
    return -cmp1(a, b);
}

long N, K, A[maxn], B[maxn];
long long Ans = 0;

int main(void)
{
    long i, l, r;
    scanf("%ld%ld", &N, &K);
    for (i = 1; i <= N; i++) scanf("%ld", &A[i]);
    for (i = 1; i <= N; i++) scanf("%ld", &B[i]);
    qsort(A + 1, N, sizeof(long), cmp1);
    qsort(B + 1, N, sizeof(long), cmp2);
    l = 1; r = N;
    while (K--)
    {
        if ( abs(A[l] - B[l]) > abs(A[r] - B[r]) )
        {
            Ans += abs(A[l] - B[l]);
            l++;
        }
        else
        {
            Ans += abs(A[r] - B[r]);
            r--;
        }
    }
    printf("%I64d\n", Ans);
    return 0;
}