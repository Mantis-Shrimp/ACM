#include <stdio.h>


int n,m,c;
int devpow[200];
int ope;
int sumpow;
int maxpow;
int count = 0;
int flag = 0 ;

int main(int argc, char **argv)
{
	scanf("%d%d%d",&n,&m,&c);
	while(m!=0||n!=0||c!=0)
	{
		flag = 0 ,maxpow = 0,count++,sumpow=0;
		for(int i = 0 ; i < n; i++) scanf("%d",devpow+i);
		for(int j = 0 ; j < m; j++)
		{
			scanf("%d",&ope) ;
			if(flag==1) continue ;
			sumpow += devpow[ope-1];
			devpow[ope-1]=- devpow[ope-1];
			if(sumpow > c) {printf("Sequence %d\nFuse was blown.\n",count);flag = 1;}
			if(sumpow > maxpow) maxpow = sumpow;
		}
		if(flag==0)printf("Sequence %d\nFuse was not blown.\nMaximal power consumption was %d amperes.\n",count,maxpow);
	printf("\n");
	scanf("%d%d%d",&n,&m,&c);
	}
	return 0;
}
