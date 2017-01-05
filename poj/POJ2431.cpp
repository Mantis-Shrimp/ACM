//poj3629 Card Stacking
//2012-7-16
//—≠ª∑∂”¡–

#include<stdio.h>
#include<string.h>
#define MAX 150000
int N,K,P;
int queue[MAX],head,rear,count,temp;
char flag[MAX];

int main()
{
	while(scanf("%d%d%d",&N,&K,&P)!=EOF)
	{
		count = 0 ,head = 0 , rear = 0 , memset(queue,0,sizeof(queue));
		for(int i = 0 ; i<K ; i++) {queue[rear]=i+1;rear=(rear+1)%MAX;}
		while(head!=rear)
		{
			//for(int i = head ; i <= rear ; i++ ) printf("%d ",queue[i]);
			//printf("\n");
			if(count%(P+1)==0)
			{
				temp = queue[head];
				head = (head+1)%MAX;
				if(count/(P+1)==N-1) flag[temp]=1;
			}
			else
			{
				temp = queue[head];
				head = (head+1)%MAX;
				queue[rear]=temp;
				rear = (rear+1)%MAX;
			}
			count = (count+1) % ( N * (P+1) );
		}
		for(int i = 0 ; i < MAX ; i++)
			if(flag[i]) printf("%d\n",i);
	}
}
