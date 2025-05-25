use proconio::input;

fn main() {
    input! {
        mut n: usize,
    }
    if n == 1 {
        println!("1");
        println!("1");
        return;
    } else {
        println!("{}", n/2);
        for i in 1..=n/2 {
            print!("{} ", i * 2);
        }
    }
}