use proconio::{input, marker::Usize1};

fn main() {
    input! {
        n: usize,
        uv: [(Usize1, Usize1); n-1],
    }
    let mut g  = vec![vec![]; n];
    for (u, v) in uv {
        g[u].push(v);
        g[v].push(u);
    }
    let mut dp = vec![0; n];
    let mut ans = 0;
    dfs(&g, 0, &mut dp, -1);
    for v in g[0].iter() {
        ans += dp[*v];
    }
    ans -= g[0].iter().map(|&v| dp[v]).max().unwrap();
    println!("{}", ans+1);
}

fn dfs(g: &Vec<Vec<usize>>, u: usize, dp: &mut Vec<usize>, p: isize) {
    dp[u] = 1;
    for v in g[u].iter() {
        if *v as isize == p {
            continue;
        }
        dfs(g, *v, dp, u as isize);
        dp[u] += dp[*v];
    }
}