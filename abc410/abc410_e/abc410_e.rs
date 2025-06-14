use proconio::input;

fn main() {
    input! {
        n: usize,
        h: i64,
        m: usize,
        ab: [(i64, i64); n],
    }
    let mut dp: Vec<Vec<i64>> = vec![vec![ -1; m + 1]; n + 1];
    dp[0][m] = h;
    for i in 0..n {
        for j in 0..=m {
            let mut tmp = dp[i][j] - ab[i].0;
            if j as i64 + ab[i].1 <= m as i64 {
                tmp = tmp.max(dp[i][(j as i64 + ab[i].1) as usize]);
            }
            dp[i+1][j] = tmp;
        }
    }
    for i in (0..=n).rev() {
        for j in 0..=m {
            if dp[i][j] >= 0 {
                println!("{}", i);
                return;
            }
        }
    }
}