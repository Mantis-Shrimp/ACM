fn main()
{
    let  mut  input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();

    //println!("{}",input);

    let n = input.parse::<i32>().unwrap();

    for i in 1..11
    {
        println!("{} x {} = {}",n,i,n*i);
    }

    return;
}
