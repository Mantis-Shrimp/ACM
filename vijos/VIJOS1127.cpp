//============================================================================
// Name        : Vijos1127
// Author      :
// Version     :
// Copyright   : 2013-11-7
// Description : 简单题
//============================================================================

#include <stdio.h>
int main()
{
    long k, n;
    double sn;
    scanf("%ld", &k);
    for (n = 2; n <= 15; n++)
    {
        sn += 1.0 / n;
        if (sn >= k)
            printf("%ld", n); break;
    }
    return 0;
}