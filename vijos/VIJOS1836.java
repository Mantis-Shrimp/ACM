//============================================================================
// Name        : VIJOS1836
// Author      :
// Version     :
// Copyright   : 2013/10/20
// Description : simple 0-1 package 
//============================================================================

import java.util.Scanner;
import java.util.Arrays;

public class VIJOS1836
{
	
	public static final int N_MAX = (1000+5);
	public static final int V_MAX = 5;
	public static final int T_MAX = 100;
	
	Scanner cin = new Scanner(System.in);


	public VIJOS1836(){return;}

	public int work()
	{
		double dp[] = new double[N_MAX * T_MAX];
		Arrays.fill(dp,Double.MAX_VALUE);
		int v = 0;
		double t = 0;
		int n = 0;
		double tempt = 0;
		int tempv = 0;

		dp[0] = 0;
		
		n = cin.nextInt();
		for(int i = 1 ; i <= n ; i++)
		{
			t = cin.nextDouble();
			v = cin.nextInt();
			for(int j = 1000 * 5 ; j >= 0 ; j--)
			{
				
				if(dp[j] < Double.MAX_VALUE)
				{
					tempt = dp[j] + t;
					tempv = j + v;
					if(tempv <= 1000 *5 && tempt < dp[tempv])
						dp[tempv] = tempt;
				}
			}
		}

		for(int i = 1000 * 5 ; i >= 0 ; i--)
			if(dp[i] <= 100.0)
			{ 
				System.out.println(i);
				break;
			}


		return 1;
	}

	public static void main(String[] args)
	{
			VIJOS1836 VIJOS = new VIJOS1836();
			VIJOS.work();
		return ;
	}
}

