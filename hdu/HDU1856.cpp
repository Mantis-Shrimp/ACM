#include <stdio.h>
#define LEN (10000000+2)

int f[LEN],c[LEN];
int t,a,b,i,j,rect;

int findroot(int a)
{
    if(f[a]==a) return a;
    else return f[a]=findroot(f[a]);
}

int set_union(int a,int b)
{
    int fa,fb;
    fa = findroot(a),fb = findroot(b);
    if(fa!=fb) f[fb] = fa,c[fa]+=c[fb];
    return 0;
}

int main()
{
    while(scanf("%d",&t)!=EOF)
    {
        for(i = 1 ;i <= 10000000 ; i++) c[i]=1,f[i]=i;
        rect = 1;

        for(i = 1 ; i <= t ; i++)
        {
            scanf("%d%d",&a,&b);
            set_union(a,b);
        }

        for(i = 1 ;i <= 10000000 ; i++)
        {
            if(f[i]==i)
                if(c[i]>rect) rect=c[i];
        }
        printf("%d\n",rect);
    }
    return 0;
}
