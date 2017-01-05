//============================================================================
// Name        : POJ_2141.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <string.h>

char alpl[26];
char alph[26];
char str;
int len = 0 ;

int main()
{
	while(scanf("%s\n",alpl)!=-1)
	{
		for(int i = 0 ; i < 26 ; alph[i] += (alpl[i]+ 'A' - 'a') , i++);
		str = getchar();
		while(str!='\n')
		{
		if(str<='Z'&&str>='A') printf("%c",alph[str-'A']);
		if(str<='z'&&str>='a') printf("%c",alpl[str-'a']);
		if(str == ' ')printf(" ");
		str = getchar();
		}
		printf("\n");
	}
	return 0;
}
