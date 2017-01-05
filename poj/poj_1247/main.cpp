#include <stdio.h>

int N = 0 ;
int guests[35] ;
int ella = 0 ;
int sam = 0 ;


int main(int argc, char **argv)
{
	scanf("%d",&N);
	while(N!=0)
	{
		for(int i = 0 ; i < N ; i++) scanf("%d",&guests[i]);

		for(int i = 0 ; i < N ; i++)
		{
			ella = 0 , sam = 0 ;
			for(int isam = 0 ; isam < i ; isam ++) sam+=guests[isam];
			for(int iella = i ; iella < N ; iella ++) ella+=guests[iella];
			if(sam==ella) {printf("Sam stops at position %d and Ella stops at position %d.\n",i,i+1);break;}
			else
				if(sam>ella) {printf("No equal partitioning.\n");break;}
		}
		scanf("%d",&N);
	}
	return 0;
}
