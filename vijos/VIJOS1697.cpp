//============================================================================
// Name        : Vijos1531
// Author      :
// Version     :
// Copyright   : 2013-11-6
// Description : data stucture  并查集
//============================================================================

#include <cstdio>
#include <cstdlib>
#include <cstring>

#define N 2
#define Max 50050


int fa[Max];
int val[Max];
int count0[Max],count1[Max];


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
    freopen("in.txt", "r", stdin);
    int n, m, q,sum;
    int x, y;
    char z;
    int px, py, vx, vy;

    for (int i = 0 ; i < Max ; i++)
        fa[i] = i;

    memset(val, 0, sizeof(val));
    memset(count0, 0, sizeof(count0));
    memset(count1, 0, sizeof(count1));

    scanf("%d%d%d\n", &n, &m, &q);
    //printf("%d%d%d\n", n, m, q);
    for (int i = 1 ; i <= m ; i++)
    {
        scanf("l%d %c l%d\n", &x, &z, &y);

        //printf("%d %c %d\n", x, z, y);
        px = findroot(x);
        py = findroot(y);

        vx = val[x];
        vy = val[y];

        if (px == py)
        {
            if (z == 'p')
            {
                if (vx == vy)
                {
                    continue;
                }
                else
                {
                    printf("There must be something wrong...\n");
                    return 0;
                }
            }
            if (z == 'v')
            {
                if (vx == vy)
                {
                    printf("There must be something wrong...\n");
                    return 0;
                }
                else
                {
                    continue;
                }
            }
        }
        else
        {
            if (z == 'p')
                Union_set(x, y, 0);
            else
                Union_set(x, y, 1);
        }
    }


    sum = 0 ;
    for(int i = 1 ; i <= n ;i++)
    {
        px = findroot(i);
        //vx = val[i];
        if(val[i] == 0) count0[px] ++ ;
        else count1[px] ++ ;
    }

    for(int i = 1 ; i <= n ; i++)
    {
        if(findroot(i) == i)
        {
            sum += (count0[i]*(count0[i]-1) / 2);
            sum += (count1[i]*(count1[i]-1) / 2);
        }
    }

    printf("%d\n", sum);

    for (int i = 1 ; i <= q ; i++)
    {
        scanf("l%d l%d\n", &x, &y);
        px = findroot(x);
        py = findroot(y);

        vx = val[x];
        vy = val[y];

        if (px == py)
        {
            if (vx == vy)
                printf("Parallel.\n");
            else
                printf("Vertical.\n");
        }
        else
        {
            printf("No idea.\n");;
        }
    }
    return 1;
}

