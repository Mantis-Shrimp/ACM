//============================================================================
// Name        : POJ_1416.cpp
// Author      : 
// Version     :
// Copyright   : 2012-7-5
// Description : Shredding Company DFS(深度优先)
//============================================================================
#include <stdio.h>
#include <string.h>
#include <limits.h>
#define LEN 10
int r,des,out[LEN],r_out[LEN],len,c,num;
char sou[LEN];

int DFS(int depth,int sum,int nsum,int count);

int main()
{
  while(scanf("%d %s",&des,sou)&&!(des==0&&sou[0]=='0'))
  {
      len = strlen(sou),c=0,r=-1;
      DFS(1,0,0,0);
      if(r==-1)  printf("error\n");
      else
        {
          if(c==1)
            {
            printf("%d ",r);
            for(int i = 0 ; i<num ; i++) printf("%d ",r_out[i]);
            printf("\n");
            }
          else
            {
              printf("rejected\n");
            }
        }
   }
  return 0;
}


int DFS(int depth,int sum,int nsum,int count)
{
  int tempsum=0,tempnsum=0;
  if(depth==len)
    {
      tempnsum=(nsum*10+(sou[depth-1]-'0'));
      tempsum=sum+tempnsum;
      if(tempsum<=des) out[count]=tempnsum,DFS(depth+1,tempsum,0,count+1);
    }
  if(depth==len+1)
    {
      //for(int i = 0 ; i<=count;i++) printf("%d ",out[i]);
      //printf("\n");
      if(sum > r) r = sum,memcpy(r_out,out,sizeof(out)),c=1,num=count;
      else if(sum == r) c++;
    }

  if(depth<len)
  {
  for(int i = 0 ; i<=1 ; i++)
    {
      if(i==0)
        {
          tempnsum=(nsum*10+(sou[depth-1]-'0'));
          DFS(depth+1,sum,tempnsum,count);
        }
      else
        {
          tempnsum=(nsum*10+(sou[depth-1]-'0'));
          tempsum=sum+tempnsum;
          if(tempsum<=des) out[count]=tempnsum,DFS(depth+1,tempsum,0,count+1);
        }
    }
  }
  return 0;
}
