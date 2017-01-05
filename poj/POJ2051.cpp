#include <cstdio>
#include <cstring>
#define MAX 2000
#define DEBUG
 
struct e
{
	int id;
	int weight;
	int value;
	int num;
};

int MIN_HEAPIFY(e min_heap[],int top,int heap_size);
int BUILD_MIN_HEAP(e min_heap[],int heap_size);
bool IsLower(e e0,e top);

struct e min_heap[MAX],e0;
int heap_size,id,weight,num;
char str0[100];

int main()
{
	int count = 0;
	
#ifdef DEBUG
	freopen("2051.txt","r",stdin);
#endif

	while(scanf("%s",str0))
	{
		if(strcmp(str0,"Register")==0)
		{
			scanf("%d%d",&e0.id,&e0.value);
			getchar();
			e0.num = 1;
			e0.weight = e0.num * e0.value;
			min_heap[++count] = e0 ;
		}
		if(strcmp(str0,"#")==0)
		{
			scanf("%d",&num);
			heap_size = count;
			break;
		}

#ifdef DEBUG
		printf(" (%d %d) ",min_heap[count].weight,min_heap[count].id);
		printf("\n");
#endif
		
	}	
	BUILD_MIN_HEAP(min_heap,count);
	for(int i = 1 ; i<=num ; i++)
	{
		printf("%d\n",min_heap[1]);
		min_heap[1].weight = min_heap[1].value * (++min_heap[1].num);
		MIN_HEAPIFY(min_heap,1,heap_size);

		#ifdef DEBUG
		printf("i = %d\n",i);
		for(int i = 1 ; i <= heap_size ; i++)
			printf(" (%d %d %d) ",min_heap[i].weight,min_heap[i].id,min_heap[i].num);
		printf("\n");
                #endif

	}
	return 0;
}

int BUILD_MIN_HEAP(e min_heap[],int heap_size)
{
	for(int i = heap_size/2 ; i >= 1 ; i--)
	{
		MIN_HEAPIFY(min_heap,i,heap_size);

#ifdef DEBUG
		printf("i = %d\n",i);
		for(int i = 1 ; i <= heap_size ; i++)
			printf(" (%d %d) ",min_heap[i].weight,min_heap[i].id);
		printf("\n");
#endif
	
	}
	return 0;
}

int MIN_HEAPIFY(e min_heap[],int top,int heap_size)
{
	int left , right ,small;
	e value;
	left = top<<1,right = (top<<1) + 1;

	if(left <= heap_size && IsLower(min_heap[left],min_heap[top]))
		small = left , value = min_heap[left];
	else 
		small = top , value = min_heap[top];

	if(right <= heap_size && IsLower(min_heap[right],value))
		small = right , value = min_heap[right];

	if(small != top)
	{
		min_heap[small] = min_heap[top];
		min_heap[top] = value;
		MIN_HEAPIFY(min_heap,small,heap_size);
	}
	return 0;
}

bool IsLower(e e0,e top)
{
	if(e0.weight < top.weight)
		return true;
	else
		if(e0.weight == top.weight && e0.id < top.id)
			return true;
		else return false;
}
