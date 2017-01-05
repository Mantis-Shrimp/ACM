//============================================================================
// Name        : POJ_1017.cpp
// Author      : 
// Version     :
// Copyright   : 2012-6-12
// Description : Packets  สýังฬโ
//============================================================================

#include <stdio.h>
#include <stdlib.h>

int num[]={0,5,3,1};

int main()
{
	int a,b,c,d,e,f,x,y,N;
	scanf("%d%d%d%d%d%d\n",&f,&e,&d,&c,&b,&a);
	while(a+b+c+d+e+f!=0)
	{
		N=a+b+c+(d+3)/4;
		y = 5 * c + num[d%4];
		if(y<e) N+=(e-y+8)/9;
		x = 36*N-36*a-25*b-16*c-9*d-4*e;
		if(x<f) N+=(f-x+35)/36;
		printf("%d\n",N);
    	scanf("%d%d%d%d%d%d\n",&f,&e,&d,&c,&b,&a);
	}
	return 0;
}
