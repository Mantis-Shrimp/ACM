//============================================================================
// Name        : POJ_2365.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <math.h>

int num = 0;
double len = 0;
double r = 0 ;
double Xend = 0 ;
double Yend = 0 ;
double x = 0 ;
double y = 0 ;
double x_1 = 0 ;
double y_1 = 0 ;

double distance(double x0,double y0,double x1,double y1);

int main()
{
	scanf("%d %lf\n",&num,&r);
	scanf("%lf %lf\n",&Xend,&Yend);
	x = Xend;
	y = Yend;
	if(num==1)
	{
		printf("%.2f\n",2* 3.141592653 * r );
		return 0 ;
	}
	for(int i = 2 ; i <= num ; i++)
	{
	    scanf("%lf %lf\n",&x_1,&y_1);
	    len+= distance(x,y,x_1,y_1);
	    x = x_1 ,y = y_1 ;
	}
	len += distance(Xend,Yend,x_1,y_1);
	len += 2* 3.141592653 * r ;
	printf("%.2f\n",len);
	return 0;
}


double distance(double x0,double y0,double x1,double y1)
{
	return sqrt((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1));
}
