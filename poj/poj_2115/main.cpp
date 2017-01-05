#include <stdio.h>

long long A,B,C,K;
long long a,b,n;
long long x,y;
long long gcd;

long long ext_gcd(long long a,long long b,long long& x,long long& y);

int main(int argc, char **argv)
{
	scanf("%I64d%I64d%I64d%I64d",&A,&B,&C,&K);
	while(A|B|C|K)
	{
		a = C ;
		b = B - A ;
		n = (long long)1 << K ;
		gcd = ext_gcd(a,n,x,y);
		if(b%gcd==0)printf("%I64d\n",(((x*(b/gcd))%n)+n)%(n/gcd));
		else printf("FOREVER\n");
		scanf("%I64d%I64d%I64d%I64d",&A,&B,&C,&K);
	}
	return 0;
}

long long ext_gcd(long long a,long long b,long long& x,long long& y)
{
	long long t,ret;
	if(!b)
		{
			x=1,y=0;
			return a;
		}
	ret=ext_gcd(b,a%b,x,y);
	t=x,x=y,y=t-a/b*y;
	return ret;
}
