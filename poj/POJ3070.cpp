//============================================================================
// Name        : POJ_3070. cpp
// Author      :
// Version     :
// Copyright   : 2012-7-28
// Description : æÿ’Û‘ÀÀ„
//============================================================================
#include <stdio.h>
#define MAX 100
int a[MAX][MAX], b[MAX][MAX], r[MAX][MAX];
int T;

int matrix_mul(int a[][MAX],int ah,int aw,int b[][MAX],int bh,int bw,int r[][MAX],int MOD);
int fase_matrix_pow(int a[][MAX],int ah,int aw,int p,int r[][MAX]);

int main(int argc,char* argv[])
{
	while(scanf("%d",&T)&&T!=-1)
	{
		a[0][0] = 1 , a[0][1] = 0;
		b[0][0] = 1 , b[0][1] = 1, b[1][0] = 1 ,b[1][1] = 0 ;
		if(T==0)
		{
			printf("0\n");
		}
		else
		{
			if(T==1)
			{
				printf("1\n");
			}
			else
			{
				fase_matrix_pow(b,2,2,T-1,r);
				matrix_mul(a,2,1,r,2,2,r,10000);
				printf("%d\n",r[0][0]);
			}
		}
	}
	return 0;
}

int matrix_mul(int a[][MAX],int ah,int aw,int b[][MAX],int bh,int bw,int r[][MAX],int MOD)
{
	int R = 0;
	int temp[MAX][MAX];
	
	if (aw!=bh) return 0;
	for(int ih = 0 ; ih < ah ; ih++)
	{
	  for(int iw = 0 ; iw < bw ; iw++)
	  {
		  R = 0 ;
		  for(int i = 0 ; i < aw ; i++)
		  {
			  R = (R + a[ih][i]*b[i][iw]) % MOD ;
		  }
		  temp[ih][iw] = R;
	  }
	}

	for(int ih = 0 ; ih < ah ; ih++)
	  for(int iw = 0 ; iw < bw ; iw++)
		r[ih][iw] = temp[ih][iw] ;
	
	return 0;
}

int fase_matrix_pow(int a[][MAX],int ah,int aw,int p,int r[][MAX])
{
	int temp[MAX][MAX]; 
	
	for(int ih = 0 ; ih < ah ; ih++)
	{
	  for(int iw = 0 ; iw < aw ; iw++)
	  {
		  temp[ih][iw] = a[ih][iw] ;
		  if(ih == iw) r[ih][iw] = 1;
		  else r[ih][iw] = 0 ;
	  }
	}

	while(p>0)
	{
		if(p&1==1)  matrix_mul(r,ah,aw,temp,ah,aw,r,10000);
		p>>=1;
		matrix_mul(temp,ah,aw,temp,ah,aw,temp,10000);
	}
	return 0;
}

