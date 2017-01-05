//============================================================================
// Name        : POJ_2562.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <string.h>

char _a[15];
char _b[15];
char a[15];
char b[15];
char r[15];
int alen = 0 ;
int blen = 0 ;
int len = 0 ;
int count = 0 ;

int main()
{
	memset(a,0,15*sizeof(char));
	memset(b,0,15*sizeof(char));
	memset(r,0,15*sizeof(char));
	scanf("%s %s\n",_a,_b);
	while(strcmp(_a,"0")!=0||strcmp(_b,"0")!=0)
	{
		alen = strlen(_a);
		blen = strlen(_b);
		len = alen>blen?alen:blen;
		strrev(_a);
		strrev(_b);
		count = 0 ;
		for(int i = 0 ; i < alen; a[i] = _a[i]-'0',i++ );
		for(int i = 0 ; i < blen; b[i] = _b[i]-'0',i++) ;

		for(int i = 0 ; i < len ; i++)
		{
			r[i] += a[i] + b[i] ;
			if(r[i] >= 10) r[i+1] += r[i]/10 , r[i] = r[i]%10 , count++;
		}
		if(count ==1)
		   printf("%d carry operation.\n",count);
		if(count > 1)
		   printf("%d carry operations.\n",count);
		if(count==0)
	       printf("No carry operation.\n");
	   memset(a,0,15*sizeof(char));
	   memset(b,0,15*sizeof(char));
	   memset(r,0,15*sizeof(char));
	   scanf("%s %s\n",_a,_b);
	}
	return 0;
}
