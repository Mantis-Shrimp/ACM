#include <stdio.h>

long long sequeue[5];
long long ratio[3];
long long difference[3];
int count = 0 ;

int main(int argc, char **argv)
{
	scanf("%d",&count);
	while(count--)
	{
		for(int i = 0 ; i < 4 ; i++) scanf("%I64d",&sequeue[i]);
		for(int i = 0 ; i < 3 ; i++) difference[i] = sequeue[i+1] - sequeue[i];
		if(difference[0]==difference[1]&&difference[1]==difference[2])
		{
			for(int i = 0 ; i < 4 ; i++) printf("%I64d ",sequeue[i]); printf("%I64d\n",sequeue[3] + difference[0]);
		}
		else
		{
			for(int i = 0 ; i < 4 ; i++) printf("%I64d ",sequeue[i]); printf("%I64d\n",(sequeue[3]*sequeue[1]) / sequeue[0]);
		}
	}
	return 0;
}
