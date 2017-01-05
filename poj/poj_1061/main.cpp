#include <stdio.h>
#include <iostream>
using namespace std;

long long ext_gcd(long long a,long long b,long long& x,long long& y);
long long x,y,m,n,l;
long long v,d;
long long x1,x2;
long long gcd;
int t = 0 ;
int mm = 0 ;


int main(int argc, char **argv)
{

	while(scanf("%I64d%I64d%I64d%I64d%I64d",&x,&y,&m,&n,&l)!=EOF)
	{
		t = 0 ;
		if(m>n)
			v=m-n,d=((y%l)-(x%l)+l)%l;
		else
			v=n-m,d=((x%l)-(y%l)+l)%l;
		gcd = ext_gcd(v,l,x1,x2);
		if(d%gcd!=0) {printf("Impossible\n");}
		else
		{
			    printf("%I64d\n",((d / gcd * x1 ) %l +l)%(l/gcd));
		}
	}
	return 0;
}

long long ext_gcd(long long a,long long b,long long& x,long long& y)
{
	long long t,ret;
	if(!b){x=1,y=0;return a;}
	ret=ext_gcd(b,a%b,x,y);
	t = x,x=y,y=t-a/b*y;
	return ret;
}
