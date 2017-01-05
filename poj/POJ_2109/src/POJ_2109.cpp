//============================================================================
// Name        : POJ_2109.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <math.h>
double n,m;
int main()
{
	while(scanf("%lf%lf",&n,&m)==2) printf("%.0lf\n",pow(m,1/n));
	return 0;
}
