use std::cmp::Ordering;
use std::fmt::Debug;
use std::clone::Clone;

#[derive(Eq,Debug,Clone)]
struct  Stock
{
    p    :   usize,
    idx  :   usize,
}

impl Ord for Stock
{
    fn cmp(&self, other: &Stock) -> Ordering
    {
        other.p.cmp(&self.p)
    }
}

impl PartialOrd for Stock
{
    fn partial_cmp(&self, other: &Stock) -> Option<Ordering>
    {
        Some(self.cmp(other))
    }
}

impl PartialEq for Stock
{
    fn eq(&self, other: &Stock) -> bool
    {
        self.p == other.p
    }
}

fn main()
{

    let mut input =  String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut t = input.trim().parse::<usize>().unwrap();


    for i in 0..t
    {

        let mut input =  String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        let mut n = input.trim().parse::<i32>().unwrap();

        let mut idx   = 0;
        let mut input =  String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        let mut s : Vec<_> = input.trim().split_whitespace().map(|x| {idx = idx + 1; Stock{ p: x.parse::<usize>().unwrap(), idx : idx}  }).collect();

        let mut stock = s.clone();
        s.sort();

      //  println!("{:?}",s);

        let mut istart = 0;
        let mut ret = 0usize;

        for j in 0..s.len()
        {
            let mut iend = s[j].idx - 1;
            let mut value = s[j].p;


            //println!("{} {}",istart,iend);
            for k in istart..iend
            {
                ret = ret + (value - stock[k].p);
            }
            if istart <= iend
            {
                istart = iend + 1;
            }
        }

        println!("{}",ret);


    }
}
