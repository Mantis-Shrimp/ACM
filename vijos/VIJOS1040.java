//============================================================================
// Name        : Vijos1040
// Author      :
// Version     :
// Copyright   : 2013-10-26
// Description : bigInteger 
//============================================================================

import java.util.Scanner;
import java.math.BigInteger;
import java.io.BufferedInputStream;


public class Main
{
	
	public Main(){return;}

	public int work()
	{
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		BigInteger a = cin.nextBigInteger();
		BigInteger b = cin.nextBigInteger();
		BigInteger c = null;
		c = a.multiply(b) ;
		System.out.println(c);
		return 1;
	}

	public static void main(String[] args)
	{
		Main VIJOS = new Main();
		VIJOS.work();
		return ;
	}
}

