use std::collections::BTreeSet;

use proconio::input;
use proconio::marker::Usize1;

fn main() {
    input! {
        n: usize,
        k: usize,
        p: [Usize1; n],
    }
    let mut q = vec![0; n];
    for i in 0..n {
        q[p[i]] = i;
    }
    let a = (0..n).collect::<Vec<_>>();
    let mut ans = 1e9 as usize;
    let mut s = BTreeSet::new();
    for i in 0..k-1 {
        s.insert(q[a[i]]);
    }
    for i in k-1..n {
        s.insert(q[a[i]]);
        ans = ans.min(s.iter().max().unwrap() - s.iter().min().unwrap());
        s.remove(&q[a[i + 1 - k]]);
    }
    println!("{}", ans);
}