#![allow(unused_imports)]
use itertools::*;
use itertools_num::*;
use maplit::*;
use memoise::memoise_map;
use num::integer::{Integer, Roots};
use proconio::{marker::*, *};
use std::cmp::{Ordering::*, Reverse};
use std::collections::*;
use superslice::*;

fn main() {
    input! {
        n: usize,
        m: usize,
        x: usize,
    }
    let mut g: Vec<Vec<(usize, usize)>> = vec![vec![]; 2 * n];
    for _ in 0..m {
        input! {
            u: usize,
            v: usize,
        }
        g[u-1].push((v-1,1));
        g[v-1 + n].push((u-1 + n,1));
    }
    for i in 0..n {
        g[i].push((i + n, x));
        g[i + n].push((i, x));
    }
    
    let inf = 1 << 60;
    let mut dist = vec![inf; 2 * n];
    let mut pq: BinaryHeap<Reverse<(usize, usize)>> = BinaryHeap::new();
    pq.push(Reverse((0, 0)));
    dist[0] = 0;
    while pq.len() > 0 {
        let Reverse((d, v)) = pq.pop().unwrap();
        if dist[v] < d {
            continue;
        }
        for &(to, c) in &g[v] {
            if dist[to] > dist[v] + c {
                dist[to] = dist[v] + c;
                pq.push(Reverse((dist[to], to)));
            }
        }
    }
    let ans = dist[n-1].min(dist[ 2*n-1]);
    println!("{}", ans);
}