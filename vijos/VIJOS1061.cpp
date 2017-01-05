//============================================================================
// Name        : Vijos1061
// Author      :
// Version     :
// Copyright   : 2013-10-30
// Description : dynamical programming 
//============================================================================

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int a[5001], f[1001][5001];
int main()
{
    int i, j, n, m;
    
    scanf("%d %d\n", &m, &n);
    for (i = n; i >= 1; i--) 
        scanf("%d", &a[i]);

    for (i = 1; i <= m; i++)
    {
        int s, dx, dy; s = i * 3;
        for (j = s; j <= n; j++)
        {
            dx = f[i][j - 1];
            dy = f[i-1][j - 2] + (a[j - 1] - a[j]) * (a[j - 1] - a[j]);
            if ((dx < dy) && (j >= s + 1)) f[i][j] = dx;
            else f[i][j] = dy;
        }
    }
    printf("%d\n", f[m][n]);
    return 0;
}