//============================================================================
// Name        : POJ_1579.cpp
// Author      : 
// Version     :
// Copyright   : 2012-7-8
// Description : Function Run Fun 记忆化的深度优先
//============================================================================

#include <stdio.h>
#include <string.h>
#define MAX 25
int r[MAX][MAX][MAX],a,b,c;
int dfs(int a,int b,int c);
int main()
{
	memset(r,-1,sizeof(r));
	while(scanf("%d%d%d",&a,&b,&c)&&!(a==-1&&b==-1&&c==-1))
	    printf("w(%d, %d, %d) = %d\n",a,b,c,dfs(a,b,c));
	return 0;
}

int dfs(int a,int b,int c)
{
	if(a<=0||b<=0||c<=0){return 1;}
	else
	if(a>20||b>20||c>20){return dfs(20,20,20);}
	else
	{
		if(r[a][b][c]!=-1) return r[a][b][c];
		else
		if(a<b&&b<c) {r[a][b][c]=dfs(a, b, c-1) + dfs(a, b-1, c-1) - dfs(a, b-1, c);return r[a][b][c];}
		else{r[a][b][c]=dfs(a-1, b, c) + dfs(a-1, b-1, c) + dfs(a-1, b, c-1) - dfs(a-1, b-1, c-1);return r[a][b][c];}
	}
}
