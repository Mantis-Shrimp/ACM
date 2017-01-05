//============================================================================
// Name        : POJ_4018.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>

char chs[60000][10];
int len;
int diff[6];
int dflag ;

int main()
{
    //#ifdef DEBUG
	freopen("in.txt","r",stdin);
   // #endif
	//int j = 0 ;

	while(scanf("%d\n",&len)!=EOF)
	{
		diff[0]=0,diff[1]=0,diff[2]=0,diff[3]=0,diff[4]=0,diff[5]=0;
		for(int i = 0 ; i < len ; i++)
		{
			gets(chs[i]);
			 for(int j = (i-1) ; j >= 0 ; j--)
			//for(j = (i-1) ; j >= 0 ; j--)
			{
				dflag = 0 ;
				for(int k = 0 ; k < 5 ; k++) if(chs[j][k]!=chs[i][k]) dflag++;
				diff[dflag]++;
			}
		}
		for(int i= 0 ; i <= 5 ; i++) printf("%d ",diff[i]);
		printf("\n");
	}


	return 0;
}
