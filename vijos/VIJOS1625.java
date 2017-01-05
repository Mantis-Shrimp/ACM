//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-10-14
// Description : dynamic programing    simple 0-1 package
//============================================================================


import java.util.Scanner;
import java.io.BufferedInputStream;

public class VIJOS1625
{
	private int V = 0;
	private int N = 0;
	private int C = 0;

	private int dp[] = null;
	private int v[] = null;
	private int c[] = null;



	public static void main(String args[])
	{
		VIJOS1625 VIJOS = new VIJOS1625();
		VIJOS.work();
		return ;
	}

	public int work()
	{
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		while(cin.hasNext())
		{
			V = cin.nextInt();
			N = cin.nextInt();
			C = cin.nextInt();

			v = new int[N];
			c = new int[N];
			dp = new int[C+1];

			for(int i = 0 ; i < N ; i++)
			{
				v[i] = cin.nextInt();
				c[i] = cin.nextInt();
			}


			for(int in = 0 ; in < N ; in++)
				for(int ic = C ; ic >= c[in] ; ic--)
					if(dp[ic] < dp[ic - c[in] ] + v[in] )
						dp[ic] = dp[ic - c[in] ] + v[in];

			for(int i = 0 ; i <= C ; i++)
				if(dp[i] >= V)
				{
					System.out.println(C - i);
					return 1;
				}
			System.out.println("Impossible");

		}

		return 1;
	}
}
