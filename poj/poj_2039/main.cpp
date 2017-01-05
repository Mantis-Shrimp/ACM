#include<stdio.h>
#include<string.h>

int col = 0 ;
int row = 0 ;
char ch[10000];
int len = 0 ;
int main()
{
	scanf("%d\n",&col);
	while(col!=0)
	{
	gets(ch);
	len = strlen(ch);
	for(int iWidth = 0 ; iWidth < col; iWidth ++)
	    for(int iHeight = 0 ; iHeight < len / col; iHeight++)
	       if(iHeight%2==0)
		    printf("%c",ch[iHeight*col+iWidth]);
		    else
		    printf("%c",ch[iHeight*col - iWidth + col - 1]);
     putchar('\n');
     scanf("%d\n",&col);
	}
	return 0;
}
