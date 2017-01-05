//============================================================================
// Name        : POJ_1159.cpp
// Author      : 
// Version     :
// Copyright   : 2012-6-12
// Description : Palindrome 回文数       滚动数组优化过的DP
//============================================================================
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 5005
char s0[LEN];
int DP[2][LEN],r,len;

int main()
{
	scanf("%d\n%s",&len,s0+1);
	memset(DP,0,sizeof(DP));
	for(int i = 1 ; i<=len ; i++)
		for(int j = 1 ; j<=len ; j++)
			if(s0[len+1-j]==s0[i])
				DP[i%2][j]=DP[(i-1)%2][j-1]+1;
			else
				if(DP[(i-1)%2][j]>DP[i%2][j-1])
					DP[i%2][j]=DP[(i-1)%2][j];
				else
					DP[i%2][j]=DP[i%2][j-1];
	printf("%d\n",len-DP[len%2][len]);
	return 0;
}
