
fn main()
{
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();

    let n:i32 = input.parse().unwrap();

    if n % 2 == 1
    {
        println!("Weird\n");
    }
    else
    {
        if n >= 2 && n <= 5
        {
            println!("Not Weird\n");
        }

        if n >= 6 && n <= 20
        {
            println!("Weird\n");
        }

        if n > 20
        {
            println!("Not Weird\n");
        }
    }
}
