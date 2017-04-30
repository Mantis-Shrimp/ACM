use std::io::Read;
//use std::collections::HashMap;
use std::char;

fn main()
{
    let mut values   =      Vec::new();

    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.clear();
    std::io::stdin().read_to_string(&mut input).unwrap();

    for l in input.lines()
    {
        let tmp: Vec<&str> =  l.trim().split( |c|  !char::is_alphabetic(c) ).collect::<Vec<&str>>();

        let len = tmp.len();
        if tmp[len-2] == "gmail" && tmp[len-1] == "com"
        {
            values.push (tmp[0].to_string());
        }
    }
    values.sort();
    for v in values
    {
        println!("{}",v);
    }
}


