//============================================================================
// Name        : VIJOS1007. cpp
// Author      :
// Version     :
// Copyright   : 2013-3-23
// Description : 模拟
//============================================================================

#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#define N (100+5)
#define PI 3.141592653


using namespace std;

int n;
double r,c;
double x[N],y[N];


inline double dis(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(int argc, char const *argv[])
{
	cin>>n>>r;
	c = 0;

	for(int i = 0 ; i < n ; i++)
	{
		cin>>x[i]>>y[i];
	}

	for(int i = 0 ; i < n ; i++)
	{
		c +=dis(x[i],y[i],x[(i+1)%n],y[(i+1)%n]);
	}
	printf("%0.2f\n", c+2*PI*r);
	return 0;
}