

fn main()
{
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n =  input.trim().parse::<u64>().unwrap();



    let mut ret = 0;
    let mut tmp_ret = 0;
    let mut tmp_n = n;


    while tmp_n > 0
    {
        if tmp_n % 2 == 1
        {
            tmp_ret += 1;
        }
        else
        {
            tmp_ret = 0;
        }

        if ret < tmp_ret
        {
            ret = tmp_ret;
        }

        tmp_n /= 2;
    }


    println!("{}",ret);
}





