//============================================================================
// Name        : Vijos1064
// Author      :
// Version     :
// Copyright   : 2013-10-29
// Description : simple 
//============================================================================
#include <stdio.h>
#include <string.h>


int list[6][11];
int S;
int LEN;
char chs[100];
int put_(int s,int flag);
int put(int s,int flag);
int main()
{
    int ilen = 1;
    list[1][1]=0,list[1][2]=1,list[1][3]=1,list[1][4]=0,list[1][5]=1,list[1][6]=1,list[1][7]=1,list[1][8]=1,list[1][9]=1,list[1][0]=1;
    list[2][1]=2,list[2][2]=2,list[2][3]=2,list[2][4]=3,list[2][5]=1,list[2][6]=1,list[2][7]=2,list[2][8]=3,list[2][9]=3,list[2][0]=3;
    list[3][1]=0,list[3][2]=1,list[3][3]=1,list[3][4]=1,list[3][5]=1,list[3][6]=1,list[3][7]=0,list[3][8]=1,list[3][9]=1,list[3][0]=0;
    list[4][1]=2,list[4][2]=1,list[4][3]=2,list[4][4]=2,list[4][5]=2,list[4][6]=3,list[4][7]=2,list[4][8]=3,list[4][9]=2,list[4][0]=3;
    list[5][1]=0,list[5][2]=1,list[5][3]=1,list[5][4]=0,list[5][5]=1,list[5][6]=1,list[5][7]=0,list[5][8]=1,list[5][9]=1,list[5][0]=1;

    scanf("%d\n",&S);
        gets(chs);
        LEN = strlen(chs);
        ilen = 0;
        for(int i = 1; i <= 2*S+3 ; i++)
        {
            ilen=0;
            while(ilen<=LEN)
            {
                if(i==1) put_(S,list[1][chs[ilen]-'0']);

                if(i>=2&&i<=S+1) put(S,list[2][chs[ilen]-'0']);

                if(i==S+2)put_(S,list[3][chs[ilen]-'0']);

                if(i>=S+3&&i<=2*S+2)put(S,list[4][chs[ilen]-'0']);

                if(i==2*S+3)put_(S,list[5][chs[ilen]-'0']);

                if(ilen!=LEN)printf(" ");
                ilen++;
            }
            printf("\n");
        }
    return 0;
}



int put_(int s,int flag)
{
    if(flag==0){for(int i = 0 ; i < s+2 ; putchar(' '),i++);return 0;}
    if(flag==1){putchar(' ');for(int i = 0 ; i < s ; putchar('-'),i++);putchar(' ');return 0;}
    return 0;
}

int put(int s,int flag)
{
    if(flag==1){putchar('|');for(int i = 0 ; i < s ; putchar(' '),i++);putchar(' ');return 0;}
    if(flag==2){putchar(' ');for(int i = 0 ; i < s ; putchar(' '),i++);putchar('|');return 0;}
    if(flag==3){putchar('|');for(int i = 0 ; i < s ; putchar(' '),i++);putchar('|');return 0;}
    return 0;
}