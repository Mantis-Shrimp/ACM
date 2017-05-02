

fn main()
{
    let mut input = String::new();
    let (mut T,mut N) = (0,0);
    let mut dp :  [i64;10000] = [2000;10000];


    dp[0]   =   0;
    dp[1]   =   1;


    for i in 0..10000
    {
        if(i + 1 < 10000)
        {
            let tmp = dp[i] + 1;

            if tmp < dp[i+1]
            {
                dp[i+1] = tmp;
            }
        }

        if(i + 2 < 10000)
        {
            let tmp = dp[i] + 1;

            if tmp < dp[i+2]
            {
                dp[i+2] = tmp;
            }
        }

        if(i + 5 < 10000)
        {
            let tmp = dp[i] + 1;

            if tmp < dp[i+5]
            {
                dp[i+5] = tmp;
            }
        }
    }

    //for i in 0..100
    //{
    //    println!("{} ",dp[i]);
    //}

    std::io::stdin().read_line(&mut input).unwrap();
    T = input.trim().parse().unwrap();
//    println!("{}",T);

    for _  in 0..T
    {
        input.clear();
        std::io::stdin().read_line(&mut input).unwrap();
        //println!("{}",input);
        N = input.trim().parse().unwrap();
        //println!("{}",N);

        input.clear();
        std::io::stdin().read_line(&mut input).unwrap();
        let chocolates : Vec<i64>  = input.split_whitespace().map(|x| x.parse().unwrap()).collect();


        //println!("{:?}",chocolates);

        let mut  min = 100000000;
        let mut  ret = 100000000;


        for i in 0..N
        {
            if  min > chocolates[i]
            {
                min = chocolates[i];
            }
        }

        //  intln!("{} {}",min,N);
        for k in 0..6
        {
            let mut  tmp = 0;
            for i in 0..N
            {
                tmp = tmp + dp[ (chocolates[i] - min+k) as usize];
            //println!("{} = {} {}",i,ret,chocolates[i]-min);
            }
            ret =  if tmp < ret {tmp} else {ret};
        }

        println!("{}",ret);
    }
}
