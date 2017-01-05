//============================================================================
// Name        : POJ_3632.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
int max,min;
int count;
int num;
int temp;

int main()
{
	scanf("%d",&count);
	while(count--)
	{
		scanf("%d",&num);
		for(int inum = 0 ; inum < num ; inum++)
		{
			scanf("%d",&temp);
			if(inum == 0 ) max = temp ,min = temp;
			if(temp>max) max = temp;
			if(temp<min) min = temp;
		}
		printf("%d\n",max-min+max-min);
	}
	return 0;
}
