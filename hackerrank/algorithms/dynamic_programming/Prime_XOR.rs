use std::io;

fn main()
{

    const MAX_N : usize = 100000 + 5; 
    const MAX_DP: usize = 10000;
    const MOD:usize     = 1000000000 + 7;
    const AI_MIN:usize  = 3500;
    const AI_MAX:usize  = 4500;

    let mut q = 0usize;
    let mut n = 0usize;
    //let mut ai = [0usize;MAX_N];
    let mut dp = [[0usize;MAX_DP];2];
    let mut is_prime = [true;MAX_DP];
    is_prime[0] = false;
    is_prime[1] = false;
    let mut ai_unique = [0;AI_MAX+1];

    let mut input:String = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    q = input.trim().parse().unwrap();



    for i in 2..MAX_DP
    {
        let mut j = 2;
        while j * i < MAX_DP
        {
            is_prime[j*i] = false;
            j = j + 1;
        }
    }



    for _ in 0..q
    {
        let mut input:String = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        n = input.trim().parse().unwrap();

        let mut input:String = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        let ai:Vec<_> = input.trim().split_whitespace().map(|x| x.parse::<usize>().unwrap()).collect();

        for i in 0..AI_MAX+1
        {
            ai_unique[i] = 0;
        }


        for i in 0..MAX_DP
        {
            dp[0][i] = 0;
            dp[1][i] = 0;
        }

        dp[0][0] = 1;

        let mut a_index = 0;
        for i in 1..n+1
        {

            let a_number = ai_unique[i];
            let a_value  = i;
            if a_number == 0
            {
                continue;
            }

            a_index += 1;
            //
            for j in 0..MAX_DP
            {
                dp[a_index & 1][j] = dp[ (a_index -1) & 1 ][j];
            }

            let mut a = 0;
            for k in 0..a_number
            {
                a = a & i;

                for j in 0..MAX_DP
                {
                    let tmp = dp[ (a_index-1) &1][j];
                    if  tmp != 0
                    {
                        dp[a_index & 1][j^a] += tmp;
                        if dp[a_index & 1][j^a] > MOD
                        {
                            dp[a_index&1][j^a] = dp[a_index&1][j^a] - MOD;
                        }
                    }
                }
            }

        }


        let mut ret = 0;

        for i in 0..MAX_DP
        {
            if is_prime[i]
            {
                ret = ret + dp[a_index&1][i];
                if ret > MOD
                {
                    ret = ret - MOD;
                }
            }
        }

        println!("{}",ret);
    }
}


