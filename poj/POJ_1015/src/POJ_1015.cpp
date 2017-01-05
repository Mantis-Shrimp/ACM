//============================================================================
// Name        : POJ_1015.cpp
// Author      : 
// Version     :
// Copyright   : 2012-6-12
// Description : Jury Compromise  广度优先
//============================================================================

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define LEN 900
#define N 205
#define M 25
#define base 450
int path[M][LEN],dp[M][LEN],a[N],b[N],m,n,r,rr[M],sum_a,sum_b;
int nCase=1;
bool LESS(int a,int b);
int main()
{
	int iim,iin,pos,sum;
	while(scanf("%d %d",&n,&m)&&m+n!=0)
	{
		r = INT_MAX,pos=INT_MAX,sum=INT_MAX,sum_a=0,sum_b=0;
		for(int in=0;in<n;in++) scanf("%d %d",a+in,b+in);
		memset(path,-1,sizeof(path)),memset(dp,-1,sizeof(dp)),dp[0][base+0]=0;
		for(int im = 0;im<m;im++)
			for(int i=-410;i<410;i++)
				if(dp[im][i+base]>=0)
					for(int in = 0 ; in<n ; in++)
						if(dp[im][i+base]+a[in]+b[in]>dp[im+1][i+base+a[in]-b[in]])
						{
							iim=im,iin=i+base;
							while(iim!=0&&path[iim][iin]!=in)
								{iin+=(-a[path[iim][iin]]+b[path[iim][iin]]);iim--;}
							if(iim==0) dp[im+1][i+base+a[in]-b[in]] = dp[im][i+base]+a[in]+b[in],path[im+1][i+base+a[in]-b[in]]=in;
						}
		for(int i = -410 ; i<410 ; i++)
			if(
			  (dp[m][base+i]!=-1&&abs(i)<r)
			||(dp[m][base+i]!=-1&&abs(i)==r&&sum<dp[m][base+i])
			  )
				r = abs(i),sum=dp[m][base+i],pos=i;

		iim = m,iin=pos;
		while(iim!=0)
		{
			rr[m-iim]=path[iim][base+iin];
			sum_a+=a[rr[m-iim]];
			sum_b+=b[rr[m-iim]];
			iin+=(-a[path[iim][base+iin]]+b[path[iim][base+iin]]);
			iim--;
		}
		sort(rr,rr+m,LESS);
		printf("Jury #%d\n",nCase++);
		printf("Best jury has value %d for prosecution and value %d for defence:\n",sum_a,sum_b);
		for(int i = 0 ; i<m;i++)
			printf(" %d",rr[i]+1);
		printf("\n\n");
	}
	return 0;
}

bool LESS(int a,int b)
{
	return a<b;
}
