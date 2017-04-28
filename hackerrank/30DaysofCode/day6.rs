


fn main()
{
    let mut  input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    //println!("{}",input);
    let n = input.trim().parse::<i32>().unwrap();


    for _ in 0..n
    {
        let mut  input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        let input =  input.trim();
        let mut i = 0;
        for c in input.chars()
        {
            if i % 2 == 0
            {
                print!("{}",c);
            }
            i += 1;
        }

        print!(" ");

        let mut i = 0;
        for c in input.chars()
        {
            if i % 2 == 1
            {
                print!("{}",c);
            }
            i += 1;
        }

        println!("");
    }
}
