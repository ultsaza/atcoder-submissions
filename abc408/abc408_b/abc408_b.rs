use proconio::input;

fn main() {
    input! {
        n: usize,
        mut a: [usize; n],
    }
    a.sort();
    a.dedup();
    println!("{}", a.len());
    a.iter().for_each(|x| print!("{} ", x));
}