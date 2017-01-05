#include <stdio.h>
#include <string.h>
#define DIGIT	4
#define DEPTH	10000
#define MAX     100
typedef int bignum_t[MAX+1];

int read(bignum_t a);
int comp(const bignum_t a,const bignum_t b);
void add(bignum_t a,const int b);
void add_(bignum_t a,const bignum_t b);
int comp_(const bignum_t a,const int b);

bignum_t a;
bignum_t b;
bignum_t fib[500]={0};
int istart = 0 ;
int iend = 0 ;





int main(int argc, char **argv)
{

	//freopen("pku1011.in","r",stdin);
	//freopen("pku1011.out","w",stdout);
	//add(fib[0],1);
	//add(fib[1],2);
	fib[0][0] = 1;
	fib[0][1] = 1;
	fib[1][0] = 1;
    fib[1][1] = 2;
	for(int iindex =2 ; iindex < 500 ; iindex++)
	{
		add_(fib[iindex],fib[iindex-1]);
		add_(fib[iindex],fib[iindex-2]);
	}
	read(a);
	read(b);
	while(comp_(a,0)!=0||comp_(b,0)!=0)
	{
		   for(istart = 0 ; istart <500 ;istart++)
		   {
			if(comp(a,fib[istart])<=0) break;
		   }

		   for(iend = 499 ;iend  > -1 ;iend--)
		   {
			  if(comp(b,fib[iend])>=0) break;
		   }
		   if(iend>=istart)
		   {
		        printf("%d\n",iend - istart + 1);
		   }
		   else
		   {
			   printf("0\n");
		   }
		read(a);
		read(b);
	}
	return 0;
}


int read(bignum_t a)
{
	char buf[MAX*DIGIT+1],ch;
	int i,j;
	scanf("%s",buf);
	memset((void*)a,0,sizeof(bignum_t));
	for (a[0]=strlen(buf),i=a[0]/2-1;i>=0;i--)
		ch=buf[i],buf[i]=buf[a[0]-1-i],buf[a[0]-1-i]=ch;
	for (a[0]=(a[0]+DIGIT-1)/DIGIT,j=strlen(buf);j<a[0]*DIGIT;buf[j++]='0');
	for (i=1;i<=a[0];i++)
		for (a[i]=0,j=0;j<DIGIT;j++)
			a[i]=a[i]*10+buf[i*DIGIT-1-j]-'0';
	for (;!a[a[0]]&&a[0]>1;a[0]--);
	return 1;
}


void add(bignum_t a,const int b)
{
	int i=1;
	for (a[1]+=b;a[i]>=DEPTH&&i<a[0];a[i+1]+=a[i]/DEPTH,a[i]%=DEPTH,i++);
	for (;a[a[0]]>=DEPTH;a[a[0]+1]=a[a[0]]/DEPTH,a[a[0]]%=DEPTH,a[0]++);
}

void add_(bignum_t a,const bignum_t b)
{
	int i;
	for (i=1;i<=b[0];i++)
		if ((a[i]+=b[i])>=DEPTH)
			a[i]-=DEPTH,a[i+1]++;
	if (b[0]>=a[0])
		a[0]=b[0];
	else
		for (;a[i]>=DEPTH&&i<a[0];a[i]-=DEPTH,i++,a[i]++);
	a[0]+=(a[a[0]+1]>0);
}

int comp(const bignum_t a,const bignum_t b)
{
	int i;
	if (a[0]!=b[0])
		return a[0]-b[0];
	for (i=a[0];i;i--)
		if (a[i]!=b[i])
			return a[i]-b[i];
	return 0;
}

int comp_(const bignum_t a,const int b)
{
	int c[12]={1};
	for (c[1]=b;c[c[0]]>=DEPTH;c[c[0]+1]=c[c[0]]/DEPTH,c[c[0]]%=DEPTH,c[0]++);
	return comp(a,c);
}


