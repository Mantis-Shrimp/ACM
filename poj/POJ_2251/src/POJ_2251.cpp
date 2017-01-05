//============================================================================
// Name        : POJ_2251.cpp
// Author      : 
// Version     :
// Copyright   : 2012-7-10
// Description : Dungeon Master BFS —≠ª∑∂”¡–
//============================================================================
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAX 35
#define QMAX 100000
char dungeon[MAX][MAX][MAX],flag[MAX][MAX][MAX];
int L,R,C,il,ir,ic,n;
typedef struct
{
	int il;
	int ir;
	int ic;
	int num;
} e;
e queue[QMAX],e0,e1;
int front,rear;

int BFS();

int main()
{
	while(scanf("%d%d%d",&L,&R,&C)&&(L+R+C!=0))
	{
		getchar();
		n = -1,il = -1 ,ir = -1 ,ic = -1,memset(flag,0,sizeof(flag));
		for(int iL = 0 ; iL < L ; iL++)
		{
			for(int iR = 0 ; iR < R ; iR++)
			{
				for(int iC = 0 ; iC < C ; iC++)
				{
					scanf("%c",&dungeon[iL][iR][iC]);
					if(dungeon[iL][iR][iC]=='S')il=iL,ir=iR,ic=iC,flag[iL][iR][iC]=1;;
				}
				getchar();
			}
			getchar();
		}
		BFS();
		if(n==-1) printf("Trapped!\n");
	}
	return 0;
}

int BFS()
{
	e0.ic = ic, e0.ir = ir, e0.il = il,e0.num = 0;
	front = 0,rear=0;
	queue[rear] = e0,rear = (rear + 1)%QMAX;

	while(front!=rear)
	{

		//for(int i = front ; i < rear ; i++) printf("%d %d %d\n",queue[i].il,queue[i].ir,queue[i].ic);
		//printf("\n");


		e1 = queue[front];
		if(e1.ic==3)
			e0.ic++;
		if((e1.il-1>=0 && e1.il - 1 <L)&&flag[e1.il-1][e1.ir][e1.ic]==0&&dungeon[e1.il-1][e1.ir][e1.ic]!='#')
		{
			if(dungeon[e1.il-1][e1.ir][e1.ic]=='E') {printf("Escaped in %d minute(s).\n",e1.num+1);n=1;return 0;}
			e1.num++,flag[e1.il-1][e1.ir][e1.ic]=1;
			e1.il--;
			queue[rear]=e1,rear = (rear + 1) % QMAX;

		}
		e1 = queue[front];
		if((e1.il+1>=0 && e1.il + 1 <L)&&flag[e1.il+1][e1.ir][e1.ic]==0&&dungeon[e1.il+1][e1.ir][e1.ic]!='#')
		{
			if(dungeon[e1.il+1][e1.ir][e1.ic]=='E') {printf("Escaped in %d minute(s).\n",e1.num+1);n=1;return 0;}
			e1.num++,flag[e1.il+1][e1.ir][e1.ic]=1;
			e1.il++;
			queue[rear]=e1,rear = (rear + 1) % QMAX;
		}
		e1 = queue[front];
		if((e1.ir-1>=0 && e1.ir - 1 <R)&&flag[e1.il][e1.ir-1][e1.ic]==0&&dungeon[e1.il][e1.ir-1][e1.ic]!='#')
		{
			e1 = queue[front];
			if(dungeon[e1.il][e1.ir-1][e1.ic]=='E') {printf("Escaped in %d minute(s).\n",e1.num+1);n=1;return 0;}
			e1.num++,flag[e1.il][e1.ir-1][e1.ic]=1;
			e1.ir--;
			queue[rear]=e1,rear = (rear + 1) % QMAX;

		}
		e1 = queue[front];
		if((e1.ir+1>=0 && e1.ir + 1 <R)&&flag[e1.il][e1.ir+1][e1.ic]==0&&dungeon[e1.il][e1.ir+1][e1.ic]!='#')
		{
			e1 = queue[front];
			if(dungeon[e1.il][e1.ir+1][e1.ic]=='E') {printf("Escaped in %d minute(s).\n",e1.num+1);n=1;return 0;}
			e1.num++,flag[e1.il][e1.ir+1][e1.ic]=1;
			e1.ir++;
			queue[rear]=e1,rear = (rear + 1) % QMAX;

		}
		e1 = queue[front];
		if((e1.ic-1 >=0 && e1.ic - 1 <C)&&flag[e1.il][e1.ir][e1.ic-1]==0&&dungeon[e1.il][e1.ir][e1.ic-1]!='#')
		{
			e1 = queue[front];
			if(dungeon[e1.il][e1.ir][e1.ic-1]=='E') {printf("Escaped in %d minute(s).\n",e1.num+1);n=1;return 0;}
			e1.num++,flag[e1.il][e1.ir][e1.ic-1]=1;
			e1.ic--;
			queue[rear]=e1,rear = (rear + 1) % QMAX;

		}
		e1 = queue[front];
		if((e1.ic+1 >=0 && e1.ic + 1 <C)&&flag[e1.il][e1.ir][e1.ic+1]==0&&dungeon[e1.il][e1.ir][e1.ic+1]!='#')
		{
			e1 = queue[front];
			if(dungeon[e1.il][e1.ir][e1.ic+1]=='E') {printf("Escaped in %d minute(s).\n",e1.num+1);n=1;return 0;}
			e1.num++,flag[e1.il][e1.ir][e1.ic+1]=1;
			e1.ic++;
			queue[rear]=e1,rear = (rear + 1) % QMAX;
		}
		front = (front+1) % QMAX;
	}

	return 1;
}
