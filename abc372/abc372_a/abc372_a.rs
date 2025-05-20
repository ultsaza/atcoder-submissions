use proconio::input;
use proconio::marker::Chars;
fn main() {
    input! {
        s: Chars,
    }
    println!("{}", s.iter().filter(|&&s| s != '.').collect::<String>());
}