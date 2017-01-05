//============================================================================
// Name        : Vijos1195
// Author      :
// Version     :
// Copyright   : 2013-11-2
// Description : data structure    hash
//============================================================================

import java.util.Scanner;
import java.util.Arrays;
import java.io.BufferedInputStream;

public class VIJOS1195
{
	public int work()
	{
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		int temp = 0,max = 0;
		int n = cin.nextInt();
		int list[] = new int[n+10];
		int hash[] = new int[2*n+10];

		Arrays.fill(hash,-1);
		hash[n + temp] = 0;
		for(int i = 1 ; i <= n ; i++)
		{
			list[i] = cin.nextInt();
			if(list[i] == 0) list[i] = -1;
		}

		for(int i = 1 ; i <= n ; i++)
		{
			temp =temp + list[i];
			
			if(hash[temp + n] == -1)
				hash[temp + n] = i;
			else
				if(max < (i - hash[temp + n]) )
					max = (i - hash[temp + n]);
		}



		System.out.println(max);
		return 1;
	}

	public static void main(String[] args)
	{
		VIJOS1195 VIJOS = new VIJOS1195();
		VIJOS.work();
		return ;
	}
}

