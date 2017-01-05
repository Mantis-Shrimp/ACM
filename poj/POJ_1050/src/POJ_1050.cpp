
#include <stdio.h>

#define SIZE 200

int arr[SIZE][SIZE];
int sum[SIZE];
int dp[SIZE];
int max;
int N;

int DP();
int calsum();
int main()
{
	scanf("%d\n",&N);
	for(int iH=0 ; iH<N ; iH++)
		for(int iW=0 ; iW<N;iW++)
		scanf("%d",&arr[iH][iW]);
	max=arr[0][0];
	calsum();
	printf("%d\n",max);
	return 0;
}


int calsum()
{

	for(int H = 0 ; H < N; H++)
	{
		for(int isum = 0 ; isum < N ; isum++) sum[isum]=0;

		for(int iH = H ; iH < N ; iH++)
		{
		   for(int iW = 0 ; iW < N ; iW++)
			   {sum[iW]+=arr[iH][iW];}
		   DP();
		}
	}
	return 0;
}


int DP()
{
	int imax = sum[0];
	dp[0]=sum[0];
	for(int isum=1 ; isum<N ;isum++)
	{
		if(dp[isum-1]>=0) dp[isum]=dp[isum-1]+sum[isum];
		else dp[isum]=sum[isum];
		if(dp[isum]>=imax)imax=dp[isum];
	}
	if(imax>=max)max=imax;
	return 0;
}
