use itertools::Itertools;
use proconio::input;

fn main() {
    input! {
        n: usize,
        mut a: [usize; n]
    }
    let a = a.into_iter().enumerate().sorted_by_key(|&x| x.1).collect::<Vec<_>>();
    println!("{}", a[n-2].0 + 1);
}