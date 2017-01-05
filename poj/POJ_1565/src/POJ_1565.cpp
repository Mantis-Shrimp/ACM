//============================================================================
// Name        : POJ_1565.cpp
// Author      : 
// Version     :
// Copyright   : 2012-6-12
// Description : skewÊý  ¼òµ¥¼ÆËã
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 100

unsigned int base[LEN];
char num[LEN];
int len;
unsigned int r;

int main()
{
	base[0]=1;
	for(int i = 1 ; i<=30; i++) base[i]=base[i-1]*2 + 1;
	scanf("%s",num);
	while(num[0]!='0')
	{
		r = 0,strrev(num),len = strlen(num);
		for(int i = 0 ; i<len ; i++) r+=(num[i]-'0')*base[i];
		printf("%d\n",r);
		scanf("%s",num);
	}
	return 0;
}
