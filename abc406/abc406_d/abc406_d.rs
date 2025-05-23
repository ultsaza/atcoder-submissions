use proconio::{input};
use std::collections::HashSet;

fn main() {
    input! {
        h: usize,
        w: usize,
        n: usize,
        xy: [(usize, usize); n],
        q: usize,
        tu: [(usize, usize); q],
    }
    let mut x: Vec<HashSet<usize>> = vec![HashSet::new(); h+1];
    let mut y: Vec<HashSet<usize>> = vec![HashSet::new(); w+1];

    for (px, py) in xy {
        x[px].insert(py);
        y[py].insert(px);
    }

    for (t, u) in tu {
        match t {
            1 => {
                println!("{}", x[u].len());
                x[u].iter().for_each(|&py| {
                    y[py].remove(&(u));
                });
                x[u].clear();
            }
            2 => {
                println!("{}", y[u].len());
                y[u].iter().for_each(|&px| {
                    x[px].remove(&(u));
                });
                y[u].clear();
            }
            _ => unreachable!(),
        }
    }
}