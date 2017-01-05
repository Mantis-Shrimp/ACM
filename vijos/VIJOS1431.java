//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-10-14
// Description : greedy algorithm
//============================================================================

import java.util.Scanner;
import java.io.BufferedInputStream;

public class VIJOS1431
{
	
	public int M = 0;
	public int S = 0;
	public int T = 0;


	public int work()
	{
		int m = this.M;
		int s = this.S;
		int t = this.T;

		int dis0 = 0;
		int dis1 = 0;

		for(int it = 1 ; it <= t; it++)
		{
			dis0 = dis0 + 17;
			if(m >= 10)
			{
				m -= 10;
				dis1 += 60;
			}
			else
			{
				m += 4;
			}

			if(dis1 > dis0) dis0 = dis1;

			if(dis0 >= s)
			{
				System.out.println("Yes");
				System.out.println(it);
				return 1;
			}
		}

		if(dis0 < s)
		{
				System.out.println("No");
				System.out.println(dis0);
		}

		return 1;
	}

	public static void main(String args[])
	{
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		VIJOS1431 VIJOS = new VIJOS1431();
		
		while(cin.hasNext())
		{
			VIJOS.M = cin.nextInt();
			VIJOS.S = cin.nextInt();
			VIJOS.T = cin.nextInt();
			VIJOS.work();
		}
		return ;
	}
}