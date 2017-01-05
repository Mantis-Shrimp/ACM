//============================================================================
// Name        : UVa_507. cpp
// Author      :
// Version     :
// Copyright   : 2013-12-21 
// Description : 最大子段和
//============================================================================
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


const int S = 25000;

int T,t,s;
int r[S],istart[S],iend[S],sum[S];
int Max,start,end;

int main(int argc, char* argv[])
{
	scanf("%d",&T);
	for(int t = 1 ; t <= T ; t++)
	{
		scanf("%d\n",&s);

		for(int i = 1 ; i < s ; i++)
			scanf("%d",&r[i]);

		sum[0] = 0;
		istart[0] = 1;
		iend[0] = 1;
		Max = INT_MIN;
		start = 0;
		end = 0;

		for(int i = 1 ; i < s ; i++)
		{
			sum[i] = sum[i-1] + r[i];

			if(sum[i] >= 0)
			{
				istart[i] = istart[i-1];
				iend[i] = iend[i-1] + 1;
			}
			else
			{
				sum[i] = 0;
				istart[i] = i + 1;
				iend[i] = i + 1;	
			}
		}

		// for(int i = 0 ; i < s ; i++)
		// {
		// 	printf("%d ",sum[i]);
		// }
		// printf("\n");

		// for(int i = 0 ; i < s ; i++)
		// {
		// 	printf("%d ",istart[i]);
		// }
		// printf("\n");
		
		// for(int i = 0 ; i < s ; i++)
		// {
		// 	printf("%d ",iend[i]);
		// }
		// printf("\n");

		for (int i = 0; i < s; ++i)
		{
			if(sum[i]>Max)
			{
				Max = sum[i];
				start = istart[i];
				end = iend[i];
			}
			else
			{
				if(sum[i]==Max)
				{
					if( iend[i]- istart[i] > end - start)
					{
						end = iend[i];
						start = istart[i];
					}
				}
			}
		}

		if(Max > 0) printf("The nicest part of route %d is between stops %d and %d\n", t,start,end);
		else printf("Route %d has no nice parts\n",t);
	}
	return 0;
}