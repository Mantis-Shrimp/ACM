#include <stdio.h>


int count = 0;
int abs(int value);

int main()
{
    char x0,y0;
	char x1,y1;
	int dx,dy;
	scanf("%d",&count);
	getchar();
	while(count--)
	{
		x0 = getchar(),y0 = getchar(),getchar();
		x1 = getchar(),y1 = getchar(),getchar();
		dx = abs((int)x0 - x1),dy = abs((int)y0 - y1);
		if(dx==0&&dy==0){printf("0 0 0 0\n");}
		else
		{
			dx>=dy?printf("%d",dx):printf("%d",dy);
			(dx==dy||dx==0||dy==0)?printf(" 1"):printf(" 2");
			(dx==0||dy==0)?printf(" 1"):printf(" 2");
			if((dx+dy)%2==0) dx==dy?printf(" 1\n"):printf(" 2\n");
			else printf(" Inf\n");
		}

	}
}

int abs(int value)
{
	if(value>=0)return value;
	else return -1 * value;
}
