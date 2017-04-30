



fn factorial(n:u64)->u64
{
    if n == 1
    {
        return 1;
    }
    else
    {
        return n * factorial(n-1);
    }
}




fn main()
{
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n =  input.trim().parse::<u64>().unwrap();

    println!("{}",factorial(n));
}





