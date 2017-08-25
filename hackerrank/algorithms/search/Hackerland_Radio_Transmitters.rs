fn main()
{

    const DP_MAX:usize = 100005;
    let mut n      =       0usize;
    let mut k      =       0usize;
    let mut dp     =       [0;DP_MAX];

    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut tmp:Vec<_> = input.trim().split_whitespace().map(|x| x.parse::<usize>().unwrap()).collect();
    n = tmp[0];
    k = tmp[1];

    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut xi:Vec<_> = input.trim().split_whitespace().map(|x| x.parse::<usize>().unwrap()).collect();

    for i in 0..xi.len()
    {
        dp[xi[i]] = 1;
    }

    let mut istart    =    0usize;
    let mut ret       =    0usize;

//    println!("{:?}",dp);

    while istart < DP_MAX
    {
        if dp[istart] == 1
        {
            let mut iend = istart + k;
            while dp[iend] != 1
            {
                iend = iend - 1;
            }
//            println!("{}",iend);
            ret = ret + 1;
            istart = iend + k;
        }
        istart = istart + 1;
    }

    println!("{}",ret);
}
