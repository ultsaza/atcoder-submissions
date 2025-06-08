use proconio::{input, marker::Chars};

fn main() {
    input! {
        n: usize,
        t: Chars,
        a: Chars,
    }
    for i in 0..n {
        if t[i] == a[i] && t[i] == 'o' {
            println!("Yes");
            return;
        }
    }
    println!("No");

}