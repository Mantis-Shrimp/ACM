#include <stdio.h>
#include <stdlib.h>

#define N (1000+10)

int f[N],n,m,a,b,rect;



int findroot(int a)
{
    if(f[a]==a) return a;
    else return f[a]=findroot(f[a]);
}

int set_union(int a,int b)
{
    int fa,fb;
    fa = findroot(a),fb = findroot(b);
    if(fa!=fb) f[fb] = fa;
    return 0;
}


int main()
{
    int i;
    while(scanf("%d%d",&n,&m)!=EOF&&n!=0)
    {
        for(i = 1 ; i<= n ; i++) f[i] = i;
        rect = 0;
        for(i = 1 ; i<= m ; i++)
        {
            scanf("%d%d",&a,&b);
            set_union(a,b);
        }

        for(i = 1 ; i <= n ; i++)
            if(f[i]==i) rect++;
        printf("%d\n",rect-1);
    }
    return 0;
}
