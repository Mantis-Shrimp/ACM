#include <stdio.h>
#include <string.h>


char alphabet[26] = {'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U'};
char str[1000];
int index = 0 ;


int main(int argc, char **argv)
{
	gets(str);
	while(strcmp(str,"ENDOFINPUT")!=0)
	{
		gets(str);
		index = 0 ;
		while(str[index]!='\0')
		{
			if(str[index]>='A'&&str[index]<='Z') str[index] = alphabet[str[index]-'A'];
			index ++ ;
		}
		puts(str);
		gets(str);
		gets(str);
	}
	return 0;
}
