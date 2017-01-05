#include <stdio.h>

int DFS(int,int,int);

int number = 0 ;
int M = 7;
int N= 3;
int count = 0;

int main(int argc, char **argv)
{
	scanf("%d",&number);
	while(number--)
	{
	scanf("%d %d",&M,&N);
	count=0;
	DFS(0,0,M);
	printf("%d\n",count);
	}
	return 0;
}

int DFS(int depth,int start,int end)
{
	if(depth==N-1&&end>=start)
	{
		count++;
		return 1;
	}
	
	for(int i = start;i<=end;i++)
	{
		DFS(depth+1,i,end-i);
	}
	return 1;
}

