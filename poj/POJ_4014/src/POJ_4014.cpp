//============================================================================
// Name        : POJ_4014.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<stdio.h>
#include<algorithm>
using namespace std;

struct node
{
int a;
int b;
int c;
} seq[1500];

int n;
double E;


bool _great(node a,node b);
bool __great(node a,node b);

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		E = 0 ;
		for(int i = 0 ; i < n ; scanf("%d",&(seq[i].b)),seq[i].a=i,seq[i].c=0,i++);
		sort(seq,seq + n,_great);
		for(int i = 0 ; i < n ; i++)
		{
			//seq[i].c = 0;
			if(i!=0) seq[i].c = seq[i-1].c;
			for(int j = 1 ; j <= seq[i].b; j++)
			{
				seq[i].c++;
				E += (1.0 / seq[i].b * seq[i].c );
			}
		}
		sort(seq,seq+n,__great);
		printf("%.5f\n",E);
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = seq[i].b -1 ; j >= 0 ; j-- )
			printf("%d ",seq[i].c - j);
			printf("\n");
		}
	}
}


bool _great(node a,node b)
{
	return a.b > b.b;
}

bool __great(node a,node b)
{
	return a.a < a.a;
}
