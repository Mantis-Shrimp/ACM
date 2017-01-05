//============================================================================
// Name        : Vijos1221
// Author      :
// Version     :
// Copyright   : 2013-10-30
// Description : data structure 
//============================================================================

import java.util.Scanner;
import java.util.Arrays;
import java.math.BigInteger;
import java.io.BufferedInputStream;

public class VIJOS1221
{
	

	public static final int N = 2;
	public int fa[] = new int[300];
	public int val[] = new int[300];
	
	int findroot(int x)
	{
    	int fx = fa[x];
    	if(fx == x)
    	{
        	return x;
    	}
    	else
    	{
        	fa[x] = findroot(fa[x]);
        	val[x] = (val[fx] + val[x]) % N;
        	return fa[x];
    	}
	}

	int Union_set(int x,int y,int c)  // add  y to x
	{
    	int fx = findroot(x);
    	int fy = findroot(y);
    	if(fx!=fy)
    	{
        	fa[fy] = fx;
        	val[fy] = (c + val[x] - val[y] + N) % N;
        	return 1;
    	}
    	else
    	{
        	return 0;
    	}
	}



	public int work()
	{
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		BigInteger ret = new BigInteger("1");
		int n , m ,a ,b ,c ,d;
		int fa,fc,va,vc,v,v0;

		n = cin.nextInt();
		m = cin.nextInt();
		
		for(int i = 1 ; i <= n ; i++)
		{
			this.fa[i] = i;
			val[i] = 0;
		}


		for(int i = 1 ; i <= m ; i++)
		{
			a = cin.nextInt();
			b = cin.nextInt();
			c = cin.nextInt();
			d = cin.nextInt();
			
			fa = findroot(a);
			fc = findroot(c);

			if(fa == fc)
			{
				v = (val[a] - val[c] + N) % N ;
				v0 = (b - d + N) % N;

				if(v != v0)
				{
					System.out.println("No Answer");
					return 1;
				} 
			}
			else
			{
				Union_set(a,c,Math.abs(d-b));
			}
		}

		for(int i = 1 ; i <= n ; i++)
		{
			if(this.fa[i] == i)
			{
				//System.out.println(i);
				ret = ret.multiply(new BigInteger("2"));
			}
		}

		System.out.println(ret.toString());

		return 1;
	}

	public static void main(String[] args)
	{
		VIJOS1221 VIJOS = new VIJOS1221();
		VIJOS.work();
		return ;
	}
}

