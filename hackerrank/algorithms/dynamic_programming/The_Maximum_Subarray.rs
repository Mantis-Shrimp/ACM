
use std::i32;

fn main()
{
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n         = input.trim().parse::<usize>().unwrap();


    for t in 0..n
    {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();

        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        let mut arr:Vec<i32> = input.trim().split_whitespace().map(|x| x.parse().unwrap()).collect();
        let mut dp:Vec<i32>  = vec![0;arr.len() +5];



        let mut ret2 = 0;
        for x in &arr
        {
            if *x > 0
            {
                ret2 = ret2 + *x;
            }
        }

        if ret2 == 0
        {

            ret2 = i32::min_value();

            for x in &arr
            {
                ret2 = if ret2 < *x  {*x} else {ret2};
            }
        }


        dp[0]  =  arr[0];
        for i in 1..arr.len()
        {
            if dp[i-1] > 0
            {
                dp[i] = dp[i-1] + arr[i];
            }
            else
            {
                dp[i] = arr[i];
            }
        }



        let mut ret1 = i32::min_value();

        for i in 0..arr.len()
        {
            if dp[i] > ret1
            {
                ret1 = dp[i];
            }

        }

        println!("{} {}",ret1,ret2);
    }
}






