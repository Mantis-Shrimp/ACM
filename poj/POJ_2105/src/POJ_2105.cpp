//============================================================================
// Name        : POJ_2105.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>

int val[8]={128,64,32,16,8,4,2,1};
int ip = 0 ;
int input = 0;
int count = 0 ;

int main()
{
	scanf("%d",&count);
	for(int icount = 0 ; icount < count ; icount++)
	{
		for(int j = 0 ; j < 4 ; j ++)
		{
			ip = 0;
			for(int i = 0 ; i < 8 ; i ++)
			{
				scanf("%1d",&input);
				ip += (input * val[i]);
			}
			printf("%d",ip);
			if(j!=3) printf(".");
		}
		printf("\n");
	}
	return 0;
}
