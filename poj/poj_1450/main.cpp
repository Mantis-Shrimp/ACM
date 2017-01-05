#include <stdio.h>

int total = 0 ;
int row,col;
int count = 1;


int main(int argc, char **argv)
{

	scanf("%d",&total);
	while(total--)
	{
		scanf("%d%d",&row,&col);
		if(row%2==0||col%2==0)
		printf("Scenario #%d:\n%d.00\n\n",count++,row*col);
		else
		printf("Scenario #%d:\n%d.41\n\n",count++,row*col);
	}
	return 0;
}
