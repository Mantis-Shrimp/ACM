#include <cstdio>
#include <cstring>
#define MAX 100
int N,top;
char in[MAX],out[MAX],flag[MAX],stack[MAX];

int main()
{
	int enter = 0,exit = 0,e = 0,top = -1;
	//freopen("HDU1022.in","r",stdin);
	while(scanf("%d%s%s",&N,in,out)!=EOF)
	{
		//printf("%d %s %s\n",N,in,out);
	        enter = 0,exit = 0,e = 0,top = -1;	
		while(enter!=N+1&&exit!=N)
		{
			//for(int i = top ; i>=0 ; i--) printf("%c ",stack[i]);
			//printf("\n");

			if(top!=-1 && stack[top]==out[exit])
			{
				top--;
				exit++;
				flag[++e] = 0 ;
			}
			else
			{
				stack[++top] = in[enter];
				enter++;
				flag[++e] = 1 ;
			}

		}
			if(exit==N)
			{
				printf("Yes.\n");
				for(int i = 1 ; i <=e ; i++)  if(flag[i]==1) printf("in\n"); else printf("out\n");
			}
			else
			{
				printf("No.\n");
			}
			printf("FINISH\n");
	}
}
