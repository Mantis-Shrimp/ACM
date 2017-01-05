//============================================================================
// Name        : POJ1041
// Author      :
// Version     :
// Copyright   : 2013-11-2
// Description :
//============================================================================
#include "cstdio"
#include "cmath"

int main()
{
    float p, q;
    int i;
    scanf("%f%f", &p, &q);
    p = p / 100;
    q = q / 100;
    for (i = 1;; i++)
        if (floor(i * q - 0.000001) - floor(i * p + 0.000001) >= 1)
            break;
    printf("%d", i);
    return 0;
}