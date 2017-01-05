//============================================================================
// Name        : VIjOS1098.cpp
// Author      : 
// Version     :
// Copyright   : 2013-10-31
// Description : 合唱队形       双端动态规划
//============================================================================

#include <stdio.h>
#include <stdlib.h>

#define LEN 200

int fldp();
int frdp();

int N;
int seq[LEN];
int ldp[LEN],rdp[LEN];
int lmax[LEN],rmax[LEN];
int max;

int main()
{
	scanf("%d\n",&N);
	max=0;
	for(int iseq = 1 ; iseq<=N ; iseq++) scanf("%d",seq+iseq);
	fldp();
	frdp();

	for(int imax = 1; imax<=N ; imax++)
		if(max<(rmax[imax]+lmax[imax]-1)) max = rmax[imax]+lmax[imax]-1;

	printf("%d\n",N-max);

}

int fldp()
{
	lmax[0]=0;
	for(int iseq=1;iseq <=N ; iseq++)
	{
		ldp[iseq] = 1 ;
		for(int ildp=iseq-1; ildp>=1 ; ildp--)
		{
			if(seq[iseq]>seq[ildp])
			{
				if(ldp[iseq] < ldp[ildp] + 1) ldp[iseq] = ldp[ildp] +1 ;
			}
		}
		if(lmax[iseq-1]>ldp[iseq]) lmax[iseq] = lmax[iseq-1];
		else lmax[iseq] = ldp[iseq];
	}
	return 0;
}

int frdp()
{
	rmax[N+1] = 0 ;
	for(int iseq=N ; iseq >= 1 ; iseq--)
	{
		rdp[iseq] = 1;
		for(int irdp=iseq+1 ; irdp <=N ; irdp++)
		{
			if(seq[iseq]>seq[irdp])
			{
				if(rdp[iseq]<rdp[irdp]+1) rdp[iseq] = rdp[irdp]+1;
			}
		}

		if(rmax[iseq+1]>rdp[iseq]) rmax[iseq]=rmax[iseq+1];
		else rmax[iseq] = rdp[iseq];
	}
	return 0;
}
