//============================================================================
// Name        : VIJOS1412
// Author      :
// Version     :
// Copyright   : 2013-10-21
// Description : the K-optimal solution 0-1 package 
//============================================================================

import java.util.Scanner;
import java.util.PriorityQueue;
import java.util.ArrayList;
import java.io.BufferedInputStream;
import java.util.Collections;
import java.util.Arrays;



public class VIJOS1412
{

	public VIJOS1412(){return;}
	public int work()
	{
		int k,v,n,p0,v0,tempp,tempv;
		int r = 0;
		int dp[][] = null;
		int result = 0;

		Scanner cin = new Scanner(new BufferedInputStream(System.in));

		k = cin.nextInt();
		v = cin.nextInt();
		n = cin.nextInt();

		dp = new int[v+1][k+1];

		for (int i = 0 ; i <= v ; i++)
			Arrays.fill(dp[i],Integer.MIN_VALUE) ;

		dp[0][0] = 0;

		for(int in = 1 ; in <= n ; in++)
		{
			v0 = cin.nextInt();
			p0 = cin.nextInt();

			for(int iv = v ; iv >= 0 ; iv--)
			{
				for(int ik = 0 ; ik < k ; ik++ )
				{
					if(dp[iv][ik] != Integer.MIN_VALUE)
					{
						tempp = dp[iv][ik] + p0;
						tempv = v0 + iv;

						//System.out.printf("%d %d\n",iv,ik);

						if(tempv <= v)
						{
							int ii = k ; // insert sort

							while( ii >= 1 && (dp[tempv][ii-1] < tempp))
							{
								dp[tempv][ii] = dp[tempv][ii-1];
								ii--;
							}
							dp[tempv][ii] = tempp;
						} 
					}
				}
			}
		}

		//for (int[] i:dp ) 
		//	System.out.printf("%s\n",Arrays.toString(i));
		for(int ii = 0 ; ii < k ; ii++)
			result += dp[v][ii];

		System.out.printf("%d\n",result);

		return 1;
	}

	public static void main(String[] args)
	{
		VIJOS1412 VIJOS = new VIJOS1412();
		VIJOS.work();
		return ;
	}
}

