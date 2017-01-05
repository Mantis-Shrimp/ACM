#include <stdio.h>

int data[150] = { 0 };
int count = 0 ;
int n = 0 ;
int icount = 0 ;

int main(int argc, char **argv)
{
	for(int i = 1 ; i <= 100 ; i ++)
	{
		for(int j = 1; j*i<=100;j++)
		{
			if(data[j*i]) data[j*i]=0;
			else data[j*i] = 1;
		}
	}
	scanf("%d",&count);

	while(count--)
	{
		scanf("%d",&n);
		icount = 0 ;
		for(int i = 1;i<=n;i++)
		{
			if(data[i])icount ++;
		}
		printf("%d\n",icount);
	}
	return 0;
}
