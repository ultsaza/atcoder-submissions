use proconio::{input, marker::Usize1};

fn main() {
    input! {
        n: usize,
        x: [i64; n],
        uvw: [(Usize1, Usize1, i64); n-1],
    }
    let mut g = vec![vec![]; n];
    let mut cost = vec![0; n];
    for (u, v, w) in uvw {
        g[u].push((v, w));
        g[v].push((u, w));
    }
    dfs(&g, &x, 0, 0, &mut cost);
    println!("{}", cost.iter().sum::<i64>());
}

fn dfs(g: &Vec<Vec<(usize, i64)>>, x: &Vec<i64>, v: usize, p: usize, cost: &mut Vec<i64>) -> i64 {
    let mut res = x[v];
    for (u, w) in &g[v] {
        if *u == p {
            continue;
        }
        let c = dfs(g, x, *u, v, cost);
        res += c;
        cost[v] += w * c.abs();
    }
    res
}
