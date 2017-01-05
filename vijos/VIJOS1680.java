//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-10-14
// Description : 动态规划 LCS变形
//============================================================================


import java.util.Scanner;
import java.io.BufferedInputStream;
import java.lang.Math;


public class VIJOS1680
{
	Scanner cin = new Scanner(new BufferedInputStream(System.in));
	String a = null;
	String b = null;
	int k = 0;
	int dp[][] = null;

	public static void main(String[] args) 
	{
		VIJOS1680 VIJOS = new VIJOS1680();
		VIJOS.work();
		return ;
	}

	public int getMin(int a,int b,int c)
	{
		int min = a;
		
		if(b < min) min = b;
		if(c < min) min = c;

		return min;
	}


	public int work()
	{
		
		int temp = 0;
		int atemp = 0;
		int btemp = 0;
		int ctemp = 0;

		while(cin.hasNext())
		{
			a = cin.nextLine();
			b = cin.nextLine();
			k = cin.nextInt();

			dp = new int[b.length() +1][a.length() + 1];

			for(int ib = 0 ; ib <= b.length() ; ++ib)
				dp[ib][0] = ib * k;

			for(int ia = 0 ; ia <= a.length() ; ++ia)
				dp[0][ia] = ia * k;

			for(int ib = 1 ; ib <= b.length(); ++ib)
			{
				for(int ia = 1 ; ia <= a.length() ; ++ia)
				{
					atemp = dp[ib-1][ia-1] + Math.abs(a.charAt(ia-1) - b.charAt(ib-1));
					btemp = dp[ib][ia-1] + k ;
					ctemp = dp[ib-1][ia] + k ;

					dp[ib][ia] = getMin(atemp,btemp,ctemp);
				}
			}

			System.out.println(dp[b.length()][a.length()]);
		}
		return 1;
	}
}