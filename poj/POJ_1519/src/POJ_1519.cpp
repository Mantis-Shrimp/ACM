//============================================================================
// Name        : POJ_1519.cpp
// Author      : 
// Version     :
// Copyright   : 2012-5-2
// Description : http://poj.org/problem?id=1519 Digital Roots ÊýÂÛ
//============================================================================

#include <stdio.h>
#include <string.h>

#define LEN 10000

int main()
{
	char num[LEN];
	int len,r;
	scanf("%s\n",num);
	while(num[0]!='0')
	{
		r = 0,len = strlen(num);
		for(int i = 0 ; i < len ; i++) r= (r + num[i]-'0')%9;
		if(r==0) printf("9\n");
		else printf("%d\n",r);
		scanf("%s\n",num);
	}
	return 0;
}
