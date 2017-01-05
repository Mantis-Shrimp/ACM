//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-10-20
// Description : enumeration
//============================================================================

import java.util.Scanner;

public class VIJOS1116
{
	
	public static final double BORDER = 0.001;

	public double a,b,c,d;

	public int work()
	{
		double f1,f2;
		double m,n;
		for(double i = -100 ; i <= 100 ; i+=BORDER)
		{
			m = i;
			n = i + BORDER;
			
			f1 = a*m*m*m + b*m*m + c*m + d;
			f2 = a*n*n*n + b*n*n + c*n + d;
			if (f1*f2 <= 0) 
				System.out.print(String.format("%.2f ", i));
		}
		return 1;
	}
	
	public static void main(String[] args)
	{
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext())
		{
			VIJOS1116 VIJOS = new VIJOS1116();
			
			VIJOS.a = cin.nextDouble();
			VIJOS.b = cin.nextDouble();
			VIJOS.c = cin.nextDouble();
			VIJOS.d = cin.nextDouble();
			
			VIJOS.work();
		}
	}
}