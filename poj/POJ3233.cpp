//============================================================================
// Name        : POJ_3233. cpp
// Author      :
// Version     :
// Copyright   : 2012-7-28
// Description : æÿ’Û‘ÀÀ„
//============================================================================
#include <stdio.h>
#include <string.h>
#define N 30 + 5
int a[N][N],r[N][N],n,k,m;


int matrix_add(int a[N][N],int b[N][N],int r[N][N],int h,int w,int mod);
int matrix_mul(int a[][N],int ah,int aw,int b[][N],int bh,int bw,int r[][N],int MOD);
int fast_matrix_pow(int a[][N],int ah,int aw,int p,int r[][N],int MOD);
int func(int a[N][N],int k, int r[N][N]);

int main(int argc,char* argv[])
{
	scanf("%d%d%d",&n,&k,&m);
	
	for(int i = 0 ; i < n ; i++)
	  for(int j = 0 ; j < n ; j++)
		scanf("%d",&a[i][j]);
	
	func(a,k,r);
	
	for(int i = 0 ; i < n ; i++)
	{
	  for(int j = 0 ; j < n ; j++)
	  {
		  printf("%d ",r[i][j]);
	  }
	  printf("\n");
	}
	return 0;
}

int func(int a[N][N],int k, int r[N][N])
{
	int _r[N][N];
	int _a[N][N];
	int _p[N][N];
	int _b[N][N];
	
	if(k==1)
	{
	for(int i = 0 ; i<n ; i++)
	  for(int j = 0 ; j<=n ; j++)
		r[i][j] = a[i][j];
	return 0;
	}

	if(k&1==1)
	{
		func(a,k-1,_a);
		fast_matrix_pow(a,n,n,k,_p,m);
		matrix_add(_a,_p,_r,n,n,m);
	}
	else
	{
		func(a,k/2,_a);
		fast_matrix_pow(a,n,n,k/2,_p,m);
		matrix_mul(_a,n,n,_p,n,n,_b,m);
		matrix_add(_b,_a,_r,n,n,m);
	}

	for(int i = 0 ; i<n ; i++)
	  for(int j = 0 ; j<=n ; j++)
		r[i][j] = _r[i][j];

	return 0;
}

int matrix_mul(int a[][N],int ah,int aw,int b[][N],int bh,int bw,int r[][N],int MOD)
{ 
	int R = 0;
	int temp[N][N];
	
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

int fast_matrix_pow(int a[][N],int ah,int aw,int p,int r[][N],int MOD)
{ 
	int temp[N][N]; 
	
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
		if(p&1==1)  matrix_mul(r,ah,aw,temp,ah,aw,r,MOD);
		p>>=1;
		matrix_mul(temp,ah,aw,temp,ah,aw,temp,MOD);
	}
	return 0;
}

int matrix_add(int a[N][N],int b[N][N],int r[N][N],int h,int w,int mod)
{
	for(int ih = 0 ; ih < h ; ih++)
		for(int iw = 0 ; iw < w ; iw++)
			r[ih][iw] = (a[ih][iw] + b[ih][iw]) % mod ;
	return 0;
}

