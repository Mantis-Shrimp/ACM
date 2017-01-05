//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-4-4
// Description : kmp
//============================================================================
#include <stdio.h>


#define M (10000+10)
#define N (1000000+10)

int t,m,n;
int a[N],b[M];
int next[M]; 


int getNext()
{
	int i = 0;
	int j = -1;
	next[0] = -1;
	
	while(i<m)
	{
		if(j==-1||b[j]==b[i])
		{
			j++;
			i++;
			next[i]=j;
		}
		else
		{
			j = next[j];
		}
	} 
	return 0;
}


int kmp()
{
	int i = 0;
	int j = 0;
	while(i<n)
	{
		if(j==-1||a[i]==b[j])
		{
			if(j==m-1) return i-j+1;
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	return -1;
}


int main(int arg,char* argv[])
{
	int sol;
	int i;
//	freopen("in.txt","r",stdin);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i = 0 ; i < n ; i++)
			scanf("%d",&a[i]);
			
		for(i = 0; i < m ; i++)
			scanf("%d",&b[i]);
			
		getNext();
		sol = kmp();
		printf("%d\n",sol);	
	}
}
