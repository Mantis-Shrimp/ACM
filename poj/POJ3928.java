//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-3-30
// Description : 树状数组
//============================================================================

import java.util.Scanner;


public class Main
{
	
	private static final int N = 100010;
	private int T,n;
	private long ret;
	private int [] rank,rev;
	private int [] S;
	private int lb[],ls[],rb[],rs[];
	public static void main(String[] args)
	{
		Main myApp = new Main();
		myApp.run();
	}

	private int run()
	{
		Scanner cin = new Scanner(System.in);
		T = cin.nextInt();
		while((T--)!=0)
		{
			ret = 0;
			n = cin.nextInt();
			rank = new int[N];
			rev = new int[N];
			lb = new int[N];
			ls = new int[N];
			rb = new int[N];
			rs = new int[N];


			for (int i = 1 ; i <= n ; i++ )
				rank[i] = cin.nextInt();

			init();
			for (int i = 1; i <= n; ++i) 
			{

				add(rank[i],1);
				ls[i] = getSum(rank[i]-1);
				lb[i] = getSum(N-1) - getSum(rank[i]);
				
			}
			init();
			for (int i = n; i >= 1; --i) 
			{
				add(rank[i],1);
				rs[i] = getSum(rank[i]-1);
				rb[i] = getSum(N-1) - getSum(rank[i]);
			}

			for (int i = 1; i <= n ; ++i) 
			{

				ret +=((lb[i]*rs[i])+(ls[i]*rb[i]));
			}

			System.out.println(ret);
		}
		return 0;
	}

	private int init()
	{
		S = new int[N];
		return 0;
	}

	private int add(int idx,int val)
	{
		while(idx<N)
		{
			S[idx] += val;
			idx+=(idx&(-idx));
		}
		return 0;
	}

	private int getSum(int idx)
	{
		int Sum = 0;
		while(idx >=1)
		{
			Sum += S[idx];
			idx-=(idx&(-idx));
		}
		return Sum;
	}

} 