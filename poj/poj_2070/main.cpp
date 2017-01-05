#include<stdio.h>

double speed[3]={4.5,6.0,5.0};
int Wei[3]={150,300,200};
int Stre[3]={200,500,300};
char ch[3][100]={"Wide Receiver","Lineman","Quarterback"};
int flag = 0 ;
double S;
int W;
int RT;

int main()
{
	scanf("%lf%d%d",&S,&W,&RT);
	while(((int)S + W + RT)!=0)
	{
		flag = 0 ;
		for(int i = 0 ; i < 3 ; i++)
		if(S<=speed[i]&&W>=Wei[i]&&RT>=Stre[i])
		  flag = 1 ,printf("%s ",ch[i]);
		 if(flag !=1) printf("No positions");
		 putchar('\n');
		 scanf("%lf%d%d",&S,&W,&RT);
	}
}
