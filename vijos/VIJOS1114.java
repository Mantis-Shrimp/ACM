//============================================================================
// Name        : Vijos1114
// Author      :
// Version     :
// Copyright   : 2013-10-29
// Description : data struction 
//============================================================================

import java.util.Scanner;
import java.util.Arrays;
import java.io.BufferedInputStream;

public class VIJOS1114
{
	
	public int work()
	{
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		cin.nextLine();
		String str = cin.nextLine();
		travel(0,str.length()-1,str);
		return 1;
	}

	public int travel(int start,int end,String str)
	{
		int mid = (start + end) / 2;
		int len = end - start + 1;
		int sum = 0;
		char type = 'F';


		for(int i = start ; i <= end ; i++)
			sum +=  (str.charAt(i) - '0');

		if(sum == 0) type = 'B';
		if(sum == len) type = 'I';
		if(sum > 0&& sum < len) type = 'F';

		// travel
		if(start == end)
		{
			System.out.print(type);
			return 0;
		}
		else
		{
			travel(start,mid,str);
			travel(mid+1,end,str);
			System.out.print(type);
			return 0;
		}
	}

	public static void main(String[] args)
	{
		VIJOS1114 VIJOS = new VIJOS1114();
		VIJOS.work();
		return ;
	}
}

