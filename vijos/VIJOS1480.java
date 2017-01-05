//============================================================================
// Name        : Vijos1480
// Author      :
// Version     :
// Copyright   : 2013-10-28
// Description : String Dynamical programming 
//============================================================================

import java.util.Scanner;
import java.util.Arrays;


public class VIJOS1480
{
	
	public VIJOS1480(){return;}

	public int work()
	{
		Scanner cin = new Scanner(System.in);
		String str = cin.nextLine();
		
		int len = str.length();
		int dp[] = new int[len+1];
		int flag[] = new int[len+1];
		int pow[] = new int[len+1];
		int res[] = new int[4];
		int max = 0;
		
		for(max = 1 ; max * max <= len ; max++)
			pow[max] = max * max;
		
		max -- ;

		Arrays.fill(dp,Integer.MAX_VALUE);
		dp[0] = 0;
		
		for(int i = 1; i <= max ; i++)
		{
			for(int j = 0 ; j <= len ; j++)
			{
				if(dp[j] != Integer.MAX_VALUE && j + pow[i] <= len && (dp[j] + 1) <= dp[j + pow[i]])
				{
					dp[j + pow[i]] = dp[j] + 1;
					flag[j+pow[i]] = i;  // record path
				}
			}
		}

		

		//System.out.println(Arrays.toString(dp));
		//System.out.println(Arrays.toString(flag));

		int pos = len;
		int idx = 0;
		while(pos != 0)
		{
			res[idx++] = flag[pos];
			pos -= flag[pos] * flag[pos];
		}
		//idx -- ;
		
		//output
		for(int i = 0 ; i <= 3 ; i++)
		{
			for(int j = i + 1 ; j<= 3 ; j++)
			{
				if(res[i] < res[j])
				{
					int temp = res[i];
					res[i] = res[j];
					res[j] = temp;
				}
			}
		}


		for(int i = 0 ; i < idx ; i ++)
		{
			for(int j = 0 ; j < res[i] ; j++)
				for(int k = 0 ; k < res[i] ; k++)
					System.out.print(str.charAt(pos + k * res[i] + j));
			
			pos += res[i] * res[i];
		}



		return 1;
	}

	public static void main(String[] args)
	{
		VIJOS1480 VIJOS = new VIJOS1480();
		VIJOS.work();
		return ;
	}
}

