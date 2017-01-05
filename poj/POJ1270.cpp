#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 30


using namespace std;


int adj[MAX][MAX],vis[MAX],degree[MAX];
char in[5*MAX],map[5*MAX],dict[MAX],rect[MAX];
int a,b,len;


int DFS(int depth,int len)
{
    if(depth==len)
    {
        rect[len]=0;
        puts(rect);
    }

    for(int i = 1 ; i <= len ; i++)
    {
        if(degree[i]==0&&vis[i]==0)
        {
            rect[depth]=dict[i];
            for(int l = 1 ; l <= adj[i][0] ; l++)
                degree[adj[i][l]]--;
            vis[i] = 1;

            DFS(depth+1,len);

            for(int l = 1 ; l <= adj[i][0] ; l++)
                degree[adj[i][l]]++;
            vis[i] = 0;

        }
    }
    return 0;
}

bool cmp(char a,char b)
{
    return a<b;
}


int main()
{
    while(gets(in))
    {
        memset(adj,0,sizeof(adj));
        memset(map,0,sizeof(map));
        memset(vis,0,sizeof(vis));
        memset(degree,0,sizeof(degree));
        len = strlen(in);
        sort(in,in+len,cmp);
        int i = 0,j = 0,k = 0;

        while(in[i++]!=0)
            if(in[i-1]!=' ')
                map[in[i-1]]=++j;
        for(int i = 0 ; i < (5*MAX) ; i++)
            dict[map[i]] = i;

        gets(in);

        i = k = 0;
        while(in[i++]!=0)
        {
            if(in[i-1]!=' ')
            {
                if(k%2==0)
                {
                    a = in[i-1];
                }
                else
                {
                    b = in[i-1];
                    adj[map[a]][++adj[map[a]][0]]=map[b];
                    degree[map[b]]++;
                }
                k++;
            }
        }
    DFS(0,j);
    putchar('\n');
    }
    return 0;
}
