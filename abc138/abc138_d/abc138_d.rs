use proconio::{input, marker::Usize1};

fn main() {
    input! {
        n: usize,
        q: usize,
        ab: [(Usize1, Usize1); n-1],
        px: [(Usize1, usize); q],
    }
    let mut x = vec![0; n];
    for (p, _x) in px {
        x[p] += _x;
    }
    let mut g = vec![vec![]; n];
    for (a, b) in ab {
        g[a].push(b);
        g[b].push(a);
    }
    let mut ans = vec![0; n];
    dfs(0, n, &g, &x, &mut ans);
    for a in ans {
        println!("{}", a);
    }
}

fn dfs(v: usize, p: usize, g: &Vec<Vec<usize>>, x: &Vec<usize>, ans: &mut Vec<usize>) {
    ans[v] += x[v];
    for &u in g[v].iter() {
        if u == p {
            continue;
        }
        ans[u] = ans[v];
        dfs(u, v, g, x, ans);
    }
}