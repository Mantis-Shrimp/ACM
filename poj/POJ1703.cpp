//============================================================================
// Name        : POJ1703
// Author      :
// Version     :
// Copyright   : 2012-7-18
// Description : 差统计量并查集
//============================================================================

#include <cstdio>
#include <cstring>
#define NMAX 100000+5

int val[NMAX],f[NMAX],x,y,ch;
int iCase,n,num,fx,fy;
int findroot(int index);
int main()
{
	scanf("%d",&iCase);
	while(iCase--)
	{
		scanf("%d%d",&n,&num);
		getchar();
		memset(val,0,sizeof(val));
		for(int i = 1 ; i <= n ; i++) f[i] = i ;
		while(num--)
		{
			scanf("%c %d %d",&ch,&x,&y);
			getchar();
			fx = findroot(x), fy = findroot(y);
			switch(ch)
			{
				case 'A':
					if(fx!=fy) printf("Not sure yet.\n");
					else
					if(val[x]==val[y])
						printf("In the same gang.\n");
					else
						printf("In different gangs.\n");
					break;
				case 'D':
					f[fx] = fy;
				        val[fx] = (1 + val[y] - val[x]) & 1;	
					break;
				default:
					break;
			}
		}
	}
}

int findroot(int index)
{
	int father = f[index];
	if(f[index]==index)
	{
		return index;
	}
	else
	{
		f[index] = findroot(f[index]);
		val[index] = (val[index]+ val[father]) % 2;
		return f[index];
	}
}
