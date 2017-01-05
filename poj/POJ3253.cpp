#include<cstdio>
#define MAX 25000
//#define DEBUG
int heap[MAX],N;
__int64 r,temp;
int BUILD_MIN_HEAP();
int MIN_HEAPIFY(int h[],int n);

int main()
{
#ifdef DEBUG
	freopen("poj3253.in","r",stdin);
#endif
	scanf("%d",&N);
	for(int i = 1 ; i <= N ; i++) scanf("%d",heap+i);

	BUILD_MIN_HEAP();
	
	r = 0;
	if(N==1) r = heap[1];
	while(N>=2)
	{
	
	temp = 0 ;
	temp += heap[1],heap[1] = heap[N--];
	MIN_HEAPIFY(heap,1);
	temp += heap[1];
	heap[1]=temp;
	r+= temp;
	MIN_HEAPIFY(heap,1);

#ifdef DEBUG
	for(int i = 1 ; i<= N ; printf("%d ",heap[i++]));
	printf("\n");
#endif

	}
	printf("%I64d",r);
}

int BUILD_MIN_HEAP()
{
	
	for(int i = N/2 ; i >= 1 ; i--) 
	{
		MIN_HEAPIFY(heap,i);
#ifdef DEBUG
	printf("BUILD %d \n",i);
	for(int i = 1 ; i<= N ; printf("%d ",heap[i++]));
	printf("\n");
#endif
	}
	return 0;
}

int MIN_HEAPIFY(int h[],int n)
{
	int small,left,right,value;
	left = n<<1,right = (n<<1) + 1;

        //printf("left = %d right = %d\n",left,right);

	if(left<=N&&h[left]<h[n])
		small=left,value=h[left];
	else
		small=n,value=h[n];
	
	if(right<=N&&h[right]<value)
		small = right,value = h[right];

	if(n != small)
	{
		h[small] = h[n],h[n] = value;
		MIN_HEAPIFY(h,small);
	}
	return 0;
}

