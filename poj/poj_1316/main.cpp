#include <stdio.h>
#include <string.h>

char num[10000] = {1};
int sum = 0 ;
int sum0 = 0 ;


int main(int argc, char **argv)
{
	//printf("hello world\n");
	freopen("out.txt","w",stdout);
	memset(num,1,10000*sizeof(char));
	for(int i = 1 ; i <= 10000 ; i ++)
	{
		//printf("i = %d\n",i);
		sum = i ;
		sum0 = sum ;
		while(sum <= 10000)
		{
			sum0 = sum ;
			do
			{
				sum += sum0%10;

			}
			while(sum0/=10);
			//printf("sum=%d..\n",sum);
			if(sum<=10000)num[sum-1] = -1;
		}
	}
	for(int i = 0 ; i < 10000 ; i ++) if(num[i]==1) printf("%d\\n",i+1);
	return 0;
}
