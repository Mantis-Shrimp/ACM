//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-4-27
// Description : hash
//============================================================================
//#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

#define  BASE 500000

using namespace std;

int flag[2*BASE+10];

int m,n;
int temp;




int main(int arg,char* argv[])
{
    
	int j;
	int k;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		j = 2*BASE+9;
		k = 0;
		memset(flag,0,sizeof(flag));
		for(int i = 1 ; i <= n ;++i)
		{
			scanf("%d",&temp);
			flag[temp+BASE]++;
		}

		while(1)
		{
			if(flag[j--]!=0)
			{
				if(k==0)
				{
					printf("%d",j+1-BASE);
					k = 1;
				}
				else
				{
					printf(" %d", j+1-BASE);
				}        
				m--;
			}
			if(m==0) break;
		}
		printf("\n");
	}
	return 0;
}