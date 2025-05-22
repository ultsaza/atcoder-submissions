use proconio::input;
use ac_library::fenwicktree;
use proconio::marker::Usize1;
use std::mem::swap;

fn main() {
    input! {
        n: usize,
        uv: [(Usize1, Usize1); n-1],
        q: usize,
    }
    let mut g = vec![vec![]; n];
    let mut edge: Vec<(usize, usize)> = vec![];
    for i in 0..n-1 {
        let (u, v) = uv[i];
        g[u].push(v);
        g[v].push(u);
        edge.push((u, v));
    }
    let mut _in = vec![0; n];
    let mut _out = vec![0; n];
    let mut idx = 0;
    dfs(&g, 0, 0, &mut _in, &mut _out, &mut idx);
    let mut fw = fenwicktree::FenwickTree::new(n, 0);
    for i in 0..n {
        fw.add(i, 1);
    }
    for _ in 0..q {
        input! {
            t: usize
        }
        match t {
            1 => {
                input! {
                    x: Usize1,
                    w: usize,
                }
                fw.add(_in[x], w);
            }
            2 => {
                input! {
                    y: Usize1,
                }
                let (mut u, mut v) = edge[y];
                if _in[u] < _in[v] {
                    swap(&mut u, &mut v);
                }
                let usum = fw.sum(_in[u].._out[u]);
                let vsum = fw.sum(0..n) - usum;
                println!("{}", usum.abs_diff(vsum));    
            }
            _ => {
                unreachable!();
            }
        }
    }

    
    
}

fn dfs(g: &Vec<Vec<usize>>, v: usize, p: usize, _in: &mut Vec<usize>, _out: &mut Vec<usize>, idx: &mut usize) {
    _in[v] = *idx;
    *idx += 1;
    for &u in &g[v] {
        if u == p {
            continue;
        }
        dfs(g, u, v, _in, _out, idx);
    }
    _out[v] = *idx;
}