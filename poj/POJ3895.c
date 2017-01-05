#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define  N 4500

short int adj[N][N],vis[N];
int m,n,t;
int pa,pb,max;



int dfs(int depth,int cp)
{
    int i;
    for(i = 1 ; i <= adj[cp][0] ;i++)
    {
        if(vis[adj[cp][i]]==0)
        {
            vis[adj[cp][i]] = depth + 1;
            dfs(depth+1,adj[cp][i]);
        }
        else
        {
            if(-vis[adj[cp][i]] + depth +1 > max&&-vis[adj[cp][i]] + depth +1>=3) max = -vis[adj[cp][i]] +depth +1;
        }
    }
    return 0;
}



int main()
{
    int i,j;
    scanf("%d",&t);
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        memset(adj,0,sizeof(adj));
        max=0;
        scanf("%d%d",&n,&m);
        for(i = 1 ; i <= m ; i++)
        {
            scanf("%d%d",&pa,&pb);
            adj[pa][++adj[pa][0]]=pb;
            adj[pb][++adj[pb][0]]=pa;
        }
        for(j = 1 ; j <=n ;j++)
        if(vis[j]==0)
        {
            vis[j]=1;
            dfs(1,j);
        }
        printf("%d\n",max);
    }
    return 0;
}
