//============================================================================
// Name        : POJ_1063.cpp
// Author      : 
// Version     :
// Copyright   : 2012-5-1
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>

int list[2][60000];
int num=0;
int x,y;

int main()
{
	int ih=0,iw=0;
	list[ih][iw] = 0 ;

	for(int i = 1 ; i <= 5000 ; i++)
	{
		iw++,list[ih][iw] = 4*i-3 ;
		ih++,list[ih][iw] = 4*i-2 ;
		iw++,list[ih][iw] = 4*i-1 ;
		ih--,list[ih][iw] = 4*i;
	}
	scanf("%d",&num);
	while(num--)
	{
		scanf("%d%d",&x,&y);
		if(x>=0&&y>=0&&x==y)
		{
			printf("%d\n",list[0][x]);
		}
		else
		{
			if(x>=2&&y>=0&&(x-y)==2)
			{
				printf("%d\n",list[1][x-1]);
			}
			else
			{
				printf("No Number\n");
			}
		}
	}
	return 0;
}
