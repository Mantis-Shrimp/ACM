//============================================================================
// Name        : POJ_1163.cpp
// Author      : 
// Version     :
// Copyright   : 2012-5-2
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define LEN 200

int N;
int tri[LEN][LEN];
int DP[LEN][LEN];

int main()
{
	scanf("%d\n",&N);

	for(int iH = 1 ; iH <= N ; iH++)
		for(int iW = 1 ; iW <= iH ; iW++)
			scanf("%d",&tri[iH][iW]),DP[iH][iW] = INT_MIN;

	for(int iW = 1 ; iW <= N ; iW++) DP[N][iW] = tri[N][iW];

	for(int iH = N-1 ; iH >= 1 ; iH--)
			for(int iW = 1 ; iW <= iH ; iW++)
				if(tri[iH][iW]+DP[iH+1][iW]>tri[iH][iW]+DP[iH+1][iW+1]) DP[iH][iW] = tri[iH][iW]+DP[iH+1][iW];
				else DP[iH][iW] = tri[iH][iW]+DP[iH+1][iW+1];
	printf("%d\n",DP[1][1]);
	return 0;
}
