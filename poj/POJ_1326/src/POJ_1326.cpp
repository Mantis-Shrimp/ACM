//============================================================================
// Name        : POJ_1326.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <string.h>

char start[100];
char end[100];
double mileages;
int total = 0;
char flag = 0 ;

int main()
{

	while(1)
	{
		scanf("%s",start);
		if(strcmp(start,"0")==0)
		{
			printf("%d\n",total);
			total = 0.0 ;
		}
		else
		{
		    if(strcmp(start,"#")==0)
		    {
			    return 0;
		    }
		    else
		   {
		    	scanf("%s%lf %c\n",end,&mileages,&flag);
		    	switch(flag)
			   {
			   case 'F':
				   total+= (int) ((mileages * 2) + 0.5);
				   break;
			   case 'B':
				   total+=  (int) ((mileages + mileages * 0.5)+0.5);
				   break;
			   case 'Y':
				   total+= (int) ((mileages>500.0?mileages:500.0)+0.5);
				   break;
			   }
		   }
		}
	}
	return 0;
}
