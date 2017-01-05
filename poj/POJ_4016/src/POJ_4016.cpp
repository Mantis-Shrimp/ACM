//============================================================================
// Name        : POJ_4016.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<stdio.h>
#include<string.h>


int rooms[100];
int num;
int icost;
int temp;
int total;
int bed;
double cos;
char name[100];

int main()
{
	while(scanf("%d %d\n",&num,&icost)!=EOF)
	{
	   for(int i = 0 ; i <= 99 ; i++) rooms[i] = 0;
	   total = 0 ;
	   for(int i = 0 ; i <num ;i++)
	   {
		  scanf("%d %s",&temp,name);
		  rooms[name[0]+name[1]+name[2]-'a'-'a'-'a'] += temp ;
          total+=temp;
	   }
	   cos = icost * ( total - 0.5 * rooms['b'+'a'+'l'-3 * 'a']);
	   printf("%d\n",total);
	   printf("%d\n",rooms[8]);
	   if((float)((int)cos)==cos)printf("%d\n",(int)cos);
	   else printf("%.1f\n",cos);
   	}
}
