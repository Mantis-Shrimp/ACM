//============================================================================
// Name        : POJ_1222.cpp
// Author      : 
// Version     :
// Copyright   : 2012-5-2
// Description : http://poj.org/problem?id=1222 œ®µ∆Œ Ã‚   √∂æŸ
//============================================================================

#include <stdio.h>
#include <string.h>

int DFS(int depth);
int output();
bool check();

int t;
int T;
char puzzle[7][8];
char press[7][8];


int main()
{

	scanf("%d\n",&t);
	T=t;
	while(t--)
	{
		memset(puzzle,0,sizeof(char)*7*8);
		memset(press,0,sizeof(char)*7*8);
		for(int ih = 1 ; ih <=5 ; ih++)
				for(int iw = 1 ; iw <= 6; iw++)
					scanf("%d",&puzzle[ih][iw]);
		DFS(1);
	}
	return 0;
}

int DFS(int depth)
{
	if(depth==7)
	{
		if(check()) {output(); return 0;}
		else return 0;
	}
	for(int i = 0 ; i<=1 ; i++) press[1][depth]=i,DFS(depth+1);
	return 0;
}

bool check()
{
	for(int ih = 2 ; ih<=6 ; ih++)
	{
		for(int iw = 1 ; iw<=6 ; iw++)
		{
			press[ih][iw] = (puzzle[ih-1][iw] + press[ih-1][iw] + press[ih-1][iw-1] + press[ih-1][iw+1]
			                + press[ih-2][iw])%2;
		}
	}
	if(press[6][1]+press[6][2]+press[6][3]+press[6][4]+press[6][5]+press[6][6]==0) return true;
	else return false;
}

int output()
{
	printf("PUZZLE #%d\n",T-t);
	for(int ih = 1 ; ih <=5 ; ih++)
	{
		for(int iw = 1 ; iw <= 6; iw++)
		{
			printf("%d ",press[ih][iw]);
		}
		printf("\n");
	}
	return 0;
}
