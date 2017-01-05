#include <stdio.h>
#include <stdlib.h>


int big_(const void* a,const void* b);
int less_(const void* a,const void* b);

int big[5];
int sma[5];
int r[5];
int temp ;
int count = 0 ;

int main(int argc, char **argv)
{
	freopen("io.txt","w",stdout);
	while(1)
	{
	    for(int i = 0 ; i < 4 ; i++)
		{
			scanf("%d",&temp);
			if(temp==-1)
				{return 0;}
			else{r[i] = temp ;}

		}
		printf("N=%d%d%d%d:\n",r[0],r[1],r[2],r[3]);
		count = 0 ;

		while(1)
		{
			count ++ ;
			for(int i = 0 ; i < 4 ;sma[i]=r[i],big[i]=r[i],i++);
			qsort(big,4,sizeof(int),big_);
			qsort(sma,4,sizeof(int),less_);
            printf("%d%d%d%d-%d%d%d%d=%d%d%d%d\n",big[0],big[1],big[2],big[3],sma[0],sma[1],sma[2],sma[3],r[0],r[1],r[2],r[3]);
			for(int i = 0 ; i < 4 ;r[i]=(big[i]-sma[i]),i++);
			if((r[0]+r[1]+r[2]+r[3])==0){printf("No!!\n"); break;}
			if(r[0]==6&&r[1]==1&&r[2]==7&&r[3]==4){printf("Ok!! %d times\n",count); break;}
		}
	}
}


int big_(const void* a,const void* b)
{
	return (*(int*)a) - (*(int*)b);
}

int less_(const void* a,const void* b)
{
	return (*(int*)b) - (*(int*)a);
}
