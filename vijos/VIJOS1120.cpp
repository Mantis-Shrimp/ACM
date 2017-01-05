#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int plant[51][51];
int main()
{
    int cx, cy, T, m, n, i, j, mx, my, time, get;
    get = 0;
    scanf("%d%d%d", &m, &n, &time);
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &plant[i][j]);
    mx = my = 1;
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (plant[i][j] > plant[mx][my])
            {
                mx = i;
                my = j;
            }
        }
    }
    cy = my;
    cx = 0;
    while (time > 0)
    {
        for (i = 1; i <= m; i++)
            for (j = 1; j <= n; j++)
            {
                if (plant[i][j] > plant[mx][my])
                {
                    mx = i;
                    my = j;
                }
            }
        if (plant[mx][my] == 0)
            break;
        if (time >= (abs(cx - mx) + abs(cy - my) + mx + 1))
        {
            time -= (abs(cx - mx) + abs(cy - my) + 1);
            cx = mx; cy = my;
            get += plant[mx][my];
            plant[mx][my] = 0;
        }
        else break;
    }
    printf("%d\n", get);
    return 0;
}