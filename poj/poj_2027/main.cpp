#include <stdio.h>



int count = 0 ;
int X = 0;
int Y = 0;


int main(int argc, char **argv)
{
	//printf("hello world\n");
	scanf("%d",&count);
	while(count--)
	{
		scanf("%d%d",&X,&Y);
		if(X>=Y) printf("MMM BRAINS\n");
		else printf("NO BRAINS\n");
	}
	return 0;
}
