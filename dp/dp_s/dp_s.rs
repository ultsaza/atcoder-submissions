use proconio::{input, marker::Bytes};
use ac_library::ModInt1000000007 as Mint;
fn main() {
    input! {
        k: Bytes,
        d: usize,
    }
    let n = k.len();
    let mut dp  = vec![vec![vec![Mint::new(0);d];2];n+1];
    dp[0][0][0] = Mint::new(1);
    // kの先頭から見ていく.
    for i in 0..n {
        let now = k[i] as usize - b'0' as usize;
        for j in 0..d {
            for l in 0..10  {
                let cur = dp[i][1][j];
                dp[i+1][1][(j + l)%d] += cur;
            }
            for l in 0..now {
                let cur = dp[i][0][j];
                dp[i+1][1][(j + l)%d] += cur;
            }
            let cur = dp[i][0][j];
            dp[i+1][0][(j+now)%d] += cur;
        }
    }
    let ans = dp[n][0][0] + dp[n][1][0] - 1;
    println!("{}", ans.val());
}