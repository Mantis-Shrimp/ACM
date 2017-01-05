//============================================================================
// Name        : POJ_4012.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <string.h>

#define MAX(X,Y) (((X)>(Y))?(X):(Y))
#define MIN(X,Y) (((X)<(Y))?(X):(Y))


int m,n,s,k;
char chs[10000];
int flag;
int num = 0 ;
int len = 0 ;
int main()
	{
		//freopen("out.txt","r",stdin);
		//freopen("in.txt","w",stdout);
		while(scanf("%d%d%d%d\n",&m,&n,&s,&k)!=EOF)
		{
			gets(chs+1);
			len = strlen(chs+1),flag = 0 ;
			for(int i = 1 ; i <= len + 1; i++)
			{
				//printf(" %d  %c\n",flag,chs[i]);
				if(flag==0)
				{
					if(chs[i]==0)flag=0;if(chs[i]=='*')flag=1;if(chs[i]=='.')flag=-1;continue;
				}
				if(flag>=1&&flag<=s-1)
				{
					if(chs[i]==0)flag=-2;if(chs[i]=='*')flag++;if(chs[i]=='.')flag=-2;continue;
				}
				if(flag==s)
				{
					if(chs[i]==0)flag=-3;if(chs[i]=='*') flag=-2;if(chs[i]=='.') flag++;continue;
				}
				if(flag==s+1)
				{
					if(chs[i]==0)flag=-3;if(chs[i]=='*')flag=-2;if(chs[i]=='.')flag=s+1;continue;
				}
				if(flag==-1)
				{
					if(chs[i]==0)flag=-1;if(chs[i]=='*')flag=1;if(chs[i]=='.')flag=-1;continue;
				}
				if(flag==-2){continue;}if(flag==-3){continue;}
			}


			if(flag==-2) printf("Impossible\n");

			if(flag==-3) //printf("-3\n");
			{
				if(s==1||s==m||k==1||k==m) printf("Unique\n");
				else printf("Ambiguous\n");
			}

			if(flag==-1)
			{

			   if(
				  MAX(k-1,m-k)==s
				  &&MIN(k-1,m-k)<s
				  &&s==n
				  )
					printf("Unique\n");
				else
					if(MAX(k-1,m-k)<s)
						printf("Impossible\n");
					else
						printf("Ambiguous\n");
			}
	}
}
