//============================================================================
// Name        : Vijos1428
// Author      :
// Version     :
// Copyright   : 2013-10-26
// Description : two dimensional 01 package    dynamical programming 
//============================================================================

import java.util.Scanner;
import java.io.BufferedInputStream;
import java.util.Arrays;



public class VIJOS1428
{
	
	public VIJOS1428(){return;}

	public int work()
	{
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		long dp[][][] = new long[1500][60][60];
		int n,s,b,si,bi,ci,temps,tempb; 
		
		for(int j = 0 ; j < 1500 ; j++)
			for(int i = 0 ; i < 60 ; i++)
				Arrays.fill(dp[j][i],Long.MAX_VALUE);

		n = cin.nextInt();
		s = cin.nextInt();
		b = cin.nextInt();

		dp[1][0][0] = 0;
		for(int in = 1 ; in <= n ; in++)
		{
			si = cin.nextInt();
			bi = cin.nextInt();
			ci = cin.nextInt();
			
			for(int is = 0 ; is <= s ; is++)
			{
				for(int ib = 0 ; ib <= b ; ib++)
				{
					if(dp[in][is][ib] != Long.MAX_VALUE )
					{
						if(is + si >= s) 
							temps = s;
						else 
							temps = is + si;
						
						if(ib + bi >= b) 
							tempb = b;
						else 
							tempb = ib + bi;

						if(dp[in][is][ib] + ci < dp[in+1][temps][tempb] )
							dp[in+1][temps][tempb] = dp[in][is][ib] + ci;
						
						if(dp[in][is][ib] < dp[in + 1][is][ib])
							dp[in+1][is][ib] = dp[in][is][ib];
					}
				}
			}
		}

		System.out.println(dp[n+1][s][b] * 2 );

		return 1;
	}

	public static void main(String[] args)
	{

		VIJOS1428 VIJOS = new VIJOS1428();
		VIJOS.work();
		return ;
	}
}

