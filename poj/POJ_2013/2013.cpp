#include <stdio.h>

char chs[30];
char ch[50][30];
int count = 0 ;
int iend = 0 ;
int num = 0 ;

int main()
{
	scanf("%d\n",&count);
	while(count!=0)
	{
		for(int icount = 0 ; icount < count ; icount++) gets(ch[icount]);
		printf("SET %d\n",++num);
		for(int icount = 0 ; icount < count ; icount+=2) puts(ch[icount]);
		iend = (count-1)%2==0?count-2:count-1;
	    for(int icount = iend; icount >= 1; icount-=2) puts(ch[icount]);
		scanf("%d\n",&count);
	}
	return 0;
}
