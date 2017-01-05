#include <stdio.h>
#include <time.h>

int data[14]= {0};


int main(int argc, char **argv)
{
	int result = 0;
	int k = 0;
	for(k = 1; k<=13; k++)
	{
		for(int _try=k; 1; _try++)
		{
			int cur = 0 ;
			int len = 2 * k;
			while(len >= k)
			{
				cur = ((cur - 1) + _try) % len;
				if(cur <= k-1) break;
				len -- ;
			}
			if(len==k)
			{
				data[k] = _try;
				break;
			}
		}
	}


	scanf("%d",&k);
	while(k!=0)
	{
		printf("%d\n",data[k]);
		scanf("%d",&k);
	}

	return 0;
}
