



fn main()
{
    const    max:usize  = 1005;
    let mut  dp:Vec<Vec<usize>>   = Vec::new();

    for i in 0..max
    {
        dp.push(Vec::new());
        for j in 0..max
        {
            dp[i].push(0);
        }
    }




    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();

    let n:usize   = input.trim().parse().unwrap();


    for t  in 0..n
    {
        for i in 0..max
        {
            for j in 0..max
            {
                dp[i][j] = 0;
            }
        }

        let mut input1 = String::new();
        let mut input2 = String::new();

        std::io::stdin().read_line(&mut input1).unwrap();
        std::io::stdin().read_line(&mut input2).unwrap();

        let str1 = input1.trim().as_bytes();
        let str2 = input2.trim().as_bytes();


        dp[0][0] = 1;

        for i in 0..str1.len()
        {
            if str1[i] >= 65&&str1[i] <= 90
            {
                dp[i+1][0] = 0;
            }
            else
            {
                dp[i+1][0] = dp[i][0];
            }

        }

        for i in 0..str1.len()
        {
            for j in 0..str2.len()
            {
                if str1[i] >= 65 && str1[i] <= 90
                {
                    if str1[i] == str2[j]
                    {
                        dp[i+1][j+1] = dp[i][j];
                    }
                    else
                    {
                        dp[i+1][j+1] = 0;
                    }
                }
                else
                {

                    if str1[i] - 32  == str2[j]
                    {

                        if dp[i][j] == 1
                        {
                            dp[i+1][j+1] = dp[i][j];
                        }

                        if dp[i][j+1] == 1
                        {
                            dp[i+1][j+1] = dp[i][j+1];                            ;
                        }

                    }
                    else
                    {
                        dp[i+1][j+1] = dp[i][j+1];
                    }
                }
            }
        }


        //println!("{:?}",dp);
        if dp[str1.len()][str2.len()] == 1
        {
            println!("YES");
        }
        else
        {
            println!("NO");
        }
    }
}





