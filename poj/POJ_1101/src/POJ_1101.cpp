//============================================================================
// Name        : POJ_1101.cpp
// Author      : 
// Version     :
// Copyright   : 2012-7-7
// Description : The Game 深度优先  + 记忆化搜索
//============================================================================

#include <stdio.h>
#include <string.h>
#define W 80
#define H 80
int DFS(int x0,int y0,int x1,int y1,int flag);
char chess[H][W],flag[H][W];
int w,h,x0,y0,x1,y1,ncase,npair,r[H][W];

int main()
{
    ncase=0;
	while(scanf("%d%d",&w,&h)&&w+h!=0)
    {
		printf("Board #%d:\n",++ncase);
		memset(chess,' ',sizeof(chess));
    	for(int iw = 0; iw <= w ; iw++)
    		for(int ih =0 ; ih <=h ; ih++)
    			scanf("%c",chess[iw][ih]),getchar();
    	npair=0;
    	while(scanf("%d%d%d%d",&x0,&y0,&x1,&y1)&&x0+y0+x1+y1!=0)
    	{
    		npair++,memset(r,-1,sizeof(r)),memset(flag,0,sizeof(flag));
    		DFS(x0,y0,x1,y1,0);
    	}
    }
	return 0;
}

int DFS(int x0,int y0,int x1,int y1,int flag)
{
    int r = 100000,temp=0;
    if(r[x0][y0]!=-1) return r[x0][y0];
	if(x0==x1&&y0==y1) {r = 0;r[x0][y0] = r;return r;}

	if(x0-1>=0&&chess[x0-1][y0]==' ')
	{
		temp = DFS(x0-1,y0,x1,y1,1);
	}

	return r;
}
