//============================================================================
// Name        : POJ_1207.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>

int start,end;
int max,count;
int n ;
int istart,iend;




int main()
{
	while(scanf("%d%d",&start,&end)!=EOF)
	{
		max = 0;
		if(start>end) iend = start ,istart = end ;
		else iend = end ,istart = start ;
		for(int i = istart;i<=iend;i++)
		{
			n = i , count=0;
			while(n!=1)
			{
				if(n%2)n=n*3+1;
				else n/=2;
				count++;
			}
			max=max>count?max:count;
		}
		printf("%d %d %d\n",start,end,max+1);
	}
	return 0;
}
