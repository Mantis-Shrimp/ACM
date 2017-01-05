//============================================================================
// Name        : POJ_1011.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<cstdio>
#include<algorithm>
#include<functional>
#include<string.h>
#include<time.h>
using namespace std;

int sticks[640];
int flag[640];
int sum[640];
int num;
int cou;
int LEN;

clock_t start,end;


bool _great(const int&,const int &);
int DFS(int co ,int len,int ii);

int main()
{
	freopen("in.txt","r",stdin);
    start = clock();
	scanf("%d",&num);
	while(num!=0)
	{
		memset(sum,0,640*sizeof(int));
		memset(flag,0,640*sizeof(int));
		for(int i = 0 ; i < num ; scanf("%d",sticks+i),i++);
		sort(sticks,sticks+num,_great);
		for(int i = num-1 ; i >=0 ; sum[i] = sum[i+1]+sticks[i],i--);

		for(int i = sticks[0] ; i <= sum[0] ; i++)
		{
			if(sum[0]%i==0)
			{
				cou = sum[0] / i ;
				LEN = i ;
				if(DFS(0,0,0)==1)
				break;
			}
		}
	scanf("%d",&num);

	}
	end = clock();
	printf("Run time: %lf S",(double)(end-start)/CLOCKS_PER_SEC);
}

bool _great(const int & a,const int &b)
{
	return a > b ;
}


int DFS(int co ,int len,int ii)
{

	int ilen = len ;
	int temp ;
	//if(depth==num) {for(int i = 0 ; i < num ; i++) printf("%d ",sticks[flag[i]-1]); printf("\n");}
	if(co==cou-1) {printf("%d\n",LEN);return 1;}
	for(int i = ii ; i < num ; i++)
	{
		temp = ilen + sticks[i];
		if(flag[i]==0&&temp<=LEN)
		{
			flag[i] = 1;
			 //printf("depth=%d co=%d sticks = %d\n",depth,co,sticks[i]);
			   if(temp==LEN)
			     {
				    if(DFS(co+1,0,0)) {flag[i]=0 ;return 1;}
				 }
			      else
                 {
				     if(DFS(co ,temp,i+1)){flag[i]=0 ; return 1;}
				 }
			flag[i] = 0;

			if(len ==0) return 0 ;
			//if(len==0&&i==ii) return 0;
			if(temp==LEN) return 0;
			if(ilen + sum[i]<LEN) return 0 ;
			while(sticks[i]==sticks[i+1]&&i+1<num)i++;
		}
	}
	return 0 ;
}
