//============================================================================
// Name        : Vijos1062
// Author      :
// Version     :
// Copyright   : 2013-10-29
// Description : data structure 
//============================================================================

import java.util.Scanner;
import java.util.Arrays;
import java.util.Stack;
import java.io.BufferedInputStream;

public class VIJOS1062
{
	public int work()
	{
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		Stack<Integer> S = new Stack<Integer>();
		int boy,girl,g0,n;
		int ret;
		n = cin.nextInt();
		boy = 1 ;

		for(int i = 1 ; i <= n ; i++)
		{
			girl = cin.nextInt();
			
			while(boy <= girl)
			{
				S.push(boy);
				boy ++ ;
			}

			ret = ((i +  girl) - (S.pop() + i - 1));

			System.out.print(ret+" ");
		}
		return 1;
	}

	public static void main(String[] args)
	{
		VIJOS1062 VIJOS = new VIJOS1062();
		VIJOS.work();
		return ;
	}
}

