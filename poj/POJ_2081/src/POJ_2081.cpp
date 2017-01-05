//============================================================================
// Name        : POJ_2081.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int seq[510000];
char _seq[10000000];
int temp = 0 ;
int flag = 0 ;
int num = 0 ;
int main()
{
	memset(_seq,0,510000*sizeof(char));
	seq[0] = 0 ;
	_seq[0] = 1 ;
	for(int i = 1 ; i < 510000 ; i++)
	{
		temp = seq[i-1] - i;
		flag = 1 ;
		if(temp < 0) flag = 0 ;
		if(_seq[temp]==1) flag = 0 ;
		if(flag ==1)
		{
			seq[i] = temp ;
			_seq[temp] = 1 ;
		}
		else
		{
			seq[i] = seq[i-1] + i ;
			_seq[seq[i]] = 1  ;
		}
	}
	scanf("%d",&num);
	while(num!=-1)
	{
		 printf("%d\n",seq[num]);
		 scanf("%d",&num);
	}
	return 0;
}
