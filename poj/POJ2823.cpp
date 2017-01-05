//============================================================================
// Name        : POJ2823
// Author      :
// Version     :
// Copyright   : 2013-11-2
// Description : data structure
//============================================================================

#include <cstdio>

#define N 2000000

struct e
{
    int pos;
    int val;
};

e MinQueue[N];
e MaxQueue[N];
int ret0[N] , ret1[N] ;
int MinHead = 0 , MinRear = 0 ;
int MaxHead = 0 , MaxRear = 0 ;

int main(int argc, char *const argv[])
{
    int temp = 0;
    int n, k;

    while (scanf("%d %d\n", &n, &k) != EOF)
    {


        MinHead = 0 , MinRear = 0 ;
        MaxHead = 0 , MaxRear = 0 ;


        int i = 0 ;
        for (i = 0 ; i < k ; i++)
        {
            scanf("%d", &temp);

                while (MinHead < MinRear && MinQueue[MinRear - 1].val > temp)
                    MinRear -- ;
                MinQueue[MinRear].val = temp;
                MinQueue[MinRear].pos = i;
                MinRear ++ ;


                while (MaxHead < MaxRear && MaxQueue[MaxRear - 1].val < temp)
                    MaxRear -- ;
                MaxQueue[MaxRear].val = temp;
                MaxQueue[MaxRear].pos = i;
                MaxRear ++ ;
        }

        ret0[0] =  MinQueue[MinHead].val ;
        ret1[0] =  MaxQueue[MaxHead].val ;

        for ( ; i < n ; i++)
        {

            // dequeue from head

            while (MinHead < MinRear && (i - MinQueue[MinHead].pos >= k) )
                MinHead ++ ;

            while (MaxHead < MaxRear && (i - MaxQueue[MaxHead].pos >= k) )
                MaxHead ++ ;

            scanf("%d", &temp);

            // dequeue from rear
            while (MinHead < MinRear && MinQueue[MinRear - 1].val > temp)
                MinRear -- ;

            MinQueue[MinRear].val = temp;
            MinQueue[MinRear].pos = i;
            MinRear ++ ;

            while (MaxHead < MaxRear && MaxQueue[MaxRear - 1].val < temp)
                MaxRear -- ;
            MaxQueue[MaxRear].val = temp;
            MaxQueue[MaxRear].pos = i;
            MaxRear ++ ;


            ret0[i - k + 1] =  MinQueue[MinHead].val ;
            ret1[i - k + 1] =  MaxQueue[MaxHead].val ;
        }

        int j = 0;
        for (j = 0 ; j <= n - k ; j++)
            printf("%d ", ret0[j]);

        printf("\n");

        for (j = 0 ; j <= n - k ; j++)
            printf("%d ", ret1[j]);
        printf("\n");
    }

    return 1;
}
