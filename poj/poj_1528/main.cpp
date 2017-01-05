#include <stdio.h>


int N = 0 ;
int sum= 0 ;



int main(int argc, char **argv)
{
	//printf("hello world\n");
	printf("PERFECTION OUTPUT\n");
	scanf("%d",&N);
	while(N!=0)
	{
		sum = 0 ;
		for(int i = 1; i<N ; i++) if(N%i==0) sum +=i ;
		if(sum==N) printf("%5d  PERFECT\n",N);
		else if(sum>N) printf("%5d  ABUNDANT\n",N);
			 else      printf("%5d  DEFICIENT\n",N);
		scanf("%d",&N);
	}
	printf("END OF OUTPUT\n");
	return 0;
}
