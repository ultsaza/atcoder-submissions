use proconio::input;


fn main() {
    input! {
        mut k: usize,
    }
    let mut ans = String::new();
    while k > 0 {
        ans = (2 * (k % 2)).to_string() + &ans;
        k /= 2;
    }
    println!("{}", ans);
}