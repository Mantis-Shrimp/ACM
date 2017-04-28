




fn main()
{
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();

    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let output= input.split_whitespace().collect::<Vec<&str>>();

    for i in   (0..output.len()).rev()
    {
        print!("{}",(output[i]).parse::<i32>().unwrap());
        if i != 0
        {
            print!(" ");
        }
    }
}




