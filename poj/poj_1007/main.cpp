//DNA Sorting
//
//

#include <stdio.h>
#include <stdlib.h>


typedef struct DNA
{
    int Measure;
    char *Sequeue;
    struct DNA *next;
} *slink,element;



int measure(char *Sequeue);
int insert (char* Sequeue);
void output(slink Head);


int Length = 0 ;
int Number = 0 ;
slink Head = 0;

int main()
{
    Head = (slink)malloc(sizeof(element));
    Head->next = NULL; 
	
	char *squeue = NULL;
    scanf("%d %d",&Length,&Number);      
    
    while(Number--)
    {
        squeue = (char*) malloc(sizeof(char));
		scanf("%s",squeue);
		insert(squeue);
    }
    output(Head);
    return 1;
}

int measure(char *Sequeue)
{
    int result = 0;
    for(int i = 0;i<=Length-1;i++)
    {
        for(int j = i+1;j<=Length-1;j++)
        {
            if(Sequeue[i]>Sequeue[j])
            {
                result++;
            }
        }
    }
    return result;
}

int insert (char* Sequeue)
{
    
	slink pa = Head;
	slink pb = (slink)malloc(sizeof(element));
	pb->Measure = measure(Sequeue);
    pb->Sequeue = Sequeue;
    pb->next = NULL;
    
	while(pa->next!=NULL&&pb->Measure>=pa->next->Measure)
    {
        pa = pa->next;
    }
    
    pb->next=pa->next;
    pa->next=pb;

	return 0;
}


void output(slink Head)
{
    slink pa = Head;
    pa = pa->next;
    while(pa)
    {
        printf("%s\n",pa->Sequeue);
        pa = pa->next;
    }
}
