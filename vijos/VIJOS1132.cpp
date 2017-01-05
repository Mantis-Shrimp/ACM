//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-3-27
// Description : 数据结构
//============================================================================

#include <cstdio>
#include <cstring>

#define LEN 20


char a[LEN],b[LEN];
int alen,blen;


int find(char str[],char a,int s,int e)
{
	for (int i = s; i <= e; ++i)
		if(str[i]==a) return i;
	return -1;
}

int DFS(int s1,int e1,int s2,int e2)
{
	
	int mid;
	if(s1==e1&&s2==e2)
	{
		printf("%c",a[s1]);
		return 0;
	}
	else
	{
		mid = find(a,b[e2],s1,e1);
		if(mid==-1) return 0;
		printf("%c",a[mid]);
		DFS(s1,mid-1,s2,s2+(mid-1-s1));
		DFS(mid+1,e1,s2+(mid-1-s1)+1,s2+(mid-1-s1)+1+e1-(mid+1));
	}
}

int main(int argc, char const *argv[])
{
	scanf("%s",a);
	scanf("%s",b);
	alen = strlen(a);
	blen = strlen(b);
	DFS(0,alen-1,0,blen-1);
	return 0;
}