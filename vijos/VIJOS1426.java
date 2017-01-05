//============================================================================
// Name        : Vijos1426
// Author      :
// Version     :
// Copyright   : 2013-10-26
// Description : multi-dimentional 0-1 package    dynamical programming 
//============================================================================

import java.util.Scanner;
import java.io.BufferedInputStream;

public class VIJOS1426
{
	
	public static final int LEN = 5000000 + 10;
	public VIJOS1426(){return;}

	//public final int getPos(int v1,int v2)

	public int work()
	{
		
		int dp[] = new int[LEN];
		int n,m,cur,pre;
		int V[] = new int[6];
		int p[] = new int[300];
		int v[][] = new int[300][6];

		Scanner cin = new Scanner(new BufferedInputStream(System.in));

		n = cin.nextInt();
		m = cin.nextInt();

		for(int i = 1 ; i <= m ; i++) V[i] = cin.nextInt();
		for(int i = 1 ; i <= n ; i++)
		{
			p[i] = cin.nextInt();
			for(int j = 1 ; j <= m ; j++)
				v[i][j] = cin.nextInt();
		}


		for(int in = 1 ; in <= n ; in++)  //through each item
		{
			for(int iv1 = V[1] ; iv1 >= v[in][1]; iv1--)
			{
				for(int iv2 = V[2] ; iv2 >= v[in][2]; iv2--)
				{
					for(int iv3 = V[3] ; iv3 >= v[in][3] ; iv3--)
					{
						for(int iv4 = V[4] ; iv4 >= v[in][4] ; iv4--)
						{
							for(int iv5 = V[5]; iv5 >= v[in][5] ; iv5--)
							{
								cur = iv1*(V[2]+1)*(V[3]+1)*(V[4]+1)*(V[5]+1) + iv2*(V[3]+1)*(V[4]+1)*(V[5]+1) + iv3*(V[4]+1)*(V[5]+1) + iv4*(V[5]+1) + iv5;
								pre = (iv1-v[in][1])*(V[2]+1)*(V[3]+1)*(V[4]+1)*(V[5]+1) + (iv2-v[in][2])*(V[3]+1)*(V[4]+1)*(V[5]+1) + (iv3-v[in][3])*(V[4]+1)*(V[5]+1) + (iv4 - v[in][4])*(V[5]+1) + iv5 - v[in][5];
							
								if(dp[pre] + p[in] > dp[cur])
									dp[cur] = dp[pre] + p[in];
							}
						}
					}
				}
			}
		}

		cur = V[1]*(V[2]+1)*(V[3]+1)*(V[4]+1)*(V[5]+1) + V[2]*(V[3]+1)*(V[4]+1)*(V[5]+1) + V[3]*(V[4]+1)*(V[5]+1) + V[4]*(V[5]+1) + V[5];

		System.out.printf("%d\n",dp[cur]);

		return 1;
	}

	public static void main(String[] args)
	{
		//Scanner cin = new Scanner(System.in);
		//while(cin.hasNext())
		//{
			VIJOS1426 VIJOS = new VIJOS1426();
			VIJOS.work();
		//}
		return ;
	}
}

