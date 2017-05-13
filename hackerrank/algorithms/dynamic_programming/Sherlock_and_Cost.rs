
fn main()
{
    let  mut  input     = String::new();

    input.clear();
    std::io::stdin().read_line(& mut input).unwrap();
    let T = input.trim().parse::<i64>().unwrap();

    for _ in 0..T
    {
        input.clear();
        std::io::stdin().read_line(& mut input).unwrap();
        let N = input.trim().parse::<i64>().unwrap();

        input.clear();
        std::io::stdin().read_line(& mut input).unwrap();
        let B : Vec<i64> = input.trim().split_whitespace().map(|x| x.parse().unwrap()).collect();

        let mut dp = [[0i64;2];100005];

        dp[0][0] = 0;
        dp[0][1] = 0;


        for i in 1..N as usize
        {
            // 取1时
            dp[i][0] = if dp[i-1][0] > dp[i-1][1] +  B[i-1] - 1  {  dp[i-1][0]    } else {  dp[i-1][1] +  B[i-1] - 1 };
            //取B时
            dp[i][1] = if dp[i-1][0]  + B[i] - 1 >  dp[i-1][1] +  i64::abs( B[i-1] - B[i] ) { dp[i-1][0]  + B[i] - 1 } else { dp[i-1][1] + i64::abs( B[i-1] - B[i]) };
        }


        if  dp[(N-1) as usize ][0]  >  dp[(N-1) as usize ][1]
        {
            println!("{}",dp[(N-1) as usize][0]);
        }
        else
        {
            println!("{}",dp[(N-1) as usize][1]);
        }
    }
}













