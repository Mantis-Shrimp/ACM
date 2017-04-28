use std::collections::HashMap;
use std::io::Read;



fn main()
{
    let mut  phone_book = HashMap::new();

    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n = input.trim().parse::<i32>().unwrap();

    for _ in 0..n
    {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        let input : Vec<&str> = input.split_whitespace().collect();
        phone_book.insert(input[0].to_string(),input[1].to_string());
    }

    let mut input = String::new();
    std::io::stdin().read_to_string(&mut input).unwrap();
    let input:Vec<&str> = input.split_whitespace().collect();


    for i in 0..input.len()
    {
        match phone_book.get(input[i])
        {
            Some(number)=>
            {
                println!("{}={}",input[i],number);
            }
            None =>
            {
                println!("Not found");
            }
        }
    }

}

