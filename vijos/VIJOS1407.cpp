//============================================================================
// Name        : Vijos1407
// Author      :
// Version     :
// Copyright   : 2013-10-28
// Description : 0-1 package 
//============================================================================

#include <iostream>
#include <cstring>


using namespace std;

	struct texture
	{
		int idx;
		int v;
		int c;
	};

	int  main(int argc, char* argv[])
	{
		texture tx[3];
		int n,m,idx;
		int b[200];
		int z[200];
		int dp[9000];
		cin>> n >>m ;

		for(int i = 0 ; i < 3 ; i++)
		{
			cin>>tx[i].idx>>tx[i].c >> tx[i].v;
		}

		for(int i = 0 ; i < n ; i++)
		{
			
			cin>>b[i];
			cin>>z[i];
			
			for(int j = 0 ; j < 3 ; j++)
			{
				if(z[i] == tx[j].idx)
				{
					z[i] = b[i] * tx[j].c;
					b[i] = b[i] + b[i] * tx[j].v;
					break;
				}
			}
		}

		//System.out.println(Arrays.toString(b));
		//System.out.println(Arrays.toString(z));


		for(int i = 0 ; i < n ; i++ )
		{
			for(int j = m ; j >= b[i] ; j--)
			{
				if(dp[j - b[i]] + z[i] > dp[j])
					dp[j] = dp[j - b[i]] + z[i];
			}
		}


		cout<<dp[m];

		return 1;
	}

