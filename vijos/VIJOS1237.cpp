//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-6-3
// Description : 二分查找
//============================================================================

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>


#define N 40000
#define G 0.6180339887498949

using namespace std;


int n;
double wing[N];
int a,b;
double r;



//二分查找求下界
int lower_bound(double* arr, int lhs, int rhs, double value)
{
    int m;
    while(lhs < rhs)
    {
        m = lhs + (rhs - lhs) / 2;
        if(arr[m] >= value)
            rhs = m;
        else
            lhs = m + 1;
    }
    return lhs;
}

//二分查找求上界
int upper_bound(double* arr, int lhs, int rhs, double value)
{
    int m;
    while(lhs < rhs)
    {
        m = lhs + (rhs - lhs) / 2;
        if(arr[m] <= value)
            lhs = m + 1;
        else
            rhs = m;
    }
    return lhs;
}


//二分查找求小于等于某个数的最大数
double lessthan_or_equalto(double* arr, int lhs, int rhs, double value)
{
    int tmp = lower_bound(arr, lhs, rhs, value);
    if(arr[tmp] > value)
        tmp--;
    return arr[tmp];
}

//二分查找求大于某个数的最小数
double greaterthan(double* arr, int lhs, int rhs, double value)
{
    int tmp = upper_bound(arr, lhs, rhs, value);
    return arr[tmp];
}


int main()
{
	double temp;
	double tempb;
	r = 10e20;
	scanf("%d",&n);
	
	for(int i = 0 ; i < n ; ++i)
		scanf("%lf",&wing[i]);

	sort(wing,wing+n,less<double>() );


	for(int i = 0 ; i < n ; ++i)
	{
		temp = wing[i] / G;
		
		tempb = lessthan_or_equalto(wing,0,n,temp);

		if(tempb!=0)
		if( fabs(r - G) - fabs(wing[i]/tempb - G) >  0.0000000001  )
			a = wing[i],
			b = tempb,
			r = wing[i]/tempb;

		tempb = greaterthan(wing,0,n,temp);

		if(tempb!=0)
		if( fabs(r - G) - fabs(wing[i]/tempb - G) >  0.0000000001 )
			a = wing[i],
			b = tempb,
			r = wing[i]/tempb;
	}
	//cout<<a<<endl<<b<<endl;
	printf("%d\n%d",a,b);
	return 0;
}