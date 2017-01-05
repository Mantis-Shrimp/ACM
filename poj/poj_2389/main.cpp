#include <stdio.h>
#include <string.h>

#define DIGIT 4
#define DEPTH 10000
#define MAX 10000
typedef int bignum_t[MAX+1];

int read(bignum_t a,char buf[]);
int write(bignum_t a);
void mul(bignum_t c,const bignum_t a,const bignum_t b);


bignum_t a;
bignum_t b;
bignum_t c;
char abuf[MAX*DIGIT+1];
char bbuf[MAX*DIGIT+1];

int main(int argc, char **argv)
{
	scanf("%s %s" ,abuf ,bbuf);
	read(a,abuf);
	read(b,bbuf);
	mul(c,a,b);
	write(c);
	return 0;
}

int read(bignum_t a,char buf[])
{
	char ch;
	int i,j;
	memset((void*)a,0,sizeof(bignum_t));
	for(a[0]=strlen(buf),i=a[0]/2-1;i>=0;i--)
		ch=buf[i],buf[i]=buf[a[0]-1-i],buf[a[0]-1-i]=ch;
	for(a[0]=(a[0]+DIGIT-1)/DIGIT,j=strlen(buf);j<a[0]*DIGIT;buf[j++]='0');
	for(i=1;i<=a[0];i++)
		for(a[i]=0,j=0;j<DIGIT;j++)
			a[i]=a[i]*10+buf[i*DIGIT-1-j]-'0';
	for(;!a[a[0]]&&a[0]>1;a[0]--);
	return 1;
}



int write(bignum_t a)
{
	int i,j;
	printf("%d",a[i=a[0]]);
	for(a[i=a[0]],i--;i;i--)
		for(j=DEPTH/10;j;j/=10)
			printf("%d",a[i]/j%10);
	printf("\n");
	return 1;
}


void mul(bignum_t c,const bignum_t a,const bignum_t b)
{
	int i,j;
	memset((void*)c,0,sizeof(bignum_t));
	for(c[0]=a[0]+b[0]-1,i=1;i<=a[0];i++)
		for(j=1;j<=b[0];j++)
			if((c[i+j-1]+=a[i]*b[j])>=DEPTH)
				c[i+j]+=c[i+j-1]/DEPTH,c[i+j-1]%=DEPTH;
	for(c[0]+=(c[c[0]+1]>0);!c[c[0]]&&c[0]>1;c[0]--);
}
