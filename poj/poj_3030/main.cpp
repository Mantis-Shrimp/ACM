#include <stdio.h>

int count = 0 ;
int r = 0 ;
int e = 0 ;
int c = 0 ;

int main(int argc, char **argv)
{
	scanf("%d",&count);
	while(count--)
	{
		scanf("%d%d%d",&r,&e,&c);
		if((e-c)==r) printf("does not matter\n");
		else if((e-c)>r) printf("advertise\n");
			  else  printf("do not advertise\n");
	}
	return 0;
}
