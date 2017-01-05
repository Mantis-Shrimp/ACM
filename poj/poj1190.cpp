#include "iostream"
#include "vector"
#include "climits"
#include "cstdio"

using namespace std;

int n,m,best;
int minv[22];
int mins[22];

void DFS(int dep,int sumv,int sums,int r,int h)
{

    int maxh;

    if(dep == 0)
    {
        if(sumv == n && sums < best)
                best = sums;

        return;
    }

    if( (sumv + minv[dep] > n) || (sums + mins[dep] > best) || (( ( n - sumv ) * 2 ) / (r+1) + sums) > best )
        return;


    for(int i = r ; i >= dep ; i-- )
    {
        if( ((n - sumv - minv[dep-1]) / (i * i)) < h) 
            maxh = (n - sumv - minv[dep-1]) / (i * i);
        else
            maxh = h;

        for(int j = maxh ; j>=dep ; j-- )
        {

            if(dep == m)
                DFS(dep - 1 ,j * i * i ,2 * j * i + i * i, i -1  , j -1 );
            else
                DFS(dep - 1 ,sumv + j * i * i,sums + 2 * j * i, i -1  , j -1 );
        }
    }

    return;
}



int main()
{

    minv[0] = mins[0] = 0;
    for(int i=1;i<22;i++)
    {
        minv[i]=minv[i-1]+i*i*i;
        mins[i]=mins[i-1]+2*i*i;
    }

    while(scanf("%d%d",&n,&m)!=EOF)
    {
        best= INT_MAX;
        DFS(m,0,0,n+1,n+1);
        if(best==INT_MAX)
            best=0;
        printf("%d\n",best);
    }
    return 0;
}