use proconio::input;

fn main() {
    input! {
        a: isize,
        b: isize,
    }
    if (a as f64 / b as f64 - (a/b) as f64).abs() <  (a as f64 / b as f64 - (a/b + 1) as f64).abs() {
        println!("{}", a/b);
    } else {
        println!("{}", a/b + 1);
    }
}