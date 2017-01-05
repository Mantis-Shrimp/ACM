//============================================================================
// Name        : UVa_10038. cpp
// Author      :
// Version     :
// Copyright   : 2013-12-21 
// Description : simple
//============================================================================
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int N = 350000;
int queue[N],flag[N],result,n;
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		memset(flag,0,sizeof(flag));
		result = 0;
		for(int i = 0 ; i < n ; i++)
			scanf("%d",&queue[i]);
		for(int i = 0 ; i < n ; i++)
			flag[abs(queue[i + 1] - queue[i])] = 1;
		for(int i = 1 ; i < n ; i++)
			if(flag[i]==0) result = 1;
		if(result==0) printf("Jolly\n");
		else printf("Not jolly\n");	
	}
	return 0;
}