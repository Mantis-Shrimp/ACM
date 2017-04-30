

fn main()
{
    let (mut T,mut N,mut K)   = (0u64,0u64,0u64);
    let mut input =  String::new();

    std::io::stdin().read_line(&mut input).unwrap();
    T = input.trim().parse().unwrap();

    for _ in 0..T
    {
        input.clear();
        std::io::stdin().read_line(&mut input).unwrap();
        let tmp:Vec<_> =  input.split_whitespace().map(|x| x.parse::<u64>().unwrap()).collect();
        N = tmp[0];
        K = tmp[1];


        let mut ret = 0;
        for i in 0..N+1
        {
            for j in i+1..N+1
            {
                if i & j < K
                {
                    if i & j > ret
                    {
                        ret = i & j;
                    }
                }
            }
        }

        println!("{}",ret);
    }
}


