//*******************************************************//
//1154.cpp
//letters
//DFS ¼òµ¥
//*******************************************************//
#include <cstdio>
#include <cstring>
#define MAX 30

int dfs(int depth,int y,int x);

int r,c,letter[MAX][MAX],ps[MAX][MAX],d;
char alph[MAX];

int main()
{
    d=0,memset(alph,0,sizeof(alph)),memset(ps,0,sizeof(ps));
    freopen("in.txt","r",stdin);
    scanf("%d%d",&r,&c);
    getchar();
    for(int ir = 1 ; ir <= r ; ir++)
    {
       for(int ic = 1 ; ic <= c ; ic++)
	       scanf("%c",&letter[ir][ic]);
       getchar();
    }
    ps[1][1]=1;
    alph[letter[1][1]-'A']=1;
    dfs(1,1,1);
    printf("%d\n",d);
    return 0;
}

int dfs(int depth,int y,int x)
{
     //for(int ir = 1 ; ir <= r ; ir++)
     //{
//	     for(int ic = 1 ; ic <= c ; ic++)
//	       printf("%d",ps[ir][ic]);
//	    printf("\n");
//    }

//     printf("\n");

   if((y-1>=1&&y-1<=r)&&ps[y-1][x]==0&&alph[letter[y-1][x]-'A']==0)
    {
	    ps[y-1][x]=1;
	    alph[letter[y-1][x]-'A']=1;
	    dfs(depth+1,y-1,x);
	    ps[y-1][x]=0;
	    alph[letter[y-1][x]-'A']=0;
    }


    if((y+1>=1&&y+1<=r)&&ps[y+1][x]==0&&alph[letter[y+1][x]-'A']==0)
    {
	    ps[y+1][x]=1;
	    alph[letter[y+1][x]-'A']=1;
	    dfs(depth+1,y+1,x);
	    	    ps[y+1][x]=0;
	    alph[letter[y+1][x]-'A']=0;
    }


    if((x-1>=1&&x-1<=c)&&ps[y][x-1]==0&&alph[letter[y][x-1]-'A']==0)
    {
	    ps[y][x-1]=1;
	    alph[letter[y][x-1]-'A']=1;
	    dfs(depth+1,y,x-1);
	    ps[y][x-1]=0;
	    alph[letter[y][x-1]-'A']=0;
    }

    
    if((x+1>=1&&x+1<=c)&&ps[y][x+1]==0&&alph[letter[y][x+1]-'A']==0)
    {
	    ps[y][x+1]=1;
	    alph[letter[y][x+1]-'A']=1;
	    dfs(depth+1,y,x+1);
	    ps[y][x+1]=0;
	    alph[letter[y][x+1]-'A']=0;
    }

    if(depth>=d) d = depth;
    return 0;
}
