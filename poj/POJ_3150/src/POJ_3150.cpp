//============================================================================
// Name        : POJ_3150.cpp
// Author      : 
// Version     :
// Copyright   : 2012-7-29
// Description : —≠ª∑æÿ’Ûµƒ‘ÀÀ„
//============================================================================

#include <cstdio>
#include <cmath>
#include <cstdlib>

#define N 500+5
#define min(X,Y) ((X)<(Y)?(X):(Y))

int n,m,d,k;
long long in[N],out[N],ma[N],p[N],temp[N];

int matrix_mul(long long a[N],int alen,long long b[N],int blen, long long r[N],long long MOD)
{
       long long R = 0;
       long long temp[N];

       if (alen!=blen) return 0;
       for(int i = 0 ; i <alen ; i++)
       {
       	R = 0;
       	for(int j = 0 ; j < blen ; j++)
       	{
       		R += a[j] * b[( i - j  + alen) % alen];
       		if(R>=MOD) R%=MOD;
        }
        temp[i] = R;
       }
       for(int i = 0 ; i<alen ; i++)
         r[i] = temp[i];
       return 0;
}

int matrix_fast_pow( long long a[N],int alen, int p,long long r[N],long long MOD)
{
       long long temp[N];
       for(int i = 0 ; i < alen ; i++)
		    temp[i] = a[i],r[i] = 0;
       r[0] = 1 ;
       while(p>0)
      {
             if(p&1==1)
             matrix_mul(r, alen ,temp,alen,r,MOD);
             p>>=1;
             matrix_mul(temp,alen,temp,alen,temp,MOD);
      }
       return 0;
}



int main()
{
	while(scanf("%d%d%d%d",&n,&m,&d,&k)!=EOF)
	{
		for(int i = 0 ; i<n ; i++) scanf("%I64d",&in[i]);

		for(int iw = 0 ; iw<n ; iw++)
        if(min(abs(0-iw),n-abs(0-iw))<=d)
		    ma[iw] = 1;
        else
		    ma[iw] = 0;

		matrix_fast_pow(ma,n,k,p,m);
		matrix_mul(in,n,p,n,out,m);
		for(int i = 0 ; i<n ; i++)
			printf("%I64d ",out[i]);
		printf("\n");
	}
	return 0;
}
