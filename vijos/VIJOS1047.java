//============================================================================
// Name        : Vijos1047
// Author      :
// Version     :
// Copyright   : 2013-10-26
// Description : number theory 
//============================================================================

import java.util.Scanner;
import java.math.BigInteger;
import java.io.BufferedInputStream;


public class VIJOS1047
{
	
	public VIJOS1047(){return;}

	public int work()
	{
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		BigInteger a = cin.nextBigInteger();
		BigInteger b = cin.nextBigInteger();	
		BigInteger c = a.multiply(b);
		System.out.println(c.divide(a.gcd(b)));

		return 1;
	}

	public static void main(String[] args)
	{
		VIJOS1047 VIJOS = new VIJOS1047();
		VIJOS.work();
		return ;
	}
}

