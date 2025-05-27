use itertools::iproduct;
use proconio::input;

fn main() {
    input! {
        n: usize,
        k: usize,
        d: usize,
        mut a: [usize; n],
    }
    let mut dp: Vec<Vec<Vec<i64>>> = vec![vec![vec![i64::MIN;k+1];d];n+1];
    dp[0][0][0] = 0;
    for (i, j, l) in iproduct!(0..n, 0..d, 0..k) {
        dp[i+1][(j + a[i])%d][l+1] = dp[i][(j +a[i])%d][l+1].max(dp[i][j][l] + a[i] as i64);
        dp[i+1][j][l] = dp[i][j][l].max(dp[i+1][j][l]);
    }
    println!("{}", dp[n][0][k].max(-1));
}