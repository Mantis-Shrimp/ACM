//============================================================================
// Name        : POJ_1836.cpp
// Author      : 
// Version     :
// Copyright   : 2012-5-2
// Description : Alignment Ë«¶Ë¶¯Ì¬¹æ»®
//============================================================================
#include <stdio.h>
#include <stdlib.h>

#define LEN 2000

int fldp();
int frdp();

int N;
double seq[LEN];
int ldp[LEN],rdp[LEN];
int lmax[LEN],rmax[LEN];
int max;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(scanf("%d\n",&N)!=EOF)
	{
	max=0;
	for(int iseq = 1 ; iseq<=N ; iseq++) scanf("%lf",seq+iseq);
	fldp();
	frdp();

	if(max<lmax[N]) max=lmax[N];
	for(int imax = 1; imax<=N-1 ; imax++)
		if(max<(rmax[imax+1]+lmax[imax])) max = rmax[imax+1]+lmax[imax];
	if(max<rmax[1]) max=rmax[1];

	printf("%d\n",N-max);
	}


/*
	for(int i = 0 ; i<=N ; i++)
		printf("%d",ldp[i]);
	puts("\n");
	for(int i = 0 ; i<=N+1 ; i++)
		printf("%d",lmax[i]);
	puts("\n");
	for(int i = 1 ; i<=N ; i++)
		printf("%d",rdp[i]);
	puts("\n");
	for(int i = 0 ; i<=N + 1; i++)
		printf("%d",rmax[i]);
	puts("\n");
*/
	return 0;

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
