#include <stdio.h>
#include <string.h>

#define DIGIT 4
#define DEPTH 10000
#define MAX   100
typedef int bignum_t[MAX];



int read(bignum_t a);
int write(const bignum_t a);
int add(bignum_t a,const bignum_t b);

bignum_t a;
bignum_t b;

int main(int argc, char **argv)
{
	//printf("hello world\n");
	read(a);
	read(b);
	while(!(b[0]==1&&b[1]==0))
	{
	add(a,b);
	read(b);
	}
	write(a);
	return 0;
}

int read(bignum_t a)
{
	char buf[MAX*DIGIT+1],ch;
	int i,j;
	scanf("%s",buf);
	memset((void*)a,0,sizeof(bignum_t));

	for(a[0]=strlen(buf),i=a[0]/2-1;i>=0;i--)
		ch=buf[i],buf[i]=buf[a[0]-1-i],buf[a[0]-1-i]=ch;
	for(a[0]=(a[0]+DIGIT-1)/DIGIT,j=strlen(buf);j<a[0]*DIGIT;buf[j++]='0');
	for(i= 1;i<=a[0];i++)
		for(a[i]=0,j=0;j<DIGIT;j++)
			a[i]=a[i]*10+buf[i*DIGIT-1-j]-'0';
	for(;!a[a[0]]&&a[0]>1;a[0]--);
	return 1;
}

int write(const bignum_t a)
{
	int i,j;
	printf("%d",a[i=a[0]]);
	for(a[i=a[0]],i--;i;i--)
		for(j=DEPTH/10;j;j/=10)
			printf("%d",a[i]/j%10);
	printf("\n");
}

int add(bignum_t a,const bignum_t b)
{
	int i;
	for(i = 1; i<=b[0];i++)
		if((a[i]+=b[i])>=DEPTH)
			a[i]-=DEPTH,a[i+1]++;
	if(b[0]>=a[0])
		a[0]=b[0];
	else
		for(;a[i]>=DEPTH&&i<a[0];a[i]-=DEPTH,i++,a[i]++);
		a[0]+=(a[a[0]+1]>0);
}

