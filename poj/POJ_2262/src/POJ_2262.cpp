//============================================================================
// Name        : POJ_2262.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <math.h>

int num = 0 ;
int end = 0 ;
int a = 0 ;
int b = 0 ;
int flag = 0;
int IsPrim(int num);
int main()
{
    scanf("%d",&num);
    while(num!=0)
    {
    	end = num / 2  ;
    	flag = 0 ;
    	for(int i = 2 ; i<=end ; i++)
    	{
    		if(IsPrim(i)&&IsPrim(num-i))
    			{
    			    printf("%d = %d + %d\n",num,i,num-i);
    			    flag = 1;
    			    break;
    			}
    	}
    	if(flag==0) printf("Goldbach's conjecture is wrong.\n");
    	scanf("%d",&num);
    }
	return 0;
}

int IsPrim(int num)
{
	int end = (int)sqrt((double)num) + 1;
	for(int i = 2 ; i <=end ; i++)
	{
		if(num%i==0) return 0;
	}
	return 1;
}
