#include <stdio.h>


int data[150];
int count = 0 ;
int sum = 0 ;
int avg = 0 ;
int r = 0 ;
int num = 1 ;
int main(int argc, char **argv)
{

	scanf("%d",&count);
	while(count!=0)
	{
		sum = 0 ;
		r = 0 ;
		for(int i = 0 ; i < count ;scanf("%d",data + i),sum +=(*(data+i)),i++);
		avg = sum / count ;
		for(int i = 0 ; i < count ; i++) if(*(data+i)>avg) r += (*(data+i) - avg);
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",num++,r);
		scanf("%d",&count);
	}
	return 0;
}
