//============================================================================
// Name        : POJ_4011.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>

int ATE;
int X0,X1;
int count;


int DFS(int,int);

int main()
{
	while(scanf("%d",&ATE)!=EOF)
	{
		count=0;
		if(ATE>=200) printf("0\n");
		else DFS(0,ATE),printf("%d\n",count);
	}
}

int DFS(int depth,int sum)
{
	if(depth==2)
	{
		if(sum==0) {count++;return 1;}
		else {return 0;}
	}
	for(int i = 0 ; i <= 99 ; i++)
	{
		DFS(depth+1,sum-i);
	}
	return 0;
}
