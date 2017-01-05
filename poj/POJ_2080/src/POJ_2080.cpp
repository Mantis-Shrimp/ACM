//============================================================================
// Name        : POJ_2080.cpp
// Author      : 
// Version     :
// Copyright   : 2012-6-12
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int years[10000];
int months[][12]={{31,28,31,30,31,30,31,31,30,31,30,31},
                   {31,29,31,30,31,30,31,31,30,31,30,31}};
char day[][10]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
int y,m,d,w;
int x;

int main()
{
	int i,j;
	for(i = 2000; i<=9999 ; i++)
		if(i%100==0)
			 if(i%400==0) years[i]=366;
			 else years[i]=365;
		else if(i%4==0) years[i]=366;
		     else years[i]=365;
	scanf("%d",&x);
	while(x!=-1)
	{
		w=x%7;
		for( i=2000; x>=years[i];i++) x-=years[i];
		for( j=0 ; x>=months[years[i]-365][j] ; j++) x-=months[years[i]-365][j];
		printf("%d-%02d-%02d %s\n",i,j+1,x+1,day[w]);
		scanf("%d",&x);
	}
	return 0;
}
