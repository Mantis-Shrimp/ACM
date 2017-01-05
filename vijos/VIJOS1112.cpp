//============================================================================
// Name        : Vijos1112
// Author      :
// Version     :
// Copyright   : 2013-11-6
// Description : data stucture  并查集
//============================================================================

#include <cstdio>
#include <cstdlib>
#include <cstring>

#define N 3
#define Max 50050


int fa[Max];
int val[Max];

int findroot(int x)
{
    int fx = fa[x];
    if (fx == x)
    {
        return x;
    }
    else
    {
        fa[x] = findroot(fa[x]);
        val[x] = (val[fx] + val[x]) % N;
        return fa[x];
    }
}

int Union_set(int x, int y, int c) // add  y to x
{
    int fx = findroot(x);
    int fy = findroot(y);
    if (fx != fy)
    {
        fa[fy] = fx;
        val[fy] = (c + val[x] - val[y] + N) % N;
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(int argc , char *argv[])
{
    int n, k, x, y, z;
    int c = 0;
    int px, py, vx, vy;

    for (int i = 0 ; i < Max ; i++)
        fa[i] = i;

    memset(val, sizeof(val), 0);

    scanf("%d%d", &n, &k);
    for (int i = 1 ; i <= k ; i++)
    {
        scanf("%d%d%d", &z, &x, &y);

        if (x > n || y > n )
        {
            c ++ ;
            continue ;
        }

        px = findroot(x);
        py = findroot(y);

        vx = val[x];
        vy = val[y];

        if (px == py)
            if (z == 1)
                if (vy == vx) continue;
                else c ++ ;
            else
                if ((vx - vy + N ) % N == 1) continue;
                else c ++ ;
        else
            if (z == 1)
                Union_set(y, x, 0);
            else
                Union_set(y, x, 1);

    }

    printf("%d\n", c);
    return 1;
}

