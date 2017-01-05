#include <stdio.h>


#define LEN 20


int queue[LEN],head,rear;
int rect[LEN][LEN];
int n,card;

int main()
{
    int i,j,k,l;
    for(i = 13 ; i >= 1 ; i--)
    {
        head = rear = LEN-1;
        for(j = i ; j >= 1 ; j--)
        {
            queue[head=(head+LEN-1)%LEN] = j;
            for(l = 1 ; l <= j ; l++)
                queue[head=(head+LEN-1)%LEN] = queue[rear=(rear+LEN-1)%LEN];
        }

        for(k = 0 ; (head + k)%LEN!=rear; k++)
            rect[i][k]=queue[(head+k)%LEN];
    }

    scanf("%d",&n);
    for(i = 1 ; i <= n ; i++)
    {
        scanf("%d",&card);
        for(j = 0 ; j < card ; j++)
            printf("%d ",rect[card][j]);
        printf("\n");
    }
    return 0;
}
