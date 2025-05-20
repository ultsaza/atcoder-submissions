use proconio::input;

fn main() {
    input! {
        n: usize,
        k: usize,
        a: [u64; n],
    }
    let ans = a.iter().fold(1_u64,|acc, &a| {
        if acc.saturating_mul(a) >= 10_u64.pow(k as u32) {
            1
        } else {
            acc.saturating_mul(a)
        }
    });
    println!("{}", ans);
}