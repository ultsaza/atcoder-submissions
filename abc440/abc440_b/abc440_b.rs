use argio::proconio::input;
use itertools::Itertools;

fn main() {
    input! {
        n: usize,
        t: [usize; n]
    }
    println!(
        "{}",
        t.iter().enumerate()
        .sorted_by_key(|x| x.1)
        .take(3)
        .map(|x| x.0 + 1)
        .join(" ")
    )
}
