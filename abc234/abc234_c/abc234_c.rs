use proconio::input;


fn main() {
    input! {
        mut k: usize,
    }
    let mut ans = String::new();
    while k > 0 {
        ans = format!("{}", 2 * (k % 2)) + &ans;
        k /= 2;
    }
    println!("{}", ans);
}