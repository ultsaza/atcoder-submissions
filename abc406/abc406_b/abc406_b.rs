use proconio::input;

fn main() {
    input! {
        n: usize,
        k: usize,
    }
    let mut ans: u64 = 1;
    let b: u64 = 10_u64.pow(k as u32);

    for _i in 0..n {
        input! {
            a: u64,
        }
        if ans.saturating_mul(a) >= b {
            ans = 1;
        } else {
            ans *= a;
        }
    }
    println!("{}", ans);
    
}