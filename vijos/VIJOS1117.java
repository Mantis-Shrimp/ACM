//============================================================================
// Name        : vijos1117
// Author      :
// Version     :
// Copyright   : 2013-10-20
// Description : dynamic programming 
//============================================================================

import java.util.Scanner;

public class VIJOS1117
{
	
	public static final int N = 250;
	public static final int K = 10;

	public int dp[][] = new int[N][K];

	public VIJOS1117()
	{
		for(int i = 1 ; i < N ; i++)
			dp[i][1] = 1;

		for(int i = 2 ; i < K ; i++)
			for(int j = i ; j < N ; j++)
				dp[j][i] = dp[j-1][i-1] + dp[j-i][i];
	}

	public int work()
	{
		return 1;
	}

	public static void main(String[] args)
	{
		Scanner cin = new Scanner(System.in);
		VIJOS1117 VIJOS = new VIJOS1117();
		//VIJOS.work();
		while(cin.hasNext())
			System.out.println(VIJOS.dp[cin.nextInt()][cin.nextInt()]);
		return ;
	}
}