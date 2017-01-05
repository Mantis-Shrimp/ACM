//============================================================================
// Name        : POJ_1321.cpp
// Author      : 
// Version     :
// Copyright   : 2012-7-8
// Description : ∆Â≈ÃŒ Ã‚ DFS
//============================================================================

#include <stdio.h>
#include <string.h>
#define H 15
#define W 15
int DFS(int depth,int count);
char chess[H][W],wflag[W],hflag[H];
int rx[H*W],w,h,n,num;
//int x[H],y[H];
int main()
{
    while(scanf("%d%d",&w,&n)!=EOF&&!(w==-1&&n==-1))
    {
	getchar();
	h=w,memset(wflag,0,sizeof(wflag)),memset(hflag,0,sizeof(hflag)),num=0;
	for(int i=0;i<h;i++)gets(chess[i]);
	DFS(0,0);
	printf("%d\n",num);
    }
    return 0;
}

int DFS(int depth,int count)
{
    if(count==n)
	{
	//for(int i = 0 ; i<16 ;i++) printf("%d ",x[i]);
	//printf("\n");
	//for(int i = 0 ; i<16 ;i++) printf("%d ",y[i]);
	//printf("\n");
	num++;
	return 0;
	}
    if(depth==w*h) return 0;

    if(chess[depth/w][depth%w]=='.')
    {
	DFS(depth+1,count);
    }
    else
    {
	for(int i = 0 ; i<=1 ;i++)
	{
	    if(i==0){DFS(depth+1,count);}
	    else
	    {
		if(hflag[depth/w]==0&&wflag[depth%w]==0)
		{
		    hflag[depth/w]=1;
		    wflag[depth%w]=1;
		    //x[count]=depth/w;
		    //y[count]=depth%w;
		    DFS(depth+1,count+1);
		    hflag[depth/w]=0;
		    wflag[depth%w]=0;
		}
	    }
	}
    }
    return 0;
}
