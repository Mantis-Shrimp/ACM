//============================================================================
// Name        : POJ_1164.cpp
// Author      : 
// Version     :
// Copyright   : 2012-7-6
// Description : The Castle  简单的深度优先
//============================================================================

#include <stdio.h>
#include <string.h>
#define M 60
#define N 60
int maze[M][N],flag[M][N],m,n,num,max,_max;

int DFS(int,int);

int main()
{
    scanf("%d%d",&m,&n);
    memset(flag,0,sizeof(flag)),num=0,max=0;

    for(int im = 1 ; im<=m ; im++)
	for(int in = 1 ; in<=n ; in++)
	    scanf("%d",&maze[im][in]);

    for(int im = 1 ; im<=m ; im++)
    	for(int in = 1 ; in<=n ; in++)
    	    if(flag[im][in]==0)
    		{
    		   //printf("%d %d\n",im,in);
    		   num++;
    		   _max = 0;
    		   flag[im][in]=1;
    		   DFS(im,in);
    		   max = _max>max?_max:max;
    		}

    printf("%d\n%d\n",num,max);
    return 0;
}

int DFS(int x,int y)
{
    int temp = maze[x][y];
    _max++;

    if(temp/8!=1&&x+1<=m&&flag[x+1][y]==0)
	flag[x+1][y]=1,DFS(x+1,y);
    temp%=8;

    if(temp/4!=1&&y+1<=n&&flag[x][y+1]==0)
	flag[x][y+1]=1,DFS(x,y+1);
    temp%=4;

    if(temp/2!=1&&x-1>=1&&flag[x-1][y]==0)
	flag[x-1][y]=1,DFS(x-1,y);
    temp%=2;

    if(temp/1!=1&&y-1>=1&&flag[x][y-1]==0)
	flag[x][y-1]=1,DFS(x,y-1);

    return 0;
}
