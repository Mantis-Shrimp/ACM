//============================================================================
// Name        : POJ_2524. cpp
// Author      :
// Version     :
// Copyright   : 2012-7-19
// Description : ²¢²é¼¯
//============================================================================
#include <cstdio>
#define N 50005
int findroot(int index);
int iCase,F[N],n,m,r;
int stu0,stu1,f0,f1;

int main()
{
	iCase=0;
	while(scanf("%d%d",&n,&m)&&n+m!=0)
	{
		iCase++,r=0;
		for(int i = 1 ; i <= n ; i++) F[i] = i ;
		for(int i = 1 ; i <= m ; i++) 
		{
			scanf("%d%d",&stu0,&stu1);
		        f0 = findroot(stu0), f1 = findroot(stu1);
		        if(f0 != f1) F[f1] = f0;
		}
		for(int i = 1 ; i <= n ; i++)
			if(F[i] == i) r++;
		printf("Case %d: %d\n",iCase,r);
	}
}

int findroot(int index)
{
	if(F[index]==index)
	{
		return index;
	}
	else
	{
		F[index] =findroot(F[index]);
		return F[index];
	}
}
