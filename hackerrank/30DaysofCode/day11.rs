use std::io::Read;


fn main()
{
    let mut  input = String::new();
    std::io::stdin().read_to_string(&mut input).unwrap();


    //let tmp_input =  input.lines().collect::<Vec<&str>>();
    let mut ma:Vec<Vec<i64>> = Vec::new();

    for l in input.lines()
    {
        ma.push(Vec::new());
        for c in l.split_whitespace()
        {
            let len  =  ma.len();
            ma[len-1].push(c.parse().unwrap());
        }
    }

    //println!("{:?}",ma);


    let mut ret = -100000000;

    for j in 1..5
    {

        for i in 1..5
        {
            let sum =
                ma[j+1][i] + ma[j+1][i-1] + ma[j+1][i+1]+
                ma[j][i]+
                ma[j-1][i] + ma[j-1][i-1] + ma[j-1][i+1];

    //        println!("{}",sum);
            if  sum > ret
            {
                ret = sum;
            }
        }

    }

    println!("{}",ret);
}






