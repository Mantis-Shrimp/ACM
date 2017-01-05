//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-4-29
// Description : 字符串 HASH
//============================================================================

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>



#define LEN 1000000
#define MAX (1000000)


int n ,ret ,nc,len,hash[MAX];
char in[LEN];
int map[LEN];

int main(int argv , char* argc[])
{
	int j = 0;
	int r = 0;
	while(scanf("%d %d\n",&n,&nc)!=EOF)
	{
		ret = 0;
		scanf("%s",in);
		memset(hash,0,sizeof(hash));
		len = strlen(in);
		j = 0;

		for(int i = 0 ; i < len ; ++i)
		{
			if(map[in[i]]==0)
				map[in[i]] = ++j;
			if(j==nc) break;
		}

		for(int i = 0 ; i + n <= len ; ++i)
		{
			r = 0;

			for(j = 0 ; j < n ; ++j)
				r = r * nc + (map[in[i+j]]-1);

			if(hash[r]==0)
			{
				ret++,hash[r]++;
//				printf("%s\n", in+i);
			}
		}
		printf("%d\n",ret);
	}
}