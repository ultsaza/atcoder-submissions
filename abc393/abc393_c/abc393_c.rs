use std::collections::HashSet;

use proconio::input;

fn main() {
    input! {
        n: usize,
        m: usize,
        uv: [(usize, usize); m],
    }
    let mut set: HashSet<(usize, usize)> = HashSet::new();
    let mut ans = 0;
    
    uv.iter().for_each(|&(u, v)| {
        if set.contains(&(u, v)) || u == v {
            ans += 1;
        } else {
            set.insert((u, v));
            set.insert((v, u));
        }
    });
    println!("{}", ans);
}