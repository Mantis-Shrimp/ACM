//============================================================================
// Name        : POJ_2479.cpp
// Author      : 
// Version     :
// Copyright   : 2012-5-2
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>


#define LEN 100010

int list[LEN];
int rdp[LEN],rmax[LEN];
int ldp[LEN],lmax[LEN];
int T;
int len;
int max;

int main()
{
	scanf("%d\n",&len);
	while(len!=0)
	{
		for(int i = 1 ; i<=len ; i++) scanf("%d",list+i);
		ldp[0]=0,rdp[len+1]=0;
		rmax[0]=0,lmax[len+1]=0;
		for(int i = 1 ; i<=len ; i++)
		{
			if(ldp[i-1]>=0) ldp[i] = ldp[i-1] + list[i];
			else ldp[i] = list[i];
			if(i==1)
			{
				lmax[i] = ldp[i];
			}
			else
			{
				lmax[i] = lmax[i-1]>=ldp[i]?lmax[i-1]:ldp[i];
			}
		}

		for(int i = len ; i>=1 ; i--)
		{
				if(rdp[i+1]>=0) rdp[i] = rdp[i+1] + list[i];
				else rdp[i] = list[i];

				if(i==len)
				{
					rmax[i] = rdp[i];
				}
				else
				{
					rmax[i] = rmax[i+1]>=rdp[i]?rmax[i+1]:rdp[i];
				}
		}

	   max=lmax[1]+rmax[2];

	   //for(int i = 1 ; i<=len ; i++) printf(" %d",rmax[i]);
	   //printf("\n");
	   //for(int i = 1 ; i<=len ; i++) printf(" %d",lmax[i]);
	   //printf("\n");

	   for(int i = 1 ; i<=len-1 ; i++) if(lmax[i]+rmax[i+1]>=max) max=lmax[i]+rmax[i+1];

	   printf("%d\n",max);
	   scanf("%d\n",&len);
	}
	return 0;
}
