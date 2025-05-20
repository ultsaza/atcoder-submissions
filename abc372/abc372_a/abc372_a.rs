use proconio::input;

fn main() {
    input! {
        mut s: String,
    }
    s.retain(|x| x!='.');
    println!("{}", s);
}