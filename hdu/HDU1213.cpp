#include <stdio.h>
#include <string.h>

#define N 1500

int f[N],t,n,m,a,b,rect;
int i;



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
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        rect = 0 ;
        for(i = 0; i <= n ; i++) f[i] = i;
        for(i = 1; i <= m ; i++)
        {
            scanf("%d %d",&a,&b);
            set_union(a,b);
        }
        for(i = 1; i <= n ; i++)
            if(f[i]==i) rect++;
        printf("%d\n",rect);
    }
    return 0;
}
