//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-4-4
// Description : kmp
//============================================================================
#include <cstdio>
#include <cstring>

#define MM (10000+10)
#define TT (1000000+10)


char S[TT],T[MM];
int next[MM];
int t,Tlen,Mlen;




int getnext()
{
	int i = 0;
	int j = -1;
	next[0] = -1;
	
	while(i <= Tlen)
	{
		if(j==-1||T[j]==S[i])
		{
			j++;
			i++;
			next[i] = j; 
		}
		else
		{
	 		j = next[j];
		}
	} 
	
	return 0;
}


int KMP()
{
	int ret = 0;
	int i = 0;
	int j = 0;
	while(i<Mlen)
	{
		if(j==-1||S[i]==T[j])
		{
			if(S[i]==T[j]&&j==Tlen-1) ret++;
			j++;
			i++;
		}
		else
		{
			j = next[j];
		}
	}
	return ret;
}


int main()
{
	freopen("in.txt","r",stdin);
	int sol;
	scanf("%d\n",&t);
	while(t--)
	{
		sol = 0;
		gets(T);
		gets(S);
		Tlen = strlen(T);
		Mlen = strlen(S);
		getnext();
		sol = KMP();
		printf("%d\n",sol); 
	}
}
