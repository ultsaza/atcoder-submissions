use argio::proconio::input;
use itertools::Itertools;

fn main() {
    input! {
        n: usize,
        a: [usize; n]
    }
    let t: Vec<_> = a
        .iter()
        .enumerate()
        .map(|(i, &x)| (i + 1, x))
        .sorted_by_key(|x| x.1)
        .collect();
    println!("{} {} {}", t[0].0, t[1].0, t[2].0);
}
