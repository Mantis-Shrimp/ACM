#include <stdio.h>

int rabbits[250][2];
int Max,cur_Max;
int count = 0 ;
int main(int argc, char **argv)
{
	scanf("%d",&count);
	while(count!=0)
	{
	Max = 0 ;
	for(int i = 0 ; i < count ; scanf("%d%d",&rabbits[i][0],&rabbits[i][1]),i ++ );

	for(int i = 0 ; i < count ; i ++)
	{
		for(int j = i + 1; j < count ; j++)
		{
			cur_Max = 0 ;
			for(int k = j + 1 ; k < count ; k++)
			{
				if(((rabbits[i][1]-rabbits[j][1])*(rabbits[i][0]-rabbits[k][0]))==((rabbits[i][1]-rabbits[k][1])*(rabbits[i][0]-rabbits[j][0])))
					cur_Max ++ ;
			}
			if(cur_Max > Max) Max = cur_Max ;
		}
	}
	printf("%d\n",Max + 2);
	scanf("%d",&count);
	}
	return 0;
}
