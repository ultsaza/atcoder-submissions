use proconio::{input, marker::Usize1};

fn main() {
    input! {
        n: usize,
        m: usize,
        xy: [(Usize1, Usize1); m],
    }
    let mut g = vec![vec![];n];
    for (x, y) in xy {
        g[x].push(y);
    }
    let mut dp = vec![-1;n];
    for i in 0..n {
        dfs(&g, &mut dp, i);
    }
    let ans = dp.iter().max().unwrap();
    println!("{}", ans);
}

fn dfs(g: &Vec<Vec<usize>>, dp: &mut Vec<i32>, u: usize) -> i32{
    if dp[u] >= 0 {
        return dp[u];
    }
    dp[u] = 0;
    for v in g[u].iter() {
        dp[u] = dp[u].max(dfs(g, dp, *v) + 1);
    }
    dp[u]
}
