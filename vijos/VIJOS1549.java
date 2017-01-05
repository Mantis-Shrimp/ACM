//============================================================================
// Name        : Vijos1549
// Author      :
// Version     :
// Copyright   : 2013-10-29
// Description : data structure  hashmap 
//============================================================================

import java.util.Scanner;
import java.util.Arrays;
import java.io.BufferedInputStream;

public class VIJOS1549
{
	

	public int work()
	{
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		int n = cin.nextInt(),b = cin.nextInt();
		int flag[] = new int[2*n];
		int queue[] = new int[n];
		int ret = 1,sum = 0,idx = 0 ;;

		for(int i = 0 ; i < n ; i++)
		{
			queue[i] = cin.nextInt();
			if(queue[i] == b) idx = i;
		}
		
		// record the quantitative relation between the number greater than b and the number less than b
		
		sum = 0;
		for(int i = idx + 1 ; i < n ; i++)
		{
			if(queue[i] > b) sum ++ ;
			else sum -- ;

			if(sum == 0) ret ++ ; //

			flag[n + sum] ++ ;
		}

		sum = 0;
		for(int i = idx - 1 ; i >= 0 ; i--)
		{
			if(queue[i] > b) sum ++ ;
			else sum -- ;

			if(sum == 0) ret ++ ; //

			ret+=( flag[n + (-sum)] );
		}

		System.out.println(ret);
		return 1;
	}

	public static void main(String[] args)
	{
		VIJOS1549 VIJOS = new VIJOS1549();
		VIJOS.work();
		return ;
	}
}