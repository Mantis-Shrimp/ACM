//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-4-4
// Description : kmp
//============================================================================
#include <cstdio>
#include <cstring>

#define LEN (1000000+10)


char S[LEN];
int next[LEN];
int slen;



int getnext()
{
	int i = 0;
	int j = -1;
	next[0]=-1;
	while(i <= slen)
	{
		if(j==-1||S[i]==S[j])
			next[++i] = ++j;
		else
			j=next[j];
	}
	return 0;
}


int main()
{
	freopen("in.txt","r",stdin);
	freopen("fuck.txt","w",stdout);
	int flag = -1;
	int pos = 0;
	int i = 0;
	gets(S);
	while(S[0]!='.')
	{
		slen = strlen(S);
		getnext();
		flag = -1; 
		i = 0;
		while(i<=slen)
		{		
			if(next[i]==1&&flag==-1)
			{
				flag = 2;
				pos = i-1;
			}
			if(next[i]==1&&flag!=-1)
			{
				flag = 2;
				pos = i-1;
			}
			if(next[i]!=1&&flag==-1)
			{
				flag=-1;
			}
			if(next[i]!=1&&flag!=-1)
			{
				if(next[i]==flag)flag++;
				else flag=-1;
			}
			i++;
		}
		if(flag>=2&&slen%pos==0&&(flag-1)%pos==0)
			printf("%d\n",slen/pos);
		else
			printf("1\n");
		gets(S);
	}
	return 0;
}